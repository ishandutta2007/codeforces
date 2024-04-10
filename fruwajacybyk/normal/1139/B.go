package main

import (
 "bufio"
 "fmt"
 "os"
)


func main() {
	in := bufio.NewReader(os.Stdin)
	n := 0;
	fmt.Fscanf(in, "%d\n", &n);

    var slice = make([]int, 223456);
	for i:=0; i < n; i++ {
        a := 0;
        fmt.Fscanf(in, "%d", &a);
        slice[i] = a;
	}
    var ans int64 = 0;
    var cur = slice[n-1];
    ans = int64(cur);
    for i := 1; i < n; i++ {
        if cur > slice[n-1-i] {
            cur = slice[n-1-i];
        } else {
            cur = cur - 1;
        }
        if cur == -1 {
            break;
        }
        ans += int64(cur);
    }
	fmt.Println(ans);
}