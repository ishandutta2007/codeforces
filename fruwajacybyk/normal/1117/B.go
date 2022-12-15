package main

import (
 "bufio"
 "fmt"
 "os"
 "sort"
)


func main() {
	  in := bufio.NewReader(os.Stdin)
		n,m,k := 0,0,0;
		fmt.Fscanf(in, "%d %d %d\n", &n, &m, &k);
		k++;
		var slice = make([]int, 213456);
		for i := 0; i < n; i++ {
			x := 0;
			fmt.Fscanf(in, "%d", &x);
			slice[i] = x;
		}
		sort.Slice(slice, func(i, j int) bool { return slice[i] > slice[j]});
		var a int64 =  int64(slice[0]) * int64(m - m/k) + int64(m/k) * int64(slice[1]);
		fmt.Println(a)
}