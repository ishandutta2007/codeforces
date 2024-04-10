use std::io;
use std::io::Stdin;
use std::str::FromStr;
use std::collections::HashSet;

fn read_line(stdin : &Stdin, line : &mut String) {
    match stdin.read_line(line) {
        Ok(_) => return,
        Err(msg) => panic!("Could not read line! Message: {}.", msg),
    }
}

fn parse_t<T : FromStr>(s : &str) -> T {
    match s.trim().parse() {
        Ok(y) => y,
        Err(_) => panic!("Could not read from string!"),
    }
}

fn read_ts<T : FromStr>(stdin : &Stdin, ts : &mut Vec<T>) {
    let mut line = String::new();
    read_line(stdin, &mut line);
    let word_iter = line.split_whitespace();
    for word in word_iter {
        let x = parse_t(word);
        ts.push(x);
    }
}

fn main() {
    let stdin = io::stdin();
    let mut line= String::new();
    read_line(&stdin, &mut line);
    let mut l = line.trim();
    l = &l[1..l.len() - 1];
    let mut vis = HashSet::new();
    for i in l.split(", ") {
        if i.len() > 0 {
            vis.insert(i);
        }
    }
    println!("{}", vis.len());
}