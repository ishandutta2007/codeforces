use std::cmp;
use std::error::Error;
use std::io::{self, BufRead};
use std::u32;

macro_rules! parse_line {
    ($reader:expr => ($($t:ty),*)) => {{
        let s = read_line(&mut $reader).unwrap();
        let mut iter = s.trim().split_whitespace();
        ( $(iter.next().unwrap().parse::<$t>().unwrap()),* )
    }}
}

fn read_line(mut reader: impl BufRead) -> io::Result<String> {
    let mut s = String::new();
    reader.read_line(&mut s)?;
    Ok(s)
}

fn main() -> Result<(), Box<Error>> {
    let stdin_slow = io::stdin();
    let mut stdin = stdin_slow.lock();
    let (n, l, a) = parse_line!(stdin => (u32, u32, u32));
    let mut breaks = 0;
    let mut start = 0;
    for _ in 0..n {
        let (t, l) = parse_line!(stdin => (u32, u32));
        breaks += (t - start) / a;
        start = t + l;
    }

    breaks += (l - start) / a;
    println!("{}", breaks);
    Ok(())
}