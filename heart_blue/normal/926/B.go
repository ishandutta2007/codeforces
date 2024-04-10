package main

import (
	"bytes"
	"fmt"
	"io/ioutil"
	"os"
	"sort"
)

func gcd(n int, m int)(result int) {
    if m == 0 {
        return n;
    } else {
        return gcd(m, n%m);
    }
}
func main() {
    bs, _ := ioutil.ReadAll(os.Stdin)
	reader := bytes.NewBuffer(bs)
    var n int
    fmt.Fscanf(reader, "%d\n", &n)
    a := make([]int, n)
    for i:= 0; i < n; i++{
        fmt.Fscanf(reader, "%d", &a[i])
    }
    sort.Ints(a)
    var g int = 0;
    for i := 1; i < n; i++ {
        g = gcd(g, a[i] - a[i-1]);
    }
    fmt.Println((a[n-1]-a[0])/g+1-n);
}