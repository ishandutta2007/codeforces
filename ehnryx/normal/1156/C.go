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
	N int = int(2e5+1)
)

var (
	n int
	z int
	a [N](int)
)

func main() {
	// code GOes here

	scan(&n, &z)
	for i:=0; i<n; i++ {
		scan(&a[i])
	}
	sort.Ints(a[:n])

	valid := func(x int) bool {
		for i:=0; i<x; i++ {
			if a[n-x+i] - a[i] < z {
				return false
			}
		}
		return true
	}

	left := 0
	right := n/2
	for left < right {
		mid := (left+right+1)/2
		if valid(mid) {
			left = mid
		} else {
			right = mid-1
		}
	}
	print(left, "\n")

	writer.Flush()
	return
}