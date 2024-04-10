use std::{
    vec::IntoIter,
    io::Read, collections::{BTreeSet, BTreeMap}
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
    let mut set = BTreeSet::<u64>::new();
    set.insert(0);
    let mut ans = BTreeMap::<u64, u64>::new();
    for _ in 0..scanner.next() {
        let c = scanner.next::<char>();
        if c == '+' {
            let x = scanner.next();
            set.insert(x);
        } else {
            let k = scanner.next();
            if !ans.contains_key(&k) {
                ans.insert(k, 0);
            }
            let ansk = ans.get_mut(&k).unwrap();
            while set.contains(ansk) {
                *ansk += k;
            }
            println!("{}", ansk)
        }
    }
}