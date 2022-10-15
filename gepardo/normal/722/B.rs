use std::io;

fn main() {
	let mut line = String::new();
	io::stdin().read_line(&mut line).unwrap();
	let tokens: Vec<&str> = line.split_whitespace().collect();
	let n = tokens[0].parse().unwrap();

	let mut line = String::new();
	io::stdin().read_line(&mut line).unwrap();
	let tokens: Vec<&str> = line.split_whitespace().collect();

	let mut v: Vec<i32> = vec![0; n];
	for i in 0..n {
		v[i] = tokens[i].parse().unwrap();
	}

	let mut yes: bool = true;
	for i in 0..n {
		let mut line = String::new();
		let mut cnt: i32 = 0;
		io::stdin().read_line(&mut line).unwrap();
		for c in line.chars() {
			if c == 'a' || c == 'e' || c == 'i' ||
			   c == 'o' || c == 'u' || c == 'y' {
			   		cnt += 1;
			   } 
		}
		if cnt != v[i] {
			yes = false;
			break;
		}
	}

	println!("{}", if yes {"YES"} else {"NO"});
}