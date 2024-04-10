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

fn right(x: i32, y: i32, u: i32, v: i32, a: i32, b: i32) -> bool {
    if (u - x) * (b - y) == (v - y) * (a - x) {
        return false;
    }
    let p = (x - u) * (x - u) + (y - v) * (y - v);
    let q = (a - u) * (a - u) + (b - v) * (b - v);
    let r = (x - a) * (x - a) + (y - b) * (y - b);
    return max(p, max(q, r)) * 2 == p + q + r;
}
fn almost_right(x: i32, y: i32, u: i32, v: i32, a: i32, b: i32) -> bool {
    let mut ret = false;
    let mut dx = [-1i32, 1, 0, 0];
    let mut dy = [0i32, 0, -1, 1];
    for i in 0..4 {
        ret |= right(x+dx[i],y+dy[i],u,v,a,b)||right(x,y,u+dx[i],v+dy[i],a,b)||right(x,y,u,v,a+dx[i],b+dy[i]);
    }
    return ret;
}

fn main() {
    let content = stdin_to_string();
    let mut inp = Parser::new(&content);
    let mut x: i32 = inp.read();
    let mut y: i32 = inp.read();
    let mut u: i32 = inp.read();
    let mut v: i32 = inp.read();
    let mut a: i32 = inp.read();
    let mut b: i32 = inp.read();
    if right(x, y, u, v, a, b) {
        println!("RIGHT");
    } else if almost_right(x, y, u, v, a, b) {
        println!("ALMOST");
    } else {
        println!("NEITHER");
    }
}