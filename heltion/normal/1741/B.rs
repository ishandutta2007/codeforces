fn read_i32() -> i32 {
    let mut line = String::new();
    std::io::stdin().read_line(&mut line);
    return line.trim().parse::<i32>().unwrap();
}
fn main() {
    for i in 0..read_i32() {
        let n = read_i32();
        if n == 1 || n == 3 {
            println!("-1");
        } else if n == 2 {
            println!("2 1");
        } else {
            print!("{} {}", n - 1, n);
            for i in 1..n - 1 {
                print!(" {}", i)
            }
            println!("");
        }
    }
}