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
fn gcd(x: i32, y: i32) -> i32 {
    return if y == 0 {
        x
    } else {
        gcd(y, x % y)
    }
}

use std::collections::HashSet;

fn main() {
    let content = stdin_to_string();
    let mut inp = Parser::new(&content); // inp.read()
    let n: usize = inp.read();
    let x0: i32 = inp.read();
    let y0: i32 = inp.read();
    let mut s = HashSet::<i64>::new();
    for _ in 0..n {
        let x: i32 = inp.read();
        let y: i32 = inp.read();
        let mut x = x - x0;
        let mut y = y - y0;
        if x < 0 {
            x = -x;
            y = -y;
        }
        let g = gcd(x, y);
        x /= g;
        y /= g;
        s.insert(x as i64 * 1000000 + y as i64);
    }
    println!("{}", s.len());
}