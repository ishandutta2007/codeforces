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
	var s string;
	fmt.Fscanf(in, "%s\n", &s);
	var a int64 = 0;
	for i:=0; i < n; i++ {
		if s[i] % 2 == 0  {
			a += int64(i + 1);
		}
	}
	fmt.Println(a);
}