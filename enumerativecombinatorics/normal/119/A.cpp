#include<stdio.h>
int gcd(int a,int b){
	while(a){
		b%=a;
		int c=b;
		b=a;
		a=c;
	}
	return b;
}
int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	while(1){
		c-=gcd(a,c);
		if(c==0){
			printf("0\n");
			return 0;
		}
		c-=gcd(b,c);
		if(c==0){
			printf("1\n");
			return 0;
		}
	}
}