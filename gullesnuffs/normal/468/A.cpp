#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	if(n <= 3)
		puts("NO");
	else{
		puts("YES");
		if(n%2 == 0){
			puts("1 * 2 = 2");
			puts("2 * 3 = 6");
			puts("6 * 4 = 24");
		}
		else{
			puts("4 * 5 = 20");
			puts("20 + 2 = 22");
			puts("22 + 3 = 25");
			puts("25 - 1 = 24");
		}
		for(int i=n; i >= 6; i -= 2){
			printf("%d - %d = 1\n", i, i-1);
			printf("24 * 1 = 24\n");
		}
	}
}