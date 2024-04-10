package main

import "fmt"
import "bufio"
import "os"
import "math/rand"
import "sort"

func gcd(a, b int) int {
	if b == 0 {
		return a
	} else {
		return gcd(b, a % b)
	}
}

func main() {
	var n int
	in := bufio.NewReader(os.Stdin)
	fmt.Fscan(in, &n)
	a := make([]int, n, n)
	mv, xv := 2147483647, -2147483648
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
		if a[i] < mv {
			mv = a[i]
		}
		if a[i] > xv {
			xv = a[i]
		}
	}
	for i := 0; i < n; i++ {
		j := rand.Intn(i + 1)
		a[i], a[j] = a[j], a[i]
	}
	sort.Ints(a)
	difs := 0
	for i := 1; i < n; i++ {
		difs = gcd(difs, a[i] - a[i-1])
	}
	kur := (a[n-1] - a[0]) / difs
	fmt.Println(kur - n + 1)
}