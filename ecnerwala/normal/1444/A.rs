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
 
fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let t: isize = scan.next();
    for _ in 0..t {
        let p: i64 = scan.next();
        let mut q: i32 = scan.next();

        let mut ans: i64 = 1;

        {
            let mut i = 2;
            while q != 1 {
                if i * i > q {
                    i = q;
                }
                let mut e = 0;
                let mut j = 1;
                while q % i == 0 {
                    q /= i;
                    j *= i;
                    e += 1;
                }
                if e > 0 {
                    let mut cnd = p;
                    while cnd % j as i64 == 0 {
                        cnd /= i as i64;
                    }
                    ans = std::cmp::max(ans, cnd);
                }

                i += 1;
            }
        }

        writeln!(out, "{}", ans).unwrap();
    }
}