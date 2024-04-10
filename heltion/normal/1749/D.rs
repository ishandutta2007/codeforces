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
    let modint = 998244353;
    let nm = reads::<i64>();
    let n = nm[0];
    let m = nm[1];
    let mut a = Vec::<i64>::new();
    a.resize(n as usize + 1, 0);
    let mut is_prime = Vec::<bool>::new();
    is_prime.resize(n as usize + 1, true);
    a[1] = m;
    let mut lcm = 1;
    let mut x = 0;
    let mut y = 0;
    let mut p = 1;
    for i in 2..n + 1 {
        if is_prime[i as usize] {
            let mut j = i + i;
            while j <= n {
                is_prime[j as usize] = false;
                j += i;
            }
        }
    }
    for i in 1..n + 1 {
        p = m % modint * p % modint; 
        x = (x + p) % modint;
        if is_prime[i as usize] {
            lcm = std::cmp::min(lcm * i, m + 1);
        }
        a[i as usize] = m / lcm;
    }
    for i in (1..n + 1).rev() {
        y = a[i as usize] % modint * (y + 1) % modint;
    }
    println!("{}", (x + modint - y) % modint);
}