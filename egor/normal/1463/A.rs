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

    fn read_int_array(&mut self, n: i32) -> Vec<i32> {
        let mut res = Vec::new();
        for _i in 0..n {
            res.push(self.read_int());
        }
        res
    }
}

fn main() {
    let mut inp = Scanner::default();
    let t = inp.read_int();
    for _i in 0..t {
        let a = inp.read_int();
        let b = inp.read_int();
        let c = inp.read_int();
        let sum = a + b + c;
        if sum % 9 == 0 && sum / 9 <= a && sum / 9 <= b && sum / 9 <= c {
            println!("YES");
        } else {
            println!("NO");
        }
    }
}