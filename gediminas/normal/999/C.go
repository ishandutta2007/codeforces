package main

import (
	"bufio"
	"fmt"
	"os"
	"bytes"
)

func main() {
	charCount := make(map[rune]int, 26)
	var chars []rune
	for i := 97; i <= 122; i++ {
		chars = append(chars, rune(i))
	}
	in := bufio.NewReader(os.Stdin)
	var k, n int
	var s string
    var res bytes.Buffer
	fmt.Fscan(in, &n, &k)
	fmt.Fscan(in, &s)
	for _, v := range s {
		charCount[v]++
	}
	for _, c := range chars {
		if _, ok := charCount[c]; ok && k > 0 {
			rem := Min(charCount[c], k)
			charCount[c] -= rem
			k -= rem
		}
	}
	for i := len(s); i > 0; i-- {
		if charCount[rune(s[i-1])] > 0 {
            res.WriteString(string(s[i-1]))
			charCount[rune(s[i-1])]--
		}
	}
	fmt.Println(Reverse(res.String()))
}
func Reverse(s string) string {
    runes := []rune(s)
    for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
        runes[i], runes[j] = runes[j], runes[i]
    }
    return string(runes)
}
// Min returns the smaller of x or y.
func Min(x, y int) int {
	if x > y {
		return y
	}
	return x
}