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
fn gcd(a : i32, b : i32) -> i32 {
    if b == 0 {
        return a;
    }
    return gcd(b, a % b);
}
fn main() {
    for i in 0..read_i32() {
        let n = read_i32();
        let a = read_i32s();
        let mut v = [-1i32; 1000 + 1];
        let mut ans = -1;
        for i in 0..n as usize {
            if a[i] == 1 {
                ans = std::cmp::max(ans, v[1] + i as i32 + 1);
            }
            v[a[i] as usize] = i as i32 + 1;
        }
        for i in 1..1000 + 1usize {
            for j in i..1000 + 1 {
                if gcd(i as i32, j as i32) == 1 {
                    if v[i] != -1 && v[j] != -1 {
                        ans = std::cmp::max(ans, v[i] + v[j]);
                    }
                }
            }
        }
        println!("{}", ans);
    }
}