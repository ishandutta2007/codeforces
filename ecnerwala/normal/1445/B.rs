use std::io::{BufReader, BufWriter, stdin, stdout, BufRead, Write};

fn main() {
    let mut reader = BufReader::new(stdin());
    let mut get_line = || {
        let mut buf = String::new();
        reader.read_line(&mut buf).unwrap();
        buf
    };
    let mut writer = BufWriter::new(stdout());

    let t: usize = get_line().trim().parse().unwrap();
    for _ in 0..t {
        let a: Vec<i32> = get_line().split_whitespace().map(|a| a.parse().unwrap()).collect();
        writeln!(writer, "{}", std::cmp::max(a[0] + a[1], a[2] + a[3])).unwrap();
    }
}