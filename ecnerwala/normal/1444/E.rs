use std::io::{stdin, stdout, BufWriter, Write};

#[derive(Default)]
struct Scanner {
    buffer: Vec<String>,
}
impl Scanner {
    fn next<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("Failed parse");
            }
            let mut input = String::new();
            stdin().read_line(&mut input).expect("Failed read");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }
}

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let n: usize = scan.next();
    let mut adj: Vec<Vec<usize>> = (0..n).map(|_| Vec::new()).collect();

    for _ in 0..n - 1 {
        let u: usize = scan.next();
        let u = u - 1;

        let v: usize = scan.next();
        let v = v - 1;

        adj[u].push(v);
        adj[v].push(u);
    }

    let mut par = vec![0 as usize; n];
    let mut bfs_q = Vec::with_capacity(n);
    bfs_q.push(0);
    for z in 0..n {
        let cur = bfs_q[z];
        adj[cur].retain(|&nxt| nxt != par[cur]);
        for &nxt in &adj[cur] {
            par[nxt] = cur;
            bfs_q.push(nxt);
        }
    }
    let bfs_q = bfs_q;

    // 1 is downwards, 0 is upwards
    let mut next_edge: Vec<[Option<usize>; 2]> = vec![[None; 2]; n];
    // edge id, value
    let mut dp: Vec<Vec<(usize, usize)>> = (0..n).map(|_| Vec::new()).collect();
    let mut sz: Vec<usize> = vec![0; n];

    for z in (0..n).rev() {
        let cur = bfs_q[z];
        sz[cur] = 1 + adj[cur].iter().map(|&nxt| sz[nxt]).sum::<usize>();

        // TODO: calculate dp[cur] and edge_val
        // We'll just calculate it naively
        let mut ch: Vec<(usize, u128)> = adj[cur].iter().map(|&nxt| {
            (nxt, dp[nxt].iter().map(|(_, z)| 1u128 << z).sum())
        }).collect();

        for hi in (0..sz[cur]).rev() {
            if ch.is_empty() {
                break;
            }

            // check if we can use this bit
            let mut has: Vec<&mut (usize, u128)> = ch.iter_mut().filter(
                |(_, msk)| (msk & (1u128 << hi)) != 0
            ).collect();
            assert!(has.len() <= 1);
            if !has.is_empty() {
                let nxt = has[0].0;
                let removed = dp[nxt].pop().unwrap();
                dp[cur].push(removed);
                has[0].1 ^= 1u128 << hi;
                continue;
            }
            drop(has);

            // check if it's satisfiable without hi
            let can_omit = || -> bool {
                let mut cur_ch = ch.clone();
                for b in (0..hi).rev() {
                    let mut has: Vec<&mut (usize, u128)> = cur_ch.iter_mut().filter(
                        |(_, msk)| (msk & (1u128 << b)) != 0
                    ).collect();
                    if has.len() >= 2 {
                        return false;
                    } else if has.len() == 1 {
                        has[0].1 ^= 1u128 << b
                    } else {
                        // remove the biggest guy
                        let a = *cur_ch.iter().max_by_key(|(_, msk)| *msk).unwrap();
                        cur_ch.retain(|&x| x != a);
                        if cur_ch.is_empty() {
                            return true
                        }
                    }
                }
                return false
            }();

            if can_omit {
                continue;
            }
            let a = *ch.iter().max_by_key(|(_, msk)| *msk).unwrap();
            ch.retain(|&x| x != a);

            let nxt = a.0;
            dp[cur].push((nxt, hi));
            for i in 1..dp[nxt].len() {
                next_edge[dp[nxt][i].0][0] = Some(dp[nxt][i-1].0);
            }
            next_edge[nxt][1] = dp[nxt].last().map(|(e,_)| *e);
        }

        dp[cur].reverse();
    }

    for i in 1..dp[0].len() {
        next_edge[dp[0][i].0][0] = Some(dp[0][i-1].0);
    }
    let mut cur = dp[0].last().unwrap().0;
    loop {
        writeln!(out, "? {} {}", par[cur]+1, cur+1).unwrap();
        out.flush().unwrap();
        let resp: usize = scan.next();
        let resp = resp-1;
        let dir = if resp == cur { 1 } else if resp == par[cur] { 0 } else { panic!() };
        match next_edge[cur][dir] {
            None => {
                writeln!(out, "! {}", resp+1).unwrap();
                break;
            },
            Some(nxt) => {
                cur = nxt;
            },
        }
    }
}