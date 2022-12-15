package main

import (
 "bufio"
 "fmt"
 "os"
)


func main() {
	  in := bufio.NewReader(os.Stdin)
    best, ile := -1,-1;
		running := 0;
		var n int;
    fmt.Fscanf(in, "%d\n", &n);
		for ;n != 0; n-- {
			var x int;
			fmt.Fscanf(in, "%d", &x);
			if x < best {
				running = 0;
			} else if x == best {
					running++;
					if running > ile {
						ile = running;
					}
			}
			if x > best {
				best = x;
				ile = 1;
				running = 1;
			}
		}
		fmt.Println(ile);
}