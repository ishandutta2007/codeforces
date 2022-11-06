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
use std::iter::repeat;
use std::cmp::max;
/*
fn cmp(&(a1, a2): &(usize, usize), &(b1, b2): &(usize, usize)) -> Ordering {
    let ah = max(a1, a2);
    let al = min(a1, a2);
    let bh = max(b1, b2);
    let bl = min(b1, b2);
    
    if ah != bh {
        return ah.cmp(&bh);
    }
    
    bl.cmp(&al)
}
*/
    
fn main() {
    let content = stdin_to_string();
    let mut inp = Parser::new(&content);
    let n: i32 = inp.read();
    let s: f64 = inp.read();
    for i in 1..n {
        let c = {
            if i + 1 == n {
                '\n'
            } else {
                ' '
            }
        };
        print!("{}{}", (i as f64 / n as f64).sqrt() * s, c);
    }
}