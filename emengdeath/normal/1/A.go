package main

import "fmt"
import "math"
var n, m, a int
func main() {

	fmt.Scanf("%d %d %d", &n, &m, &a)
	fmt.Println(int64(math.Ceil(float64(n) / float64(a)) * math.Ceil(float64(m) / float64(a))))
}