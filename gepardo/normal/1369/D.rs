use std::io::{self, BufRead};
use std::str::FromStr;
use std::iter;

struct BufReader<'a, R> {
    reader: &'a mut R,
    line: String,
    tokens: std::vec::IntoIter<String>
}

trait Reader {
    fn next_token(&mut self) -> String;
    
    fn next<T: FromStr>(&mut self) -> T {
        let token = self.next_token();
        match token.parse() {
            Ok(val) => val,
            Err(_) => panic!(format!("cannot parse token {}", token))
        }
    }
    
    fn next_many<T: FromStr>(&mut self, amount: usize) -> Vec<T> {
        iter::repeat_with(|| self.next()).take(amount).collect()
    }
}

impl<'a, R: BufRead> BufReader<'a, R> {
    fn new(reader: &'a mut R) -> BufReader<'a, R> {
        BufReader {
            reader,
            line: String::new(),
            tokens: vec![].into_iter()
        }
    }
    
    fn read_line(&mut self) {
        self.line.clear();
        self.reader.read_line(&mut self.line).unwrap();
        let v: Vec<_> = self.line.split_ascii_whitespace().map(|x| x.to_string()).collect();
        self.tokens = v.into_iter();
    }
}

impl<'a, R: BufRead> Reader for BufReader<'a, R> {
    fn next_token(&mut self) -> String {
        loop {
            match self.tokens.next() {
                Some(v) => return v,
                None => self.read_line()
            }
        }
    }
}

fn main() {
    let stdin = io::stdin();
    let mut lock = stdin.lock();
    let mut reader = BufReader::new(&mut lock);
    
    const MOD: i64 = 1_000_000_007;
    
    let lim: usize = 2_000_202;
    let mut d0: Vec<i64> = Vec::new();
    let mut d1: Vec<i64> = Vec::new();
    d0.resize(lim, 0);
    d1.resize(lim, 0);
    
    for i in 3..lim {
        let v0 = 2 * d1[i-2] + d1[i-1];
        let v1 = 2 * d0[i-2] + d0[i-1] + 4;
        let v1 = if i % 3 == 2 { v0 } else { v1 };
        d0[i] = v0 % MOD;
        d1[i] = v1 % MOD;
    }
    
    let t: usize = reader.next();
    for _ in 0..t {
        println!("{}", d1[reader.next::<usize>()]);
    }
}