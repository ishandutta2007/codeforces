use std::io;
use std::io::Stdin;
use std::str::FromStr;
use std::collections::HashSet;

fn read_line(stdin: &Stdin, line: &mut String) {
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

fn read_ts<T: FromStr>(stdin: &Stdin, ts: &mut Vec<T>) {
    let mut line = String::new();
    read_line(stdin, &mut line);
    let word_iter = line.split_whitespace();
    for word in word_iter {
        let x = parse_t(word);
        ts.push(x);
    }
}

pub fn read_i64(stdin: &Stdin) -> i64 {
    let mut line = String::new();
    read_line(&stdin, &mut line);
    match line.trim().parse() {
        Ok(i) => i,
        Err(e) => {
            panic!("Could not read i64!");
        }
    }
}

struct Team {
    a: i32,
    b: i32,
}

fn main() {
    let stdin = io::stdin();
    let n = read_i64(&stdin) as usize;
    let mut k: Vec<Team> = vec![];
    for i in 0..n {
        let mut v= vec![];
        read_ts(&stdin, &mut v);
        k.push(Team { a: v[0], b: v[1] });
    }
    let mut s = 0;
    for i in 0..n {
        for j in 0..n {
            if k[i].a == k[j].b {
                s += 1;
            }
        }
    }
    println!("{}", s);
}