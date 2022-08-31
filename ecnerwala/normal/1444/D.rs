use std::io::{BufWriter, stdin, stdout, Write};

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

fn split_equal(lens: Vec<i32>) -> Option<[Vec<i32>; 2]> {
    let tot: i32 = lens.iter().sum();
    if tot % 2 != 0 {
        return None;
    }
    let target: i32 = tot / 2;
    let mut prv = vec![-1 as isize; (target+1) as usize];
    prv[0] = 0;
    for (i, &l) in lens.iter().enumerate() {
        for x in (0..=target-l).rev() {
            if prv[x as usize] == -1 {
                continue
            }
            if prv[(x+l) as usize] == -1 {
                prv[(x+l) as usize] = i as isize
            }
        }
    }
    if prv[target as usize] == -1 {
        return None
    }
    let mut cur = target;
    let mut cur_idx = lens.len() as isize;
    let mut resp = [Vec::new(), Vec::new()];
    while cur > 0 {
        let i = prv[cur as usize];
        while cur_idx > i {
            cur_idx -= 1;
            if cur_idx == i {
                resp[0].push(lens[cur_idx as usize]);
            } else {
                resp[1].push(lens[cur_idx as usize]);
            }
        }
        cur -= lens[i as usize];
    }
    while cur_idx > 0 {
        cur_idx -= 1;
        resp[1].push(lens[cur_idx as usize]);
    }
    if resp[0].len() > resp[1].len() {
        resp.reverse();
    }
    resp[0].sort_unstable();
    resp[1].sort_unstable();
    return Some(resp);
}

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let t: usize = scan.next();
    for _ in 0..t {
        let h: usize = scan.next();
        let lx: Vec<i32> = (0..h).map(|_| scan.next()).collect();
        let v: usize = scan.next();
        let ly: Vec<i32> = (0..v).map(|_| scan.next()).collect();

        let ans = move || -> Option<Vec<(i32, i32)>> {
            if h != v {
                return None;
            }

            // If the splits don't exist, return None
            let mut lx = split_equal(lx)?;
            let mut ly = split_equal(ly)?;

            lx[0].reverse();
            lx[1].reverse();
            lx[1].iter_mut().for_each(|v| *v = -*v );

            ly.reverse();
            ly[1].iter_mut().for_each(|v| *v = -*v );

            let lx = lx[0].iter().chain(lx[1].iter());
            let ly = ly[0].iter().chain(ly[1].iter());

            let mut polyline = Vec::with_capacity(h + v);
            let mut cur_x = 0;
            let mut cur_y = 0;

            for (dx, dy) in lx.zip(ly) {
                cur_x += dx;
                polyline.push((cur_x, cur_y));
                cur_y += dy;
                polyline.push((cur_x, cur_y));
            }

            return Some(polyline);
        }();

        match ans {
            Some(v) => {
                writeln!(out, "Yes").unwrap();
                v.iter().for_each(|(a,b)| writeln!(out, "{} {}", a, b).unwrap());
            }
            None => {
                writeln!(out, "No").unwrap();
            }
        }
    }

}