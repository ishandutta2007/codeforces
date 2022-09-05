use std::io::{self, BufRead, Write};
use std::str::FromStr;
use std::fmt::Debug;

#[allow(unused_variables)]
fn solve(input: &mut FastDynInput<'_>, output: &mut dyn Write) -> io::Result<()> {
    let t = input.iread();
    for _ in 0..t {
        let n = input.iread();
        let s1 = input.read_bytes();
        let s2 = input.read_bytes();
        if (0usize..n as usize).any(|idx| s1[idx] == b'1' && s2[idx] == b'1') {
            writeln!(output, "NO")?;
        } else {
            writeln!(output, "YES")?;
        }
    }
    Ok(())
}

struct FastDynInput<'a> {
    stdin: Box<dyn BufRead + 'a>,
}

impl<'a, R: BufRead + 'a> From<R> for FastDynInput<'a> {
    fn from(r: R) -> Self {
        Self {
            stdin: Box::new(r),
        }
    }
}

#[allow(dead_code)]
impl FastDynInput<'_> {
    fn read_bytes(&mut self) -> Vec<u8> {
        let mut bytes: Vec<u8> = Vec::new();
        let mut skip_space = true;
        loop {
            if let Ok(buf) = self.stdin.fill_buf() {
                if buf.is_empty() {
                    break;
                }
                let mut pos: usize = 0;
                if skip_space {
                    while pos < buf.len() && buf[pos] <= 32 {
                        pos += 1;
                    }
                    if pos < buf.len() {
                        skip_space = false;
                    } else {
                        self.stdin.consume(pos);
                        continue;
                    }
                }
                while pos < buf.len() && buf[pos] > 32 {
                    bytes.push(buf[pos]);
                    pos += 1;
                }
                if pos < buf.len() {
                    self.stdin.consume(pos);
                    break;
                }
                self.stdin.consume(pos);
            } else {
                break;
            }
        }
        bytes
    }

    fn read_word(&mut self) -> String {
        String::from_utf8(self.read_bytes()).unwrap()
    }

    fn try_read_word(&mut self) -> Option<String> {
        let result = self.read_bytes();
        if result.is_empty() {
            return None;
        }
        String::from_utf8(result).ok()
    }

    fn read_line_bytes(&mut self) -> Option<Vec<u8>> {
        let mut bytes: Vec<u8> = Vec::new();
        loop {
            if let Ok(buf) = self.stdin.fill_buf() {
                if buf.is_empty() {
                    if bytes.is_empty() {
                        return None;
                    }
                    break;
                }
                let mut pos: usize = 0;
                while pos < buf.len() && buf[pos] != b'\n' {
                    if buf[pos] != b'\r' {
                        bytes.push(buf[pos]);
                    }
                    pos += 1;
                }
                if pos < buf.len() {
                    pos += 1;
                    self.stdin.consume(pos);
                    break;
                }
                self.stdin.consume(pos);
            } else {
                break;
            }
        }
        Some(bytes)
    }

    fn read_line(&mut self) -> String {
        String::from_utf8(self.read_line_bytes().unwrap()).unwrap()
    }

    fn try_read_line(&mut self) -> Option<String> {
        String::from_utf8(self.read_line_bytes()?).ok()
    }

    fn iread(&mut self) -> i32 {
        self.read()
    }

    fn uread(&mut self) -> u32 {
        self.read()
    }

    fn dread(&mut self) -> f64 {
        self.read()
    }

    fn lread(&mut self) -> i64 {
        self.read()
    }

    fn read<V>(&mut self) -> V
        where V: FromStr,
              V::Err: Debug {
        self.read_word().parse::<V>().unwrap()
    }

    fn parse<V: FromStr>(&mut self) -> Result<V, V::Err> {
        self.read_word().parse::<V>()
    }
}

fn main() -> io::Result<()> {
    let stdin = io::stdin();
    let mut input = FastDynInput::from(stdin.lock());
    let stdout = io::stdout();
    let stdout_lock = stdout.lock();
    let mut output = io::BufWriter::new(stdout_lock);
    solve(&mut input, &mut output)
}