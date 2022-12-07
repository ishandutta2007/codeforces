use std::{
    cmp::{self, Reverse},
    error::Error,
    io::{stdin, stdout, BufRead, BufWriter, Write},
};

use crate::io::TokenReader;

fn solve(
    reader: &mut TokenReader<impl BufRead>,
    mut writer: impl Write,
) -> Result<(), Box<dyn Error>> {
    let n: usize = reader.get();
    let c: u64 = reader.get();
    let d: usize = reader.get();
    let mut a: Vec<u64> = reader.iter().take(n).collect();
    a.sort_unstable_by_key(|&ai| Reverse(ai));
    for i in 1..n {
        a[i] += a[i - 1];
    }

    if a[0] * (d as u64) < c {
        return writeln!(writer, "Impossible").map_err(Into::into);
    }
    if a[cmp::min(n, d) - 1] >= c {
        return writeln!(writer, "Infinity").map_err(Into::into);
    }

    for k in (0..d).rev() {
        let full = d / (k + 1);
        let partial = d % (k + 1);
        let mut val = a[cmp::min(n - 1, k)] * full as u64;
        if partial > 0 {
            val += a[cmp::min(n, partial) - 1];
        }

        if val >= c {
            return writeln!(writer, "{}", k).map_err(Into::into);
        }
    }

    Ok(())
}

fn main() -> Result<(), Box<dyn Error>> {
    let stdin_unlocked = stdin();
    let mut reader = TokenReader::new(stdin_unlocked.lock());
    let stdout_unlocked = stdout();
    let mut writer = BufWriter::new(stdout_unlocked.lock());

    let t: usize = reader.get();
    for _ in 0..t {
        solve(&mut reader, &mut writer)?;
    }

    Ok(())
}

mod io {
    use std::{io::BufRead, iter, str};

    pub struct TokenReader<R>(R);

    impl<R: BufRead> TokenReader<R> {
        pub fn new(reader: R) -> Self {
            Self(reader)
        }

        pub fn get<T: Token>(&mut self) -> T {
            <T as Token>::read(self)
        }

        pub fn iter<T: Token>(&mut self) -> impl '_ + Iterator<Item = T> {
            iter::repeat_with(move || self.get::<T>())
        }

        pub fn get_ascii_char(&mut self) -> char {
            self.skip_whitespace();
            let res = char::from(self.get_buf()[0]);
            self.0.consume(1);
            res
        }

        fn get_buf(&mut self) -> &[u8] {
            self.0.fill_buf().expect("input error")
        }

        fn process_bufs(&mut self, mut f: impl FnMut(&[u8]) -> usize) {
            loop {
                let buf = self.get_buf();
                if buf.is_empty() {
                    break;
                }
                let buf_len = buf.len();
                let consumed = f(buf);
                self.0.consume(consumed);
                if consumed != buf_len {
                    break;
                }
            }
        }

        fn skip_whitespace(&mut self) {
            self.process_bufs(|buf| buf.iter().take_while(|c| c.is_ascii_whitespace()).count());
        }
    }

    pub trait Token {
        fn read(reader: &mut TokenReader<impl BufRead>) -> Self;
    }

    impl Token for String {
        fn read(reader: &mut TokenReader<impl BufRead>) -> Self {
            reader.skip_whitespace();
            let mut res = Self::new();
            reader.process_bufs(|buf| {
                let len = buf.iter().take_while(|&c| !c.is_ascii_whitespace()).count();
                res.push_str(str::from_utf8(&buf[..len]).expect("invalid utf-8 in input"));
                len
            });
            res
        }
    }

    macro_rules! impl_readable_unsigned {
    ($ty:ty) => {
        impl Token for $ty {
            fn read(reader: &mut TokenReader<impl BufRead>) -> Self {
                reader.skip_whitespace();
                let mut value = 0;
                reader.process_bufs(|buf| {
                    buf.iter()
                        .take_while(|c| !c.is_ascii_whitespace())
                        .inspect(|&c| value = 10 * value + Self::from(c - b'0'))
                        .count()
                });
                value
            }
        }
    };
    ($ty:ty, $($tys:ty),*) => {
        impl_readable_unsigned!($ty);
        impl_readable_unsigned!($($tys),*);
    }
}
    impl_readable_unsigned!(u8, u16, u32, u64, u128, usize);

    macro_rules! impl_readable_signed {
    (($ty:ty, $uty:ty)) => {
        impl Token for $ty {
            fn read(reader: &mut TokenReader<impl BufRead>) -> Self {
                reader.skip_whitespace();
                if reader.get_buf()[0] == b'-' {
                    reader.0.consume(1);
                    reader.get::<$uty>().wrapping_neg() as Self
                } else {
                    reader.get::<$uty>() as Self
                }
            }
        }
    };
    (($ty:ty, $uty:ty), $($rest:tt)*) => {
        impl_readable_signed!(($ty, $uty));
        impl_readable_signed!($($rest)*);
    }
}

    impl_readable_signed!(
        (i8, u8),
        (i16, u16),
        (i32, u32),
        (i64, u64),
        (i128, u128),
        (isize, usize)
    );
}