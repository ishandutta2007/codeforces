package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

func print(a ...interface{}) { fmt.Fprint(writer, a...) }
func scan(a ...interface{})  { fmt.Fscan(reader, a...) }

const (
	N int = 5e3+1
	MOD int64 = 998244353
)

var (
	n int
	a, nums [N]int
	fact, invf [N]int64
)

func inverse(x int64) (res int64) {
	res = 1
	for e:=MOD-2; e>0; e/=2 {
		if e%2 == 1 {
			res = res*x % MOD
		}
		x = x*x % MOD
	}
	return
}

func main() {
	// code GOes here

	fact[0] = 1
	invf[0] = 1
	for i:=1; i<N; i++ {
		fact[i] = int64(i)*fact[i-1] % MOD
		invf[i] = inverse(fact[i])
	}

	scan(&n)
	for i:=0; i<n; i++ {
		scan(&a[i])
	}
	sort.Ints(a[:n])

	inv := int64(1)
	pre := 0
	cnt := 1
	for i:=0; i<=n; i++ {
		if a[i] != pre {
			inv = inv * invf[cnt] % MOD
			nums[pre] = cnt
			cnt = 1
		} else {
			cnt++
		}
		pre = a[i]
	}

	ans := int64(0)
	gf := []int64 {1}
	for i:=1; i<=n; i++ {
		if nums[i] >= 2 {
			cur := int64(0)
			for j,k := range gf {
				l := n-(len(gf)-1-j)-2
				cur += fact[l] * k % MOD
			}
			cur = (cur%MOD) * int64(nums[i]*(nums[i]-1)) % MOD
			ans += cur * inv % MOD
		}
		if nums[i] > 0 {
			gf = append(gf, 0)
			for j:=len(gf)-1; j>=0; j-- {
				gf[j] = gf[j]*int64(nums[i])
				if j > 0 {
					gf[j] += gf[j-1]
				}
				gf[j] %= MOD
			}
		}
	}

	ans = (ans % MOD) * inverse(fact[n] * inv % MOD) % MOD
	print(ans, "\n")

	writer.Flush()
	return
}