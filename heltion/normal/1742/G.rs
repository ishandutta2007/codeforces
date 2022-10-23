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
fn read_words() -> Vec<String> {
    let mut line = String::new();
    std::io::stdin().read_line(&mut line);
    return line.trim().split(' ').map(|x| x.to_string()).collect();
}
fn gcd(a : i32, b : i32) -> i32 {
    if b == 0 {
        return a;
    }
    return gcd(b, a % b);
}
fn main() {
    for t in 0..read_i32() {
        let n = read_i32();
        let mut a = read_i32s();
        let mut or = 0;
        loop {
            let mut mx = or;
            let mut mxi = -1i32;
            for i in 0..n as usize {
                if a[i] != -1 {
                    if (or | a[i]) > mx {
                        mx = or | a[i];
                        mxi = i as i32;
                    }
                }
            }
            if mxi == -1 {
                break;
            }
            print!("{} ", a[mxi as usize]);
            a[mxi as usize] = -1;
            or = mx;
        }
        for ai in a {
            if ai != -1 {
                print!("{} ", ai);
            }
        }
        println!()
    }
}