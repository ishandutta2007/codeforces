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

func Max(a, b int) int {
	if a>b {
		return a
	} else {
		return b
	}
}

const N int = 100

func main() {
	var n int
	scan(&n)
	var a [N](int)
	ans := 0
	for i:=0; i<n; i++ {
		scan(&a[i])
		if i>0 && a[i]!=1 && a[i-1]!=1 {
			goto Bad
		}
		if i>1 && a[i]==2 && a[i-1]==1 && a[i-2]==3 {
			ans--
		}
		if i>0 {
			if Max(a[i],a[i-1])==2 {
				ans += 3
			} else {
				ans += 4
			}
		}
	}

	print("Finite\n")
	print(ans, "\n")
	writer.Flush()
	return

Bad:
	print("Infinite\n")
	writer.Flush()
	return
}