mod cp {
    use std::io::prelude::*;
    pub fn stdin_to_string() -> String {
        let mut content = String::new();
        let stdin = std::io::stdin();
        let mut rd = stdin.lock();
        rd.read_to_string(&mut content).unwrap();
        return content;
    }
    
    pub struct Parser<'a> {
        tokens: std::str::SplitWhitespace<'a>,
    }
    
    impl<'a> Parser<'a> {
        pub fn new(text: &'a str) -> Self {
            Self {
                tokens: text.split_whitespace(),
            }
        }
    
        pub fn read_or_eof<T: std::str::FromStr>(&mut self) -> Option<T> {
            self.next().map(|s| match s.parse() {
                Ok(x) => x,
                Err(_) => panic!("cannot parse {:?}", s),
            })
        }
    
        pub fn read<T: std::str::FromStr>(&mut self) -> T {
            self.read_or_eof::<T>().expect("unexpected end-of-file")
        }
    }
    
    impl<'a> Iterator for Parser<'a> {
        type Item = &'a str;
        fn next(&mut self) -> Option<&'a str> {
            self.tokens.next()
        }
    }
    
    #[macro_export]
    macro_rules! take {
        ($p: expr, $n: expr) => {
            $p.by_ref().take($n).map(|x| x.parse().unwrap())
        };
        ($p: expr, $n: expr, $t: ty) => {
            $p.by_ref().take($n).map(|x| x.parse::<$t>().unwrap())
        };
    }
    
    #[macro_export]
    macro_rules! take_all {
        ($p: expr) => {
            $p.by_ref().map(|x| x.parse().unwrap())
        };
        ($p: expr, $t: ty) => {
            $p.by_ref().map(|x| x.parse::<$t>().unwrap())
        };
    }
}
    
use cp::*;
//use std::cmp::*;
//const N: usize = 100011;
//const EPS: f64 = 1e-9;
//use std::f64::consts::PI;


fn main() {
    let content = stdin_to_string();
    let mut inp = Parser::new(&content); // inp.read()
    let n: usize = inp.read();
    let mut u: i32 = inp.read();
    let mut uu: i32 = 0;
    let mut sum: i32 = 0;
    for _ in 1..n {
        let v: i32 = inp.read();
        sum += match (u, v) {
            (1, 2) => 3 - (uu == 3) as i32,
            (1, 3) => 4,
            (2, 1) => 3,
            (2, 3) => 114514,
            (3, 1) => 4,
            (3, 2) => 114514,
            _ => 0
        };
        uu = u;
        u = v;
    }
    if sum >= 114514 {
        println!("Infinite");
    } else {
        println!("Finite\n{}", sum);
    }
}