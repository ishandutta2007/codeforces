package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

func print(a ...interface{}) { fmt.Fprint(writer, a...) }
func scan(a ...interface{})  { fmt.Fscan(reader, a...) }

const (
	N int = 2e5+1
)

var (
	n int
	tree [N][][2]int
	adj [N][]int
	vis [N][2]bool
	cnt [2*N]int
)

func dfs(u int, p int, c int, id int) {
	if vis[u][c] { return }
	vis[u][c] = true
	cnt[id] += 1
	adj[u] = append(adj[u], id)
	for _,e := range tree[u] {
		v,t := e[0],e[1]
		if v!=p && t==c {
			dfs(v,u,c,id)
		}
	}
}

func main() {
	// code GOes here

	scan(&n)
	for i:=1; i<n; i++ {
		var a,b,c int
		scan(&a,&b,&c)
		tree[a] = append(tree[a], [2]int{b,c})
		tree[b] = append(tree[b], [2]int{a,c})
	}

	ans := int64(0)
	id := 0
	for i:=1; i<=n; i++ {
		for c:=0; c<2; c++ {
			dfs(i,0,c,id)
			ans += int64(cnt[id])*int64(cnt[id]-1)
			id++
		}
	}

	for i:=1; i<=n; i++ {
		a,b := adj[i][0], adj[i][1]
		ans += int64(cnt[a]-1)*int64(cnt[b]-1)
	}

	print(ans, "\n")
	writer.Flush()
	return
}