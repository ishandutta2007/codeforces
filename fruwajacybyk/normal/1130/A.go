package main

import (
 "fmt"
)

func main() {
    var n int = 0;
    fmt.Scan(&n);
    var plus, minus, zero int = 0,0,0;
    for n > 0 {
        var x int = 0;
        fmt.Scan(&x);
        if (x < 0) {
            minus++;
        } else if (x > 0) {
            plus++;
        } else {
            zero++;
        }
        n--;
    }
    if (plus >= minus + zero) {
        fmt.Println(1);
    } else if (minus >= plus + zero) {
        fmt.Println(-1);
    } else {
        fmt.Println(0);
    }
}