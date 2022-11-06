use std::cmp;
use std::error::Error;
use std::fmt::{self, Debug, Formatter};
use std::io::{self, BufRead};
use std::u32;

const OFFSETS: [(usize, usize); 8] = [(0, 0), (1, 0), (2, 0), (0, 1), (2, 1), (0, 2), (1, 2), (2, 2)];

#[allow(dead_code)]
pub struct WrapDebug<T>(pub T);

impl<T: Debug> Debug for WrapDebug<T> {
    fn fmt(&self, f: &mut Formatter) -> fmt::Result { self.0.fmt(f) }
}

/// See module level documentation.
#[macro_export]
macro_rules! dbg {
    // Handle `dbg!()` <-- literal
    () => {
        dbg!( () );
    };
    // Handle trailing comma:
    ($($val: expr),+,) => {
        dbg!( $($val),+ )
    };
    ($($lab: expr => $val: expr),+,) => {
        dbg!( $($lab => $val),+ )
    };
    // Without label, use source of $val:
    ($valf: expr $(, $val: expr)*) => {{
        // in order: for panics, clarification on: dbg!(expr);, dbg!(expr)
        #[allow(unreachable_code, unused_must_use, unused_parens)]
        let _r = {
        #[cfg(not(debug_assertions))] { ($valf $(, $val)*) }
        #[cfg(debug_assertions)] {
            // DEBUG: Lock STDERR in a buffered writer.
            // Motivation:
            // 1. to avoid needless re-locking of STDERR at every write(ln)!.
            // 2. to ensure that the printed message is not interleaved, which
            // would disturb the readability of the output, by other messages to
            // STDERR.
            use ::std::io::Write;
            let stderr = ::std::io::stderr();
            let mut err = ::std::io::BufWriter::new(stderr.lock());

            // Are we in not in compact mode (detailed)?
            // If so:
            // + {:?} is used instead of {:#?},
            // + Header is: [<location>]
            let detailed = option_env!("RUST_DBG_COMPACT")
                            .map_or(true, |s| s == "0");

            (if detailed {
                write!(&mut err, "[DEBUGGING, {}:{}]\n=> ", file!(), line!())
            } else {
                write!(&mut err, "[{}:{}] ", file!(), line!())
            }).unwrap();

            // Foreach label and expression:
            //     1. Evaluate each expression,
            //     2. Print out $lab = value of expression
            let _ret = (
                {
                    // Print out $lab = :
                    write!(&mut err, "{} = ", stringify!($valf)).unwrap();

                    // Evaluate, tmp is value:
                    let _tmp = $crate::WrapDebug($valf);
                    // Won't get further if $val panics.

                    // Print out tmp:
                    (if detailed { write!(&mut err, "{:#?}", _tmp) }
                    else         { write!(&mut err, "{:?}" , _tmp) }).unwrap();

                    // Yield tmp:
                    _tmp.0
                }
                $(, {
                    // Comma separator:
                    write!(&mut err, ", ").unwrap();

                    // Print out $lab = :
                    write!(&mut err, "{} = ", stringify!($val)).unwrap();

                    // Evaluate, tmp is value:
                    let _tmp = $crate::WrapDebug($val);
                    // Won't get further if $val panics.

                    // Print out tmp:
                    (if detailed { write!(&mut err, "{:#?}", _tmp) }
                     else        { write!(&mut err, "{:?}" , _tmp) }).unwrap();

                    // Yield tmp:
                    _tmp.0
                } )*
            );

            // Newline:
            (if detailed { writeln!(&mut err, "\n") }
             else        { writeln!(&mut err, "")   }).unwrap();

            // Return the expression:
            _ret
        }
        };
        _r
    }};
    // With label:
    ($labf: expr => $valf: expr $(, $lab: expr => $val: expr)*) => {{
        // in order: for panics, clarification on: dbg!(expr);, dbg!(expr)
        #[allow(unreachable_code, unused_must_use, unused_parens)]
        let _r = {
        #[cfg(not(debug_assertions))] { ($valf $(, $val)*) }
        #[cfg(debug_assertions)] {
            // DEBUG: Lock STDERR in a buffered writer.
            // Motivation:
            // 1. to avoid needless re-locking of STDERR at every write(ln)!.
            // 2. to ensure that the printed message is not interleaved, which
            // would disturb the readability of the output, by other messages to
            // STDERR.
            use ::std::io::Write;
            let stderr = ::std::io::stderr();
            let mut err = ::std::io::BufWriter::new(stderr.lock());

            // Are we in not in compact mode (detailed)?
            // If so:
            // + {:?} is used instead of {:#?},
            // + Header is: [<location>]
            let detailed = option_env!("RUST_DBG_COMPACT")
                            .map_or(true, |s| s == "0");

            (if detailed {
                write!(&mut err, "[DEBUGGING, {}:{}]\n=> ", file!(), line!())
            } else {
                write!(&mut err, "[{}:{}] ", file!(), line!())
            }).unwrap();

            // Foreach label and expression:
            //     1. Evaluate each expression,
            //     2. Print out $lab = value of expression
            let _ret = (
                {
                    // Enforce is_literal_string($lab):
                    let _ = concat!($labf, "");
                    let _ : &'static str = $labf;

                    // Print out $lab = :
                    write!(&mut err, "{} = ", stringify!($labf)).unwrap();

                    // Evaluate, tmp is value:
                    let _tmp = $crate::WrapDebug($valf);
                    // Won't get further if $val panics.

                    // Print out tmp:
                    (if detailed { write!(&mut err, "{:#?}", _tmp) }
                     else        { write!(&mut err, "{:?}" , _tmp) }).unwrap();

                    // Yield tmp:
                    _tmp.0
                }
                $(, {
                    // Comma separator:
                    write!(&mut err, ", ").unwrap();

                    // Enforce is_literal_string($lab):
                    let _ = concat!($lab, "");
                    let _ : &'static str = $lab;

                    // Print out $lab = :
                    write!(&mut err, "{} = ", stringify!($lab)).unwrap();

                    // Evaluate, tmp is value:
                    let _tmp = $crate::WrapDebug($val);
                    // Won't get further if $val panics.

                    // Print out tmp:
                    (if detailed { write!(&mut err, "{:#?}", _tmp) }
                     else        { write!(&mut err, "{:?}" , _tmp) }).unwrap();

                    // Yield tmp:
                    _tmp.0
                } )*
            );

            // Newline:
            (if detailed { writeln!(&mut err, "\n") }
             else        { writeln!(&mut err, "")   }).unwrap();

            // Return the expression:
            _ret
        }
        };
        _r
    }};
}

