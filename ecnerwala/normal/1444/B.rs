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

fn modinv(a: i64, m: i64) -> i64 {
    if a == 1 { 1 } else { m - modinv(m % a, a) * m / a }
}

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let n: isize = scan.next();
    let mut a: Vec<i32> = (0..2*n).map(|_| scan.next()).collect();
    a.sort_unstable();
    let a = a;

    const MOD: i64 = 998244353;

    let mut val: i64 = a.iter().enumerate().map(|(i,&v)| if (i as isize) < n { -v as i64 } else { v as i64 }).sum();

    val %= MOD;

    let mut fact: i64 = 1;
    for i in 1..=n {
        fact *= i as i64; fact %= MOD;
    }

    val *= modinv(fact, MOD);
    val %= MOD;

    for i in 1..=n {
        val *= (n+i) as i64;
        val %= MOD;
    }

    writeln!(out, "{}", val).unwrap();
}

// All that matters is the index.