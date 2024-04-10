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

func min(a int, b int) int {
	if a<b {
		return a
	} else {
		return b
	}
}

func max(a int, b int) int {
	if a>b {
		return a
	} else {
		return b
	}
}

func main() {
	// code GOes here

	var T int
	for scan(&T); T>0; T-- {
		var (
			cnt [26](int)
			s string
			minv int = 27
			maxv int = -1
		)
		scan(&s)
		for _, c := range s {
			cnt[c-'a'] += 1
			minv = min(minv, int(c-'a'))
			maxv = max(maxv, int(c-'a'))
		}

		if minv == maxv {
			print(s,"\n")
		} else if maxv-minv > 2 {
			last := 27
			for i:=0; i<26; i++ {
				if i%2 != minv%2 {
					if cnt[i] > 0 {
						last = i
					}
					for j:=0; j<cnt[i]; j++ {
						print(string(i+'a'))
					}
				}
			}
			if last-minv > 1 {
				for i:=0; i<26; i++ {
					if i%2 == minv%2 {
						for j:=0; j<cnt[i]; j++ {
							print(string(i+'a'))
						}
					}
				}
			} else {
				for i:=25; i>=0; i-- {
					if i%2 == minv%2 {
						for j:=0; j<cnt[i]; j++ {
							print(string(i+'a'))
						}
					}
				}
			}
			print("\n")
		} else if cnt[(minv+maxv)/2] == 0 {
			print(s, "\n")
		} else {
			print("No answer\n")
		}
	}

	writer.Flush()
	return
}