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
fn read_chars() -> Vec<char> {
    return read_line().chars().collect();
}
fn main() {
    for _ in 0..read::<i32>() {
        let nm = reads::<i32>();
        let n = nm[0];
        let m = nm[1];
        let mut s = Vec::<Vec<char>>::new();
        s.resize_with(n as usize, read_chars);
        let mut qx = Vec::new();
        qx.resize((n * m * 8) as usize, 0);
        let mut qy = Vec::new();
        qy.resize((n * m * 8) as usize, 0);
        let check = |x : i32, y : i32| -> bool {
            return x >= 0 && x < n && y >= 0 && y < m;
        };
        let check_path = |x : i32, y : i32| -> bool {
            if !check(x, y) {
                return false;
            }
            if check(x - 1, y) && s[x as usize - 1][y as usize] == '#' {
                return false;
            }
            if check(x + 1, y) && s[x as usize + 1][y as usize] == '#' {
                return false;
            }
            if check(x, y - 1) && s[x as usize][y as usize - 1] == '#' {
                return false;
            }
            if check(x, y + 1) && s[x as usize][y as usize + 1 ] == '#' {
                return false;
            }
            return true;
        };
        let mut qh = (n * m * 4) as usize;
        let mut qt = (n * m * 4) as usize;
        let fm = ||{
            let mut fi = Vec::<i32>::new();
            fi.resize(m as usize, -1);
            return fi;
        };
        let mut fx = Vec::<Vec::<i32>>::new();
        fx.resize_with(n as usize, fm);
        let mut fy = Vec::<Vec::<i32>>::new();
        fy.resize_with(n as usize, fm);
        let mut d = Vec::<Vec::<i32>>::new();
        d.resize_with(n as usize, fm);
        for i in 0..n {
            if check_path(i, 0) {
                qx[qt] = i;
                qy[qt] = 0;
                qt += 1;
                fx[i as usize][0] = -2;
                fy[i as usize][0] = -2;
                d[i as usize][0] = 1;
                if s[i as usize][0] == '#' {
                    d[i as usize][0] = 0;
                }
            }
        }
        while qh < qt {
            let x = qx[qh];
            let y = qy[qh];
            qh += 1;
            for dx in [-1, 1] {
                for dy in [-1, 1] {
                    if check_path(x + dx, y + dy) {
                        let mut w = 1;
                        if s[(x + dx) as usize][(y + dy) as usize] == '#' {
                            w = 0;
                        }
                        if d[(x + dx) as usize][(y + dy) as usize] == -1 ||
                            d[(x + dx) as usize][(y + dy) as usize] > d[x as usize][y as usize] + w {
                            fx[(x + dx) as usize][(y + dy) as usize] = x;
                            fy[(x + dx) as usize][(y + dy) as usize] = y;
                            d[(x + dx) as usize][(y + dy) as usize] = d[x as usize][y as usize] + w;
                            if w == 1 {
                                qx[qt] = x + dx;
                                qy[qt] = y + dy;
                                qt += 1;
                            } else {
                                qx[qh - 1] = x + dx;
                                qy[qh - 1] = y + dy;
                                qh -= 1;
                            }
                        }
                    }
                }
            }
        }
        let mut end = -1;
        for i in 0..n {
            if fx[i as usize][m as usize - 1] != -1 {
                if end == -1 || d[i as usize][m as usize - 1] < d[end as usize][m as usize - 1] {
                    end = i;
                }
            }
        }
        if end == -1 {
            println!("NO");
            continue;
        }
        let mut x = end;
        let mut y = m - 1;
        while x != -2 {
            s[x as usize][y as usize] = '#';
            let tx = fx[x as usize][y as usize];
            let ty = fy[x as usize][y as usize];
            x = tx;
            y = ty;
        }
        println!("YES");
        for i in 0..n {
            print!("{}", s[i as usize].iter().collect::<String>());
        }
    }
}