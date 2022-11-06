use std::cmp;
use std::error::Error;
use std::io::{self, Read, Stdin};
use std::u32;

fn read_line(stdin: &mut Stdin) -> io::Result<String> {
    let mut s = String::new();
    stdin.read_line(&mut s)?;
    Ok(s)
}

fn main() -> Result<(), Box<Error>> {
    let mut stdin = io::stdin();
    let n = read_line(&mut stdin)?.trim().parse::<u32>()?;
    let mut a = Vec::with_capacity(n as usize);
    let mut b = Vec::with_capacity(n as usize);
    for _ in 0..n {
        let line = read_line(&mut stdin).unwrap();
        let mut iter = line.trim().split_whitespace();
        let l = iter.next().unwrap().parse::<u32>().unwrap();
        let r = iter.next().unwrap().parse::<u32>().unwrap();
        a.push(l);
        b.push(r);
    }

    a.sort_unstable();
    b.sort_unstable();
    let seats = n as u64 + a.into_iter().zip(b).map(|(l, r)| cmp::max(l, r) as u64).sum::<u64>();
    println!("{}", seats);
    Ok(())
}