fn read_line() -> String {
    let mut line = String::new();
    std::io::stdin().read_line(&mut line).expect("");
    return line;
}
fn read_i32() -> i32 {
    return read_line().trim().parse::<i32>().unwrap();
}
fn read_i32s() -> Vec<i32> {
    return read_line().trim().split(' ').map(|x| x.parse::<i32>().unwrap()).collect();
}
fn main() {
    for _ in 0..read_i32() {
        let nm = read_i32s();
        let n = nm[0];
        let m = nm[1];
        if n > m {
            println!("YES");
        }
        else {
            println!("NO");
        }
        for _ in 0..m {
            read_line();
        }
    }
}