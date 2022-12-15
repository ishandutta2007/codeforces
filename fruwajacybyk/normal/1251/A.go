package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"sync"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	n := 0
	fmt.Fscanf(in, "%d\n", &n)
	res := make([][]byte, n)
	var wg sync.WaitGroup
	wg.Add(n)
	for i := 0; i < n; i++ {
		s, _ := in.ReadBytes('\n')
		go func(id int, s []byte) {
			defer wg.Done()
			mem := make(map[byte]bool)
			cnt := 0
			for j := range s {
				if j == 0 {
					cnt = 1
					continue
				}
				if s[j] != s[j-1] && cnt%2 == 1 {
					mem[s[j-1]] = true
					cnt = 1
				} else {
					cnt++
				}
			}
			for a := range mem {
				res[id] = append(res[id], a)
			}
		}(i, s)
	}
	wg.Wait()
	for _, s := range res {
		sort.Slice(s, func(i, j int) bool { return s[i] < s[j] })
		fmt.Println(string(s))
	}
}