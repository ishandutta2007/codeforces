use std::io::{BufWriter, stdin, stdout, Write};

#[derive(Default)]
struct Scanner {
    buffer: Vec<String>
}

impl Scanner {
    fn next<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("Failed parse");
            }
            let mut input = String::new();
            stdin().read_line(&mut input).expect("Failed read");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }
}

fn solve(n: usize, m: u64, w: Vec<u64>) -> Vec<usize>
{
    let mut result = Vec::new();
    let mut sum: u64 = 0;
    for i in 0..n {
        if w[i] <= m {
            if 2 * w[i] >= m {
                return vec![i];
            } else {
                result.push(i);
                sum += w[i];
                if 2 * sum >= m {
                    return result;
                }
            }
        }
    }
    return vec![];
}

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    for _ in 0..scan.next::<usize>() {
        let n = scan.next::<usize>();
        let m = scan.next::<u64>();
        let w: Vec<u64> = (0..n).map(|_| scan.next::<u64>()).collect();
        let result = solve(n, m, w);
        let n = result.len();
        if n > 0 {
            writeln!(out, "{}", n).ok();
            for (i, v) in result.iter().enumerate() {
                write!(out, "{}{}", v + 1, if i + 1 < n { ' ' } else { '\n' }).ok();
            }
        } else {
            writeln!(out, "-1").ok();
        }
    }
}