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
use std::cmp::*;
//const N: usize = 100011;
//const EPS: f64 = 1e-9;
//use std::f64::consts::PI;

fn work(x: i32, y: i32) -> i32 {
    let n = max(x.abs(), y.abs());
    return if n == 0 {
        0
    } else {
        4 * (n - 1) + 
        if x == n {
            if y == -n {
                4
            } else {
                (y >= 2 - n) as i32
            }
        } else if y == n {
            1 + (x < n) as i32
        } else if x == -n {
            2 + (y < n) as i32
        } else {
            3 + (x > -n) as i32
        }
    };
}
fn main() {
    let content = stdin_to_string();
    let mut inp = Parser::new(&content); // inp.read()
    let x: i32 = inp.read();
    let y: i32 = inp.read();
    println!("{}", work(x,y));
}