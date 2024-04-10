use std::{
    vec::IntoIter,
    io::Read
};
struct Scanner {
    iter: IntoIter<String>,
}

impl Scanner {
    fn new() -> Scanner {
        let mut source = Vec::new();
        std::io::stdin().read_to_end(&mut source).unwrap();
        return Scanner {
            iter: source
                .split(|x| (*x as char).is_ascii_whitespace())
                .map(|x| String::from_utf8(x.to_vec()).unwrap())
                .filter(|x| !x.is_empty())
                .collect::<Vec<String>>()
                .into_iter(),
        };
    }
    fn next_string(&mut self) -> String {
        return self.iter.next().unwrap();
    }
    fn next<T: std::str::FromStr>(&mut self) -> T
    where
        <T as std::str::FromStr>::Err: std::fmt::Debug,
    {
        return self.next_string().parse::<T>().unwrap();
    }
}

fn main() {
    let mut scanner = Scanner::new();
    for _ in 0..scanner.next() {
        let n = scanner.next();
        let q = scanner.next();
        let mut a = Vec::<u64>::new();
        a.resize_with(n, ||scanner.next());
        a.insert(0, 0);
        let mut add = vec![0; n + 1];
        let mut xor = vec![0; n + 1];
        let mut next = vec![n + 1; n + 2];
        let mut prev = vec![0; n + 2];
        for i in 1..n + 1 {
            add[i] = add[i - 1] + a[i];
            xor[i] = xor[i - 1] ^ a[i];
            prev[i] = prev[i - 1];
            if a[i] > 0 {
                prev[i] = i;
            }
        }
        for i in (1..n + 1).rev() {
            next[i] = next[i + 1];
            if a[i] > 0 {
                next[i] = i;
            }
        }
        for _ in 0..q {
            let mut l = scanner.next::<usize>();
            let mut r = scanner.next::<usize>();
            if a[l] == 0 {
                l = next[l];
                if l > r {
                    println!("{} {}", r, r);
                    continue;
                }
            }
            if a[r] == 0 {
                r = prev[r];
            }
            let value = add[r] - add[l - 1] - (xor[r] ^ xor[l - 1]);
            let mut ls = Vec::new();
            let mut rs = Vec::new();
            let mut pl = l;
            let mut pr = r;
            while pl <= r && ls.len() <= 30 {
                ls.push(pl);
                pl = next[pl + 1];
            }
            while pr >= l && rs.len() <= 30 {
                rs.push(pr);
                pr = prev[pr - 1];
            }
            //println!("l = {}, r = {}, ls = {:?}, rs = {:?}", l, r, ls, rs);
            for cl in &ls {
                for cr in &rs {
                    if cl <= cr && add[*cr] - add[*cl - 1] - (xor[*cr] ^ xor[*cl - 1]) == value && *cr - *cl <= r - l {
                        l = *cl;
                        r = *cr;
                    }
                }
            }
            println!("{} {}", l, r);
        }
    }
}