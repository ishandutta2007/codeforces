package main 

import "fmt"
import "sort"
import "bufio"
import "os"
func gcd(x int, y int) int {
	if y==0 {
	    return x
	}
	return gcd(y,x%y)
}
func main() {
    in := bufio.NewReader(os.Stdin)
	var n,dif int
	fmt.Fscan(in, &n)
	x := make([]int, n, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &x[i])
	}
	sort.Ints(x)
	dif=x[1]-x[0]
	for i := 2; i < n; i++ {
		dif=gcd(dif,x[i]-x[i-1])
	}
	fmt.Println((x[n-1]-x[0])/dif-n+1)
}