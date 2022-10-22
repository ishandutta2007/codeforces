use std::io;

fn read_string() -> String {
    let mut s: String = String::new();
    io::stdin().read_line(&mut s).expect("Failed to read line");
    s.trim().to_string()
}

fn read_int() -> i32 {
    read_string().parse().expect("Expected a number")
}

fn main() {
    let t = read_int();

    for _ in 0..t {
        read_int();
        let mut enemy_row = read_string();
        let my_row = read_string();
        let enemy_row = unsafe {enemy_row.as_bytes_mut()};
        let my_row = my_row.as_bytes();
        let mut ans = 0;
        for j in 0usize..my_row.len() {
            if my_row[j] == b'0' {
                continue;
            }
            if j > 0 && enemy_row[j-1] == b'1' {
                ans += 1;
                enemy_row[j-1] = b'0';
            } else if enemy_row[j] == b'0' {
                ans += 1;
            } else if j+1 < enemy_row.len() && enemy_row[j+1] == b'1' {
                ans += 1;
                enemy_row[j+1] = b'2';
            }
        }
        println!("{}", ans);
    }
}