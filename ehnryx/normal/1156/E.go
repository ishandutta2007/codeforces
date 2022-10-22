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
	N int = 2e5+3
)

type BIT struct {
	freq [N]int
}
func (bit *BIT) insert(x int, v int) {
	for x++; x<N; x+=x&-x {
		bit.freq[x] += v
	}
}
func (bit *BIT) query(x int) int {
	res := 0
	for x++; x>0; x-=x&-x {
		res += bit.freq[x]
	}
	return res
}
func (bit *BIT) nth(n int) int {
	x := 1<<30
	for step:=x>>1; step>0; step>>=1 {
		if x-step >= N || bit.freq[x-step] >= n {
			x -= step
		} else {
			n -= bit.freq[x-step]
		}
	}
	return x-1
}

var (
	n int
	nums [N]map[int]bool
	a, s, idx, m [N]int
)

func main() {
	// code GOes here

	scan(&n)

	nums[0] = make(map[int]bool)
	for i:=1; i<=n; i++ {
		scan(&a[i])
		idx[a[i]] = i
		s[i] = a[i]
		nums[0][a[i]] = true
		m[i] = 0
	}
	sort.Sort(sort.Reverse(sort.IntSlice(s[1:n+1])))

	var bit BIT
	bit.insert(0,1)
	bit.insert(n+1,1)

	ans := 0
	id := 1
	for _,v := range s[1:n+1] {
		i := idx[v]
		rank := bit.query(i)
		left := bit.nth(rank)
		right := bit.nth(rank+1)
		bit.insert(i,1)

		nums[id] = make(map[int]bool)
		if i-left < right-i {
			for j:=left+1; j<i; j++ {
				nums[id][a[j]] = true
				nums[m[i]][a[j]] = false
				m[j] = id
			}
			for j:=left+1; j<i; j++ {
				if nums[m[i]][v-a[j]] == true {
					ans++
				}
			}
		} else {
			for j:=i+1; j<right; j++ {
				nums[id][a[j]] = true
				nums[m[i]][a[j]] = false
				m[j] = id
			}
			for j:=i+1; j<right; j++ {
				if nums[m[i]][v-a[j]] == true {
					ans++
				}
			}
		}
		id++
	}

	print(ans, "\n")
	writer.Flush()
	return
}