use std::io;

fn read_int() -> i32 {
    let mut s: String = String::new();
    io::stdin().read_line(&mut s).expect("Failed to read line");

    let result: i32 = s.trim().parse().expect("Expected a number");
    return result;
}

fn main() {
    let t = read_int();

    for _ in 0..t {
        let p = read_int();
        let mut done = false;
        let q = p+1;
        for b in 2..q {
            if done {
                break;
            }
            for a in 2..b {
                if p % a == p % b {
                    println!("{} {}", a, b);
                    done = true;
                    break;
                }
            }
        }
    }
}