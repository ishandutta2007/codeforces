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

fn work(a: i32, x: i32, y: i32) -> i32 {
    if y % a == 0 || x.abs() >= a {return -1;}
    let y = y / a;
    return if y == 0 {
        if 2 * x.abs() < a {
            1
        } else {
            -1
        }
    } else {
        if y % 2 == 0 {
            if x == 0 {
                -1
            } else {
                3 * y / 2 + (x > 0) as i32
            }
        } else {
            if 2 * x.abs() >= a {
                -1
            } else {
                3 * y / 2 + 1
            }
        }  
    };
}

fn main() {
    let content = stdin_to_string();
    let mut inp = Parser::new(&content); // inp.read()
    let a: i32 = inp.read();
    let x: i32 = inp.read();
    let y: i32 = inp.read();
    println!("{}", work(a, x, y));
}