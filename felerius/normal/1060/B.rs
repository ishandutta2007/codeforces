use std::error::Error;
use std::io::{self, Read};

fn main() -> Result<(), Box<Error>> {
    let mut stdin = io::stdin();
    let mut line = String::new();
    stdin.read_line(&mut line)?;
    let num_str = line.trim();
    let num: u64 = num_str.parse()?;
    let num_nines = num_str.len() - 1;
    let remaining_num = num - (10_u64.pow(num_nines as u32) - 1);
    let rem_digit_sum: u32 = remaining_num.to_string().into_bytes().into_iter().map(|c| (c - b'0') as u32).sum();
    println!("{}", num_nines as u32 * 9 + rem_digit_sum);

    Ok(())
}