use std::io;
use std::io::Read;
use std::cmp::Ordering;

pub struct Scanner<'a> {
	input: &'a mut dyn Read,
	buf: Vec<u8>,
	at: usize,
	buf_read: usize
}

impl<'a> Scanner<'a> {
	const BUF_SIZE: usize = 4096;

	pub fn new(input: &'a mut dyn Read) -> Scanner {
		Scanner {
			input,
			buf: vec![0; Self::BUF_SIZE],
			at: 0,
			buf_read: 0
		}
	}

	pub fn refill_buffer(&mut self) -> bool {
		if self.at == self.buf_read {
			self.buf_read = self.input.read(&mut self.buf).unwrap();
			self.at = 0;
		}
		self.at < self.buf_read
	}

	fn next_byte(&mut self) -> Option<u8> {
		if !self.refill_buffer() {
			return None;
		}
		let res = self.buf[self.at];
		self.at += 1;
		Some(res)
	}

	fn peek(&mut self) -> Option<u8> {
		if !self.refill_buffer() {
			None
		} else {
			Some(self.buf[self.at])
		}
	}

	fn skip_whitespace(&mut self) {
		while let Some(c) = self.peek() {
			if c.is_ascii_whitespace() {
				self.next_byte();
			} else {
				break;
			}
		}
	}

	fn next_token(&mut self) -> Option<Vec<u8>> {
		self.skip_whitespace();
		let mut res = Vec::new();
		while let Some(c) = self.peek() {
			if c.is_ascii_whitespace() {
				break;
			} else {
				res.push(self.next_byte().unwrap());
			}
		}
		if !res.is_empty() {
			Some(res)
		} else {
			None
		}
	}

	pub fn next_string(&mut self) -> String {
		String::from_utf8(self.next_token().unwrap()).unwrap()
	}

	pub fn i32(&mut self) -> i32 {
		self.next_string().parse().unwrap()
	}
}

fn solve(sc: &mut Scanner) {
	let a = sc.i32();
	let b = sc.i32();
	let c = sc.i32();

	let x = a - 1;
	let y = c - 1 + (b - c).abs();
	println!("{}", match x.cmp(&y) {
		Ordering::Less => 1,
		Ordering::Greater => 2,
		Ordering::Equal => 3,
	});
}

fn main() {
	let mut stdin = io::stdin();
	let mut sc = Scanner::new(&mut stdin);

	let t = sc.i32();
	for _ in 0..t {
		solve(&mut sc);
	}
	// let mut s = String::new();
	// io::stdin().read_to_string(&mut s).unwrap();
	// let mut s = s.split(|c: char| c.is_ascii_whitespace());
	// println!("{}", s.next().unwrap());
}