macro_rules! parse_line {
    ($reader:expr => ($($t:ty),*)) => {{
        let s = read_line(&mut $reader).unwrap();
        let mut iter = s.trim().split_whitespace();
        ( $(iter.next().unwrap().parse::<$t>().unwrap()),* )
    }}
}

fn read_line(mut reader: impl BufRead) -> io::Result<String> {
    let mut s = String::new();
    reader.read_line(&mut s)?;
    Ok(s)
}

fn calc_coord(base: usize, delta: usize, pos: usize, range: usize) -> Option<usize> {
    if base + delta < pos || base + delta - pos >= range {
        None
    } else {
        Some(base + delta - pos)
    }
}

fn main() -> Result<(), Box<Error>> {
    let stdin_slow = io::stdin();
    let mut stdin = stdin_slow.lock();

    let (n, m) = parse_line!(stdin => (usize, usize));
    let grid: Vec<Vec<_>> = (0..n).map(|_| {
        let line = read_line(&mut stdin).unwrap();
        let bytes = line.trim().as_bytes();
        (0..m).map(|x| bytes[x] == b'#').collect()
    }).collect();

    let mut possible = true;
    for y in 0..n {
        for x in 0..m {
            if grid[y][x] {
                possible &= OFFSETS.iter().any(|&(px, py)| {
                    OFFSETS.iter().all(|&(dx, dy)| {
                        let ox = calc_coord(x, dx, px, m);
                        let oy = calc_coord(y, dy, py, n);
                        if let (Some(fx), Some(fy)) = (ox, oy) {
                            grid[fy][fx]
                        } else {
                            false
                        }
                    })
                });
            }
        }
    }

    println!("{}", if possible { "YES" } else { "NO" });
    Ok(())
}