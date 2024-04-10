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
//use std::iter::repeat;
//use std::cmp::max;
//const N: usize = 100011;
const EPS: f64 = 1e-9;

fn main() {
    let content = stdin_to_string();
    let mut inp = Parser::new(&content); // inp.read()
    let n: usize = inp.read();
    let vb: f64 = inp.read();
    let vs: f64 = inp.read();
    let mut x = vec![0; n+1];
    for i in 1..=n {
        x[i] = inp.read();
    }
    let mut ans: f64 = 1e18;
    let mut du: f64 = 1e18;
    let mut p: usize = 0;
    let xu: f64 = inp.read();
    let yu: f64 = inp.read();
    for i in 2..=n {
        let u =  ((xu - x[i] as f64) * (xu - x[i] as f64) + yu * yu).sqrt() / vs;
        let w = (x[i] as f64) / vb + u;
        if w < ans {
            ans = w;
            du = u;
            p = i;
        } else if (w - ans).abs() < EPS && du > u {
            du = u;
            p = i;
        }
    }
    println!("{}", p);
}