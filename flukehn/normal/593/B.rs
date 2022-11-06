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
//const INF:i32=1073741824;

fn work(inp:&mut Parser) -> bool{
    let n:usize=inp.read();
    let x1:i64=inp.read();
    let x2:i64=inp.read();
    let mut v=vec![(0i64,0i64);n];
    for i in 0..n{
        let k:i64=inp.read();
        let b:i64=inp.read();
        v[i]=(k*x1+b,k*x2+b);
    }
    
    /*for i in 0..n{
        println!("{} {}",v[i].0,v[i].1);
    }*/
    v.sort();
    for i in 1..n{
        if v[i].1<v[i-1].1{
            return true;
        }
    }
    return false;
}
fn main() {
    let content = stdin_to_string();
    let mut inp = Parser::new(&content);
    println!("{}",["NO","YES"][work(&mut inp) as usize]);
}