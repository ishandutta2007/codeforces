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
        let q = read_i32();
        let mut s = [0i64; 26];
        s[0] = 1;
        let mut t = [0i64; 26];
        t[0] = 1;
        for qi in 0..q {
            let line = read_words();
            let d = line[0].parse::<i32>().unwrap();
            let y = line[1].parse::<i64>().unwrap();
            let x = &line[2];
            for c in x.chars() {
                if d == 1 {
                    s[(c as u8 - 'a' as u8) as usize] += y;
                } else {
                    t[(c as u8 - 'a' as u8) as usize] += y;
                }
            }
            let mut ans = false;
            let mut cs = 0;
            let mut ms = 27;
            let mut ct = 0;
            let mut mt = 0;
            for i in 0..26usize {
                if s[i] > 0 {
                    cs += 1;
                    if ms == 27 {
                        ms = i;
                    }
                }
                if t[i] > 0 {
                    ct += 1;
                    mt = i;
                }
            }
            if ms < mt {
                ans = true;
            } else if cs == 1 && ct == 1 && ms == mt && s[ms] < t[mt] {
                ans = true;
            }
            if ans {
                println!("YES");
            } else {
                println!("NO");
            }
        }
    }
}