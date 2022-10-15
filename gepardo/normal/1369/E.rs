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
    let m: usize = reader.next();
    let mut w: Vec<i64> = reader.next_many(n);
    let mut g: Vec<Vec<(usize, usize)>> = Vec::new();
    g.resize_with(n, Vec::new);
    for i in 0..m {
        let a = reader.next::<usize>() - 1;
        let b = reader.next::<usize>() - 1;
        g[a].push((b, i));
        g[b].push((a, i));
        w[a] -= 1;
        w[b] -= 1;
    }
    let mut used: Vec<bool> = Vec::new();
    used.resize(m, false);
    let mut good: Vec<bool> = Vec::new();
    good.resize(n, false);
    let mut good_vec: Vec<usize> = Vec::new();
    let mut added: usize = 0;
    for i in 0..n {
        if w[i] >= 0 {
            good_vec.push(i);
            good[i] = true;
        }
    }
    let mut result: Vec<usize> = Vec::new();
    while let Some(v) = good_vec.pop() {
        added += 1;
        for (to, eid) in &g[v] {
            let to = to.clone();
            let eid = eid.clone();
            if !used[eid] {
                used[eid] = true;
                result.push(eid + 1);
            }
            if good[to] {
                continue;
            }
            w[to] += 1;
            if w[to] >= 0 {
                good_vec.push(to);
                good[to] = true;
            }
        }
    }
    if added != n {
        println!("DEAD");
        return;
    }
    result.reverse();
    println!("ALIVE");
    println!("{}", result.iter().map(usize::to_string).collect::<Vec<_>>().join(" "));
}