use std::{collections::HashMap, io::{BufWriter, stdin, stdout, Write}, cmp::{min, max}};

#[derive(Default)]
struct Scanner {
    buffer: Vec<String>
}
impl Scanner {
    fn next<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("Failed parse");
            }
            let mut input = String::new();
            stdin().read_line(&mut input).expect("Failed read");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }
}

struct DSU {
    par: Vec<(isize, bool)>,
    undo_stack: Vec<(isize, (isize, bool))>,
}

struct DSUCheckpoint (usize);

impl DSU {
    fn new(n: isize) -> DSU {
        DSU {
            par: vec![(-1, false); n as usize],
            undo_stack: Vec::new(),
        }
    }

    fn get_par(self: &DSU, mut a: isize) -> (isize, bool) {
        let mut cur_flip = false;
        while self.par[a as usize].0 >= 0 {
            cur_flip ^= self.par[a as usize].1;
            a = self.par[a as usize].0;
        }
        return (a, cur_flip);
    }
    
    fn add_edge(self: &mut DSU, a: isize, b: isize) -> bool {
        let (a, fa) = self.get_par(a);
        let (b, fb) = self.get_par(b);
        let flip = fa ^ fb ^ true;
        if a == b {
            return !flip;
        }

        let (a, b) = if self.par[a as usize].0 < self.par[b as usize].0 {
            (a, b)
        } else {
            (b, a)
        };

        self.undo_stack.push((a, self.par[a as usize]));
        self.undo_stack.push((b, self.par[b as usize]));

        self.par[a as usize].0 += self.par[b as usize].0;
        self.par[b as usize] = (a, flip);

        return true;
    }

    fn checkpoint(self: &DSU) -> DSUCheckpoint {
        DSUCheckpoint(self.undo_stack.len())
    }

    fn rollback(self: &mut DSU, check: DSUCheckpoint) {
        while self.undo_stack.len() > check.0 {
            let (i, v) = self.undo_stack.pop().unwrap();
            self.par[i as usize] = v;
        }
    }
}

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let n: isize = scan.next();
    let m: isize = scan.next();
    let k: isize = scan.next();

    let c: Vec<isize> = (0..n).map(|_| scan.next::<isize>()-1).collect();

    let edges: Vec<(isize, isize)> = (0..m).map(|_| (scan.next::<isize>()-1, scan.next::<isize>()-1)).collect();

    let mut dsu = DSU::new(n);
    let mut group_good = vec![true; k as usize];

    let mut group_edges: HashMap<(isize, isize), Vec<(isize, isize)>> = HashMap::new();

    for (a,b) in edges {
        let ca = c[a as usize];
        let cb = c[b as usize];
        if ca == cb {
            if !dsu.add_edge(a, b) {
                group_good[ca as usize] = false;
            }
        } else {
            group_edges.entry((min(ca, cb), max(ca, cb))).or_default().push((a,b));
        }
    }

    let good_groups: i32 = group_good.iter().map(|&a| if a { 1 } else { 0 }).sum();

    let mut ans = good_groups as i64 * (good_groups as i64 - 1) / 2;

    for (groups, cur_edges) in group_edges {
        if !group_good[groups.0 as usize] || !group_good[groups.1 as usize] {
            continue
        }

        let check = dsu.checkpoint();
        let mut is_good = true;
        for (a, b) in cur_edges {
            if !dsu.add_edge(a, b) {
                is_good = false;
                break;
            }
        }
        if !is_good {
            ans -= 1;
        }
        dsu.rollback(check);
    }
    writeln!(out, "{}", ans).unwrap();
}