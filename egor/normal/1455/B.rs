use std::io::stdin;

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

    fn read_int(&mut self) -> i32 {
        self.next::<i32>()
    }

    fn read_string(&mut self) -> String {
        self.next::<String>()
    }
}

fn main() {
    let mut inp = Scanner::default();
    let t = inp.read_int();
    for _i in 0..t {
        let x = inp.read_int();
        let mut y = 0;
        let mut k = 1;
        while y < x {
            y += k;
            k += 1;
        }
        println!("{}", if y == x + 1 {k} else {k - 1});
    }
}