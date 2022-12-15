package main

import (
 "bufio"
 "fmt"
 "os"
)

var mod int64 = 1000000007;
var n int = 0;
var k int = 0;
var g [][]int;
var visited = make([]int, 123456);

func pot(a int64, m int) int64 {
    if m == 0 {
        return 1;
    }
    sq := pot(a, m/2);
    sq *= sq;
    sq %= mod;
    if m % 2 == 0 {
        return sq;
    }
    return (sq * a) % mod;
}

func dfs(v int) int {
    if (visited[v] != 0) {
        return 0;
    }
    lans := 1;
    visited[v] = 1;
    for _, w := range g[v] {
        lans += dfs(w);
    }
    return lans;
}

func main() {
	in := bufio.NewReader(os.Stdin)
	fmt.Fscanf(in, "%d %d\n", &n, &k);

    g = make([][]int, n);

	for i:=0; i < n - 1; i++ {
        a,b,c := 0,0,0;
        fmt.Fscanf(in, "%d %d %d\n", &a, &b, &c);
        a--; b--;
        if c == 0 {
            g[a] = append(g[a], b);
            g[b] = append(g[b], a);
        }
	}
    ans := pot(int64(n), k);
    for i := 0; i < n; i++ {
        visited[i] = 0;
    }
    for i := 0; i < n; i++ {
        if visited[i] == 0 {
            m := dfs(i);
            ans = ans + mod - pot(int64(m), k);
            ans %= mod;
        }
    }
	fmt.Println(ans);
}