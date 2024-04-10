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
        let _ = read::<i32>();
        let a = reads::<i64>();
        let b = reads::<i64>();
        println!("{}", a.iter().sum::<i64>() + b.iter().sum::<i64>() - *b.iter().max().unwrap());
    }
}