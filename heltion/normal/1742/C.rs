fn read_i32() -> i32 {
    let mut line = String::new();
    std::io::stdin().read_line(&mut line);
    return line.trim().parse::<i32>().unwrap();
}
fn read_i32s() -> Vec<i32> {
    let mut line = String::new();
    std::io::stdin().read_line(&mut line);
    return line.trim().split(' ').map(|x| x.parse::<i32>().unwrap()).collect();
}
fn read_line() -> String {
    let mut line = String::new();
    std::io::stdin().read_line(&mut line);
    return line.trim().to_string();
}
fn main() {
    for i in 0..read_i32() {
        read_line();
        let mut ans = 'B';
        for i in 0..8 {
            if read_line() == "RRRRRRRR" {
                ans = 'R';
            }
        }
        println!("{}", ans);
    }
}