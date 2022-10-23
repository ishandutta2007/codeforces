fn f(s : &str) -> i32 {
    if s == "M" {
        return 0;
    }
    if &s[s.len() - 1..s.len()] == "L" {
        return s.len() as i32;
    }
    return -(s.len() as i32);
}
fn main() {
    let mut line = String::new();
    std::io::stdin().read_line(&mut line);
    let t = line.trim().parse::<i32>().unwrap();
    for i in 0..t {
        let mut line = String::new();
        std::io::stdin().read_line(&mut line);
        let s = line.trim().split(" ").collect::<Vec<_>>();
        let a = f(s[0]);
        let b = f(s[1]);
        if a < b {
            println!("<")
        } else if a == b {
            println!("=")
        } else {
            println!(">")
        }
    }
}