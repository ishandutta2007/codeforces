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
        let n = read_i32();
        let mut a = read_i32s();
        a.sort();
        let mut ok = true;
        for i  in 0..n as usize - 1 {
            if a[i] == a[i + 1] {
                ok = false;
            }
        }
        if ok {
            println!("YES");
        } else {
            println!("NO");
        }
    }
}