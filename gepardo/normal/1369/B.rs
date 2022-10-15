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
    let t: usize = reader.next();
    for _ in 0..t {
        let n: usize = reader.next();
        let s: String = reader.next();
        let s = s.as_bytes();
        let mut i: usize = 0;
        let mut zeroes: usize;
        let mut ones: usize = 0;
        while i < n && s[i] == b'0' {
            i += 1;
        }
        zeroes = i;
        let mut add: usize = 0;
        while i < n {
            let l = i;
            while i < n && s[i] == b'1' {
                i += 1;
            }
            if i == n {
                ones = i - l;
                break;
            }
            while i < n && s[i] == b'0' {
                i += 1;
            }
            add += 1;
        }
        if add != 0 {
            zeroes += 1;
        }
        let mut result = String::new();
        for _ in 0..zeroes {
            result += "0";
        }
        for _ in 0..ones {
            result += "1";
        }
        println!("{}", result);
    }
}