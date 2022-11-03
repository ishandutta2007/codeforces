use std::io::stdin;
fn check(s1: String) -> i32 {
    let mut s = String::new();
    for c in s1.chars() {
        match c {
            '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9' => {
//            '0'...'9' => {

                s.push(c);
            }
            _ => {}
        }
    }

    if s.len() > 0 {
        return s.parse::<i32>().unwrap();
    } else {
        return 0;
    }
}
fn main() {
    let mut str_buf = String::new();
    stdin().read_line(&mut str_buf);
    let n = check(str_buf);
    let mut v: Vec<i32> = Vec::new(); 
    // for i in &mut v {
    //     *i = 0;
    // }
    // for i in &v {
    //     println!("{}", i);
    // }
    // println!("Your input line is \n{}", n);
    for i in 0..n {
        let mut s = String::new();
        stdin().read_line(&mut s);
        let h = check(s[0..2].to_string());
        let m = check(s[3..5].to_string());
        // println!("{}:{}",h,m);
        v.push(h*60+m);
    }
    v.sort();
    // for i in &v {
    //     println!("{}",i);
    // }
    v.push(v[0]+24*60);
    let mut ans = 0;
    for i in 0..n {
        let x = v[(i+1) as usize];
        let y = v[i as usize];
        if ans < x - y {
            ans = x - y;
        }
    }
    ans = ans - 1;
    let h = ans / 60;
    let m = ans % 60;
    if h < 10 {
        print!("0{}:",h);
    }
    else { 
        print!("{}:",h);
    }
    if m < 10 {
        println!("0{}",m);
    }
    else { 
        println!("{}",m);
    }
}