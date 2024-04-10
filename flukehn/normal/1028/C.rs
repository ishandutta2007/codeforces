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
const INF:i32=1073741824;

#[derive(Clone,Copy)]
struct P{
    x1: i32,
    y1: i32,
    x2: i32,
    y2: i32,
}

impl P{
    fn read(&mut self,inp: &mut Parser){
        self.x1=inp.read();
        self.y1=inp.read();
        self.x2=inp.read();
        self.y2=inp.read();
    }
}
fn add(a:P,b:P)->P{
    P{
        x1:max(a.x1,b.x1),
        y1:max(a.y1,b.y1),
        x2:min(a.x2,b.x2),
        y2:min(a.y2,b.y2),
    }
}
fn main() {
    let content = stdin_to_string();
    let mut inp = Parser::new(&content);
    let n:usize=inp.read();
    const H:P=P{x1:-INF,y1:-INF,x2:INF,y2:INF};
    let mut p=vec![H;n];
    for i in 0..n{
        p[i].read(&mut inp);
    }
    let mut q=vec![H;n+1];
    for i in 0..n{
        q[i+1]=add(q[i],p[i]);
    }
    let mut t=H;
    for i in (0..n).rev(){
        let s=add(t,q[i]);
        //println!("({},{}) ({},{})",s.x1,s.y1,t.x2,t.y2);
        if s.x1<=s.x2&&s.y1<=s.y2{
            println!("{} {}",s.x1,s.y1);
            break;
        }
        t=add(t,p[i]);
    }
}