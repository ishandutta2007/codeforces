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
fn gcd(a: u32, b: u32) -> u32 {
    if b == 0 {
        return a;
    } else {
        return gcd(b, a % b);
    }
}
fn main() {
    let mut scanner = Scanner::new();
    for _ in 0..scanner.next() {
        let n = scanner.next();
        let mut a = Vec::<u32>::new();
        a.resize_with(n, ||scanner.next());
        let mut cd = 0;
        for ai in a {
            cd = gcd(cd, ai);
        }
        let mut ans = 3;
        if cd == 1 {
            ans = 0;
        }
        for i in 1..n + 1 {
            if gcd(cd, i as u32) == 1 {
                ans = ans.min(n - i + 1);
            }
        }
        println!("{}", ans);
    }
}