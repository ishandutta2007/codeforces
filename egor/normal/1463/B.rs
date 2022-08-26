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
        let n = inp.read_int();
        let a = inp.read_int_array(n);
        let mut b:Vec<i32> = Vec::new();
        let mut c: Vec<i32> = Vec::new();
        let mut sb = 0i64;
        let mut sc = 0i64;
        for i in 0usize..(n as usize) {
            if i % 2 == 0 {
                b.push(a[i]);
                c.push(1);
                sc += (a[i] - 1) as i64;
            } else {
                b.push(1);
                c.push(a[i]);
                sb += (a[i] - 1) as i64;
            }
        }
        if sb < sc {
            for i in b {
                print!("{} ", i);
            }
        } else {
            for i in c {
                print!("{} ", i);
            }
        }
        println!();
    }
}