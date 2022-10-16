use std::io;
use std::io::{Stdin, stdin};
use std::str::FromStr;
use std::collections::HashSet;

fn read_line(line: &mut String) {
    let stdin = stdin();
    match stdin.read_line(line) {
        Ok(_) => return,
        Err(msg) => panic!("Could not read line! Message: {}.", msg),
    }
}

fn parse_t<T: FromStr>(s: &str) -> T {
    match s.trim().parse() {
        Ok(y) => y,
        Err(_) => panic!("Could not read from string!"),
    }
}

fn read_ts<T: FromStr>(ts: &mut Vec<T>) {
    let stdin = stdin();
    let mut line = String::new();
    read_line(&mut line);
    let word_iter = line.split_whitespace();
    for word in word_iter {
        let x = parse_t(word);
        ts.push(x);
    }
}

fn read_i64() -> i64 {
    let stdin = stdin();
    let mut line = String::new();
    read_line(&mut line);
    match line.trim().parse() {
        Ok(i) => i,
        Err(e) => {
            panic!("Could not read i64!");
        }
    }
}

fn main() {
    let mut n_m: Vec<i64> = vec![];
    read_ts(&mut n_m);
    let mut a: Vec<i64> = vec![];
    read_ts(&mut a);
    let mut sum: i64 = 0;
    let mut d = 1;
    for i in a {
        if(i < d) {
            sum += n_m[0] - d + i;
        }else{
            sum += i - d;
        }
        d = i;
    }
    println!("{}", sum);
}