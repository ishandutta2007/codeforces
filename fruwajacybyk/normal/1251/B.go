package main

import (
	"bufio"
	"fmt"
	"os"
	"sync"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	q := 0
	fmt.Fscanf(in, "%d\n", &q)
	res := make([]int, q)
	var wg sync.WaitGroup
	wg.Add(q)
	for i := 0; i < q; i++ {
		n := 0
		fmt.Fscanf(in, "%d\n", &n)
		strs := make([][]byte, n)
		allEven := true
		zeros, ones := 0, 0
		for _, s := range strs {
			s, _ = in.ReadBytes('\n')
			if len(s)%2 == 1 {
				allEven = false
			}
			for _, c := range s {
				if c == '0' {
					zeros++
				}
				if c == '1' {
					ones++
				}
			}
		}
		go func(id int, z, o int, ae bool, en int) {
		  	defer wg.Done()
			if ae && z%2 == 1 {
				res[id] = en - 1
			} else {
				res[id] = en
			}
		}(i, zeros, ones, allEven, n)
	}
	wg.Wait()
	for _, s := range res {
		fmt.Println(s)
	}
}