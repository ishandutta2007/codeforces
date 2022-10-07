#include<stdio.h>
int n;
int cp(int x){
	int i;
	for(i=2;i*i<=x;i++){
		if(x%i==0)break;
	}
	if(i*i>x)return 1;
	return 0;
}
int main(){
	int i,j;
	scanf("%d",&n);
	if(n<9){
		puts("1");
		printf("%d",n);
		return 0;
	}
	puts("3");
	for(i=6;;i+=2){
		if(cp(n-i)){
			for(j=3;i-j>=3;j+=2){
				if(cp(j)&&cp(i-j)){
					printf("%d %d %d",n-i,j,i-j);
					return 0;
				}
			}
		}
	}
}