use std::{str::FromStr, fmt::Debug};

fn read_line() -> String {
    let mut line = String::new();
    std::io::stdin().read_line(&mut line).expect("");
    return line;
}
fn read<T: std::str::FromStr>() -> T where <T as FromStr>::Err: Debug{
    return read_line().trim().parse::<T>().unwrap();
}
fn reads<T: std::str::FromStr>() -> Vec<T> where <T as FromStr>::Err: Debug{
    return read_line().trim().split(' ').map(|x| x.parse::<T>().unwrap()).collect();
}
fn main() {
    for _ in 0..read::<i32>() {
        let n = read::<i32>();
        let mut a = reads::<i32>();
        a.sort();
        let mut k = n;
        loop {
            let mut r = n - 1;
            let mut l = 0;
            let mut i = 1;
            while r >= l && i <= k {
                while r >= l && a[r as usize] > k - i + 1 {
                    r -= 1;
                }
                if r < l {
                    break;
                }
                r -= 1;
                l += 1;
                i += 1;
            }
            if i > k {
                println!("{}", k);
                break;
            }
            k -= 1;
        }
    }
}