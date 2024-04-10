package main
import "fmt"
func main() {
	var n int
	var last, sum, temp, flag int
	fmt.Scan(&n)
	last=-1;
	sum=0;
	temp=0;
	flag=0;
	for i:=1; i<=n; i++ {
		var x int
		fmt.Scan(&x)
		if(x!=last) {
			if(last==-1) {
				last=x;
			}else if(sum==0) {
				sum=temp;
				last=x;
			}else {
				if(sum!=temp) {
				    flag=1;
				}
			}
			last=x;
			temp=1;
		}else {
		temp=temp+1;
		}
	}
	if(sum!=temp&&sum!=0) {
	    flag=1;
	}
	if(flag==1) {
	    fmt.Println("NO")
	}else {
	    fmt.Println("YES")
	}
}