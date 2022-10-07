#include<stdio.h>
int n;
int main(){
	int i;
	scanf("%d",&n);
	if(n<4){
		puts("NO");
		return 0;
	}
	if(n>=8){
		puts("YES");
		puts("6 - 5 = 1");
		puts("8 - 7 = 1");
		puts("1 - 1 = 0");
		for(i=9;i<=n;i++){
			printf("%d * 0 = 0\n",i);
		}
		puts("1 * 2 = 2");
		puts("2 * 3 = 6");
		puts("6 * 4 = 24");
		puts("24 + 0 = 24");
	}
	if(n==4){
		puts("YES");
		puts("1 * 2 = 2");
		puts("2 * 3 = 6");
		puts("6 * 4 = 24");
	}
	if(n==6){
		puts("YES");
		puts("1 * 2 = 2");
		puts("2 * 3 = 6");
		puts("6 * 4 = 24");
		puts("6 - 5 = 1");
		puts("24 * 1 = 24");
	}
	if(n==5){
		puts("YES");
		puts("3 * 4 = 12");
		puts("5 - 1 = 4");
		puts("4 - 2 = 2");
		puts("12 * 2 = 24");
	}
	if(n==7){
		puts("YES");
		puts("3 * 4 = 12");
		puts("5 - 1 = 4");
		puts("4 - 2 = 2");
		puts("12 * 2 = 24");
		puts("7 - 6 = 1");
		puts("24 * 1 = 24");
	}
}