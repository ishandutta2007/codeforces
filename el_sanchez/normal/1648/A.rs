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

const MAXC: usize = 100_500;

fn count(occ: &[usize]) -> u64 {
    let n = occ.len() as i64;
    let mut mult: i64 = -(n - 1);
    let mut res = 0i64;
    for i in 0..n {
        res += mult * (occ[i as usize] as i64);
        mult += 2;
    }
    res as u64
}

fn solve<R: BufRead, W: Write>(sc: &mut Scanner<R>, w: &mut W) {
    let n: usize = sc.next();
    let m: usize = sc.next();
    let mut a = vec![vec![0u32; m]; n];
    let mut occ: Vec<Vec<Vec<usize>>> = vec![vec![vec![]; MAXC]; 2];
    for i in 0..n {
        for j in 0..m {
            a[i][j] = sc.next();
        }
    }

    for i in 0..n {
        for j in 0..m {
            occ[0][a[i][j] as usize].push(i);
        }
    }
    for j in 0..m {
        for i in 0..n {
            occ[1][a[i][j] as usize].push(j);
        }
    }

    let mut sum: u64 = 0;
    for k in 0..2 {
        for i in 0..MAXC {
            sum += count(&occ[k][i]);
        }
    }
    writeln!(w, "{}", sum);
}

fn main() {
    let (stdin, stdout) = (stdin(), stdout());
    let mut sc = Scanner::new(stdin.lock());
    let mut w = BufWriter::new(stdout.lock());
    solve(&mut sc, &mut w);
}