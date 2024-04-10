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
    let n: usize = reader.next();
    for _ in 0..n {
        let x: u64 = reader.next();
        if x % 4 == 0 {
            println!("YES");
        } else {
            println!("NO");
        }
    }
}