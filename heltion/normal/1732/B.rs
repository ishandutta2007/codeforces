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
        let s = scanner.next_string().chars().collect::<Vec<_>>();
        let mut ans = 0;
        for i in 1..n {
            if s[i] != s[i - 1] {
                ans += 1;
            }
        }
        if s[0] == '0' {
            println!("{}", 0.max(ans - 1));
        } else {
            println!("{}", ans);
        }
    }
}