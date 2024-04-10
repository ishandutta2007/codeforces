package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	if n % 2 == 1 {
		fmt.Print("7")
		n = n - 3
	}
	for i := 0; n > 0; i = i ^ 1 {
		fmt.Print("1")
		n = n - 2
	}
}