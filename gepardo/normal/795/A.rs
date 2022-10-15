use std::io;

fn main() {
	let mut line = String::new();
	io::stdin().read_line(&mut line).unwrap();
	let tokens: Vec<&str> = line.split_whitespace().collect();
	let n: i32 = tokens[0].parse().unwrap();
	let c1: i64 = tokens[1].parse().unwrap();
	let c2: i64 = tokens[2].parse().unwrap();
	
	let mut s = String::new();
	io::stdin().read_line(&mut s).unwrap();
	let mut adults = 0;
	for c in s.chars() { 
		if (c as u8) == ('1' as u8) {
			adults += 1
		}
	}
	
	let mut res: i64 = 1234567890123456789i64;
	for groups in 1..adults+1 {
		let sml_var: i64 = ((n as i64) / (groups as i64)) - 1;
		let sml_cnt: i64 = groups - (n as i64) % (groups as i64);
		let big_var: i64 = sml_var + 1;
		let big_cnt: i64 = (n as i64) % (groups as i64);
		let cur_res: i64 = c1 * groups + 
			c2 * sml_cnt * sml_var * sml_var +
			c2 * big_cnt * big_var * big_var;
		if cur_res < res {
			res = cur_res;
		}
	}
	println!("{}", res);
}