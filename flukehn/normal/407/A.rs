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
    if y == 0 {x} else {gcd(y, x % y)}
}
fn main() {
    let content = stdin_to_string();
    let mut inp = Parser::new(&content);
    let a: i32 = inp.read();
    let b: i32 = inp.read();
    let mut i: i32 = 0;
    let mut j: i32 = 0;
    while (j + 1) * (j + 1) < a * a {j += 1;}
    while (i + 1) * (i + 1) < a * a{
        i += 1;
        while j > 1 && i * i + j * j > a * a {j -= 1;}
        if i * i + j * j != a * a {continue;}
        let g = gcd(i, j);
        let x = i / g;
        let y = j / g;
        if b * b % (x * x + y * y) != 0 {continue;}
        let w = b * b / (x * x + y * y);
        let p = (w as f64).sqrt().ceil() as i32;
        if p * p != w {continue;}
        let u = x * p;
        let v = y * p;
        //println!("YES\n{} {}\n{} {}\n{} {}", 0, 0, i, j, -v, u);
        if u == j {continue;}
        println!("YES\n{} {}\n{} {}\n{} {}", 0, 0, i, j, -v, u);
        return;
    }
    println!("NO");
}