#include <bits/stdc++.h>

using namespace std;

int a, x, y;

int main(){
	scanf("%d%d%d", &a, &x, &y);
	if(y%a == 0){
		puts("-1");
		return 0;
	}
	if(y < a){
		if(2*x < a && 2*x > -a)
			puts("1");
		else
			puts("-1");
		return 0;
	}
	if(y%(2*a) > a){
		if(2*x < a && 2*x > -a)
			printf("%d\n", (y/(2*a))*3+2);
		else
			puts("-1");
	}
	else{
		if(x < a && x > 0)
			printf("%d\n", (y/(2*a))*3+1);
		else if(x > -a && x < 0)
			printf("%d\n", (y/(2*a))*3);
		else
			puts("-1");
	}
}