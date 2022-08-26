use std::io::stdin;
use std::cmp::min;

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

fn abs(n: i32) -> i32 {
    if n < 0 {-n} else {n}
}

fn main() {
    let mut inp = Scanner::default();
    let t = inp.read_int();
    for _i in 0..t {
        let n = inp.read_int();
        let mut curp = 0;
        let mut curt = 0;
        let mut time = 0;
        let mut ans = 0;
        let mut lastt = -1;
        for _j in 0..n {
            let t = inp.read_int();
            let x = inp.read_int();
            if lastt == curp || lastt > curp && lastt <= curt && lastt - curp <= t - time ||
                    lastt < curp && curt <= lastt && curp - lastt <= t - time {
                ans += 1;
            }
            if curt > curp {
                curp += min(curt - curp, t - time);
            } else if curt < curp {
                curp -= min(curp - curt, t - time);
            }
            if curp == curt {
                curt = x;
            }
            lastt = x;
            time = t;
        }
        if lastt >= curp && lastt <= curt || lastt <= curp && lastt >= curt {
            ans += 1;
        }
        println!("{}", ans);
    }
}