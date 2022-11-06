use std::cmp;
use std::error::Error;
use std::io::{self, Read};

fn main() -> Result<(), Box<Error>> {
    let mut stdin = io::stdin();
    let mut line = String::new();
    stdin.read_line(&mut line)?;
    let num_digits: usize = line.trim().parse()?;
    let mut digits = vec![0u8; num_digits];
    stdin.read_exact(&mut digits)?;
    let num_eights = digits.iter().filter(|c| **c == b'8').count();
    println!("{}", cmp::min(num_digits / 11, num_eights));
    Ok(())
}