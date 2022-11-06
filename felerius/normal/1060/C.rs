use std::cmp;
use std::error::Error;
use std::io::{self, Read, Stdin};
use std::u32;

fn read_line(stdin: &mut Stdin) -> io::Result<String> {
    let mut s = String::new();
    stdin.read_line(&mut s)?;
    Ok(s)
}

fn ceil_div(a: usize, b: usize) -> usize {
    (a + b - 1) / b
}

fn main() -> Result<(), Box<Error>> {
    let mut stdin = io::stdin();
    read_line(&mut stdin)?;
    let a: Vec<_> = read_line(&mut stdin)?.trim().split_whitespace().map(|s| s.parse::<u32>().unwrap()).collect();
    let b: Vec<_> = read_line(&mut stdin)?.trim().split_whitespace().map(|s| s.parse::<u32>().unwrap()).collect();
    let x = read_line(&mut stdin)?.trim().parse::<u32>().unwrap();

    let mut a_mins = vec![u32::max_value(); a.len()];
    for i in 0..a.len() {
        let mut sum = 0;
        for j in i..a.len() {
            sum += a[j];
            a_mins[j - i] = cmp::min(a_mins[j - i], sum);
        }
    }
    let mut b_mins = vec![u32::max_value(); b.len()];
    for i in 0..b.len() {
        let mut sum = 0;
        for j in i..b.len() {
            sum += b[j];
            b_mins[j - i] = cmp::min(b_mins[j - i], sum);
        }
    }

    let mut max_size = 0;
    for (a_len, a_min_sum) in a_mins.into_iter().enumerate() {
        for (b_len, b_min_sum) in b_mins.iter().cloned().enumerate() {
            if a_min_sum.saturating_mul(b_min_sum) <= x {
                max_size = cmp::max(max_size, (a_len + 1) * (b_len + 1));
            }
        }
    }

    println!("{}", max_size);
    Ok(())
}