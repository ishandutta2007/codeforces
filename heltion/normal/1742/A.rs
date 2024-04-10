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
fn main() {
    for i in 0..read_i32() {
        let abc = read_i32s();
        let a = abc[0];
        let b = abc[1];
        let c = abc[2];
        if a == b + c || b == a + c || c == a + b {
            println!("YES")
        } else {
            println!("NO")
        }
    }
}