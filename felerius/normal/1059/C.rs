#[allow(unused_imports)]
use std::cmp;
use std::error::Error;
use std::io::{self, BufRead};
use std::u32;

macro_rules! parse_line {
    ($reader:expr => ($($t:ty),*)) => {{
        let s = read_line(&mut $reader).unwrap();
        let mut iter = s.trim().split_whitespace();
        ( $(iter.next().unwrap().parse::<$t>().unwrap()),* )
    }};
    ($reader:expr => $t:ty) => {{
        read_line(&mut $reader).unwrap().trim().parse::<$t>().unwrap()
    }};
}

fn read_line(mut reader: impl BufRead) -> io::Result<String> {
    let mut s = String::new();
    reader.read_line(&mut s)?;
    Ok(s)
}

fn ceil_div(n: u32, divisor: u32) -> u32 {
    (n + divisor - 1) / divisor
}

fn main() -> Result<(), Box<Error>> {
    let stdin_slow = io::stdin();
    let mut stdin = stdin_slow.lock();

    let n = parse_line!(stdin => u32);
    let mut remaining = n;
    let mut gcd = 1;
    loop {
        if remaining == 1 {
            println!("{}", gcd);
            break;
        } else if remaining == 3 {
            println!("{} {} {}", gcd, gcd, gcd * 3);
            break;
        }

        for _ in 0..ceil_div(remaining, 2) {
            print!("{} ", gcd);
        }

        remaining /= 2;
        gcd *= 2;
    }

    Ok(())
}