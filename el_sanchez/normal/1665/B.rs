mod trd {

    use std::str;
    use std::io::BufRead;

    pub struct Scanner<R: BufRead> {
        reader: R,
        buf: Vec<u8>,
        split: str::SplitWhitespace<'static>,
    }

    impl<R: BufRead> Scanner<R> {
        pub fn new(reader: R) -> Self {
            Self {
                reader,
                buf: vec![],
                split: "".split_whitespace(),
            }
        }

        pub fn next<T: str::FromStr>(&mut self) -> T {
            loop {
                if let Some(token) = self.split.next() {
                    return token.parse().ok().expect("failed to parse");
                }

                self.buf.clear();
                self.reader.read_until(b'\n', &mut self.buf).expect("failed to read");

                let slice = unsafe {
                    // Assume the input is correct UTF-8
                    str::from_utf8_unchecked(&self.buf)
                };
                self.split = unsafe {
                    // Assume the split does not outlive the underlying buffer (it won't)
                    std::mem::transmute(slice.split_whitespace())
                }
            }
        }
    }

}

use std::cmp::max;
use std::collections::HashMap;
use std::io::*;
use std::ops::Add;
use trd::*;

fn solve<R: BufRead, W: Write>(sc: &mut Scanner<R>, w: &mut W) {
    let t: usize = sc.next();
    for _ in 0..t {
        let n: u32 = sc.next();
        let mut occ: HashMap<i32, u32> = HashMap::new();
        let mut k = 0u32;
        for _ in 0..n {
            let a: i32 = sc.next();
            let x = occ.entry(a).or_default();
            *x += 1;
            k = max(k, *x);
        }
        // eprintln!("{:?}", occ);
        let x = (n + k - 1) / k;
        let t = 32 - (x - 1).leading_zeros();
        // eprintln!("{} {} {}", n, k, t);
        writeln!(w, "{}", n - k + t).ok();
    }
}

fn main() {
    let (stdin, stdout) = (stdin(), stdout());
    let mut sc = Scanner::new(stdin.lock());
    let mut w = BufWriter::new(stdout.lock());
    solve(&mut sc, &mut w);
}