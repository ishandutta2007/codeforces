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
	res := make([][]byte, q)
	var wg sync.WaitGroup
	wg.Add(q)
	for i := 0; i < q; i++ {
		s, _ := in.ReadBytes('\n')
		s = s[:len(s)-2]
		go func(id int, str []byte) {
			defer wg.Done()
			odds, evens := []byte{}, []byte{}
			for _, c := range str {
				if c%2 == 0 {
					odds = append(odds, c)
				} else {
					evens = append(evens, c)
				}
			}
			a, b := 0, 0
			for a < len(odds) && b < len(evens) {
				if odds[a] < evens[b] {
					res[id] = append(res[id], odds[a])
					a++
				} else {
					res[id] = append(res[id], evens[b])
					b++
				}
			}
			res[id] = append(res[id], odds[a:]...)
			res[id] = append(res[id], evens[b:]...)
		}(i, s)
	}
	wg.Wait()
	for _, s := range res {
		fmt.Println(string(s))
	}
}