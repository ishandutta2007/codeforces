use std::io::stdin;
use std::cmp::{min, max};

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
        let b = inp.read_int_array(n);
        let mut direct = 0;
        let mut need = 0;
        let mut last = 0;
        let mut free = 0;
        for i in 0usize..(n as usize) {
            let mut cneed = b[i] - last - 1;
            if free >= cneed {
                free -= cneed;
                cneed = 0;
            } else {
                cneed -= free;
                free = 0;
            }
            need += cneed;
            if need > n - (i as i32) - 1 {
                break;
            }
            direct += 1;
            last = b[i];
            free += 1;
        }
        let mut reverse = 0;
        need = 0;
        last = 2 * n + 1;
        free = 0;
        for i in (0usize..(n as usize)).rev() {
            let mut cneed = last - b[i] - 1;
            if free >= cneed {
                free -= cneed;
                cneed = 0;
            } else {
                cneed -= free;
                free = 0;
            }
            need += cneed;
            if need > i as i32 {
                break;
            }
            reverse += 1;
            last = b[i];
            free += 1;
        }
        println!("{}", max(direct + reverse - n + 1, 0));
    }
}