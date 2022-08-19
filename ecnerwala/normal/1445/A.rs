use std::io::{stdin, stdout, BufWriter, Write};

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

    let t = scan.next::<isize>();
    for _ in 0..t {
        let n: isize = scan.next();
        let x: i32 = scan.next();

        let a: Vec<i32> = (0..n).map(|_| scan.next()).collect();
        let mut b: Vec<i32> = (0..n).map(|_| scan.next()).collect();
        b.reverse();
        let b = b;
        let is_good = a.iter().zip(b.iter()).all(|(s,t)| s+t <= x);
        writeln!(out, "{}", if is_good { "Yes" } else { "No" }).ok();
    }
}