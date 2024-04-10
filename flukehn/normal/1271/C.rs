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
//const EPS: f64 = 1e-9;

fn main() {
    let content = stdin_to_string();
    let mut inp = Parser::new(&content); // inp.read()
    let n: usize = inp.read();
    let sx: i32 = inp.read();
    let sy: i32 = inp.read();
    let mut f = [0i32; 4];
    for _ in 0..n {
        let x: i32 = inp.read();
        let y: i32 = inp.read();
        f[0] += (x < sx) as i32;
        f[1] += (x > sx) as i32;
        f[2] += (y < sy) as i32;
        f[3] += (y > sy) as i32;
    }
    let mut ans: i32 = f[0];
    let mut p = 0;
    for i in 1..4 {
        if f[i] > ans {
            ans = f[i];
            p = i;
        }
    }
    println!("{}\n{} {}", ans, sx + [-1,1,0,0][p], sy + [0,0,-1,1][p]);
}