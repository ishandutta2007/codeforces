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
    let mut map = BTreeMap::<u64, BTreeSet<u64>>::new();
    let mut rev = BTreeMap::<u64, Vec<u64>>::new();
    let q = scanner.next();
    let mut c = vec![' '; q];
    let mut x = vec![0u64; q];
    for i in 0..q {
        c[i] = scanner.next();
        x[i] = scanner.next();
        set.insert(x[i]);
    }
    for x in &set { 
        if *x > 0 {
            map.insert(*x, BTreeSet::<u64>::new());
            let map_set = map.get_mut(&x).unwrap();
            let mut mx = 0;
            while set.contains(&mx) {
                mx += x;
                map_set.insert(mx);
                if !rev.contains_key(&mx) {
                    rev.insert(mx, Vec::new());
                }
                rev.get_mut(&mx).unwrap().push(*x);
            }
        }
    }
    for i in 0..q {
        if c[i] == '+' {
            for rx in rev.get(&x[i]).unwrap() {
                map.get_mut(&rx).unwrap().remove(&x[i]);
            }
        } else if c[i] == '-' {
            for rx in rev.get(&x[i]).unwrap() {
                map.get_mut(&rx).unwrap().insert(x[i]);
            }
        } else {
            println!("{}", *map.get_mut(&x[i]).unwrap().iter().next().unwrap());
        }
    }
}