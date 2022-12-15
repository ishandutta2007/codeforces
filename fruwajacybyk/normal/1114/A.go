package main

import (
 "fmt"
)


func main() {
    var x,y,z,a,b,c int;
    fmt.Scan(&x,&y,&z,&a,&b,&c);
		y += x; b+= a;
		z += y; c+= b;
		if a >= x && b >= y && c>=z {
			fmt.Println("YES");
		} else {
			fmt.Println("NO");
		}
}