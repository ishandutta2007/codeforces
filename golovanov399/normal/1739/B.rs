use std::io;

fn nxt() -> i32 {
	let mut s = String::new();
	io::stdin().read_line(&mut s).unwrap();
	s.trim_end_matches(|c: char| c.is_ascii_whitespace()).parse().unwrap()
}

fn solve() {
	let n = nxt() as usize;
	let mut s = String::new();
	io::stdin().read_line(&mut s).unwrap();
	let a: Vec<i32> = s
			.trim_end_matches(|c: char| c.is_ascii_whitespace())
			.split(|c: char| c.is_ascii_whitespace())
			.map(&str::parse::<i32>)
			.map(|x| x.unwrap())
			.collect();
	let mut v: Vec<i32> = vec![];
	v.push(a[0]);
	for i in 1..n {
		if a[i] == 0 {
			v.push(v[i - 1]);
		} else if v[i - 1] >= a[i] {
			println!("-1");
			return;
		} else {
			v.push(v[i - 1] + a[i]);
		}
	}
	println!("{}", v.iter().map(|x| x.to_string()).collect::<Vec<String>>().join(" "));
}

fn main() {
	let t = nxt();
	for _ in 0..t {
		solve();
	}
}