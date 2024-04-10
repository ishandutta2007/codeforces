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
    for t in 0..read_i32() {
        let nq = read_i32s();
        let n = nq[0];
        let q = nq[1];
        let a = read_i32s();
        let mut sum = Vec::<i64>::new();
        sum.push(0);
        let mut st = Vec::<i32>::new();
        for i in 0..n as usize {
            sum.push(sum[i] + a[i] as i64);
            if st.len() == 0 || a[st[st.len() - 1] as usize] < a[i] {
                st.push(i as i32);
            }
        }
        for k in read_i32s() {
            let mut L = 0;
            let mut R = st.len();
            while L < R {
                let M = (L + R) / 2;
                if a[st[M] as usize] > k {
                    R = M;
                } else {
                    L = M + 1;
                }
            }
            if L == st.len() {
                print!("{} ", sum[n as usize]);
            } else {
                print!("{} ", sum[st[L] as usize]);
            }
        }
        println!();
    }
}