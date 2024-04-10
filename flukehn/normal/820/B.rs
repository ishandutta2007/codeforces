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
use std::cmp::min;
//const N: usize = 100011;
//const EPS: f64 = 1e-9;
const PI: f64 = 3.14159265358979323846264338327950288f64;
fn dist(n: i32, i: i32, j: i32) -> f64 {
    let mut w = (i - j).abs();
    if 2 * w > n {
        w = n - w;
    }
    let r: f64 = w as f64 / n as f64 * 2.0 * PI;
    return (r / 2.0).sin() * 2.0;
}
fn angle(n: i32, i: i32, j: i32, k: i32) -> f64 {
    let a = dist(n, i, j);
    let b = dist(n, j, k);
    let c = dist(n, i, k);
    return ((a * a + b * b - c * c) / 2.0 / a / b).acos() / PI * 180.0;
}
fn main() {
    let content = stdin_to_string();
    let mut inp = Parser::new(&content); // inp.read()
    let n: i32 = inp.read();
    let a: f64 = inp.read();
    let mut x: i32 = 1;
    let mut y: i32 = 2;
    let mut ans: f64 = (a - angle(n, 1, 0, 2)).abs();
    let mut p: i32 = 1;
    for i in 3..n {
        let mut now = angle(n, p, 0, i);
        if (a - now).abs() < ans {
            ans = (a - now).abs();
            x = p;
            y = i;
        }
        while p + 1 < i {
            let nxt = angle(n, p + 1, 0, i);
            if (a - nxt).abs() < ans {
                ans = (a - nxt).abs();
                x = p + 1;
                y = i;
            }
            if nxt > a {
                now = nxt;
                p += 1;
            } else {
                break;
            }
        }
    }
    //println!("{}", ans);
    println!("{} {} {}", x + 1, 1, y + 1);
}