#include<stdio.h>
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	int c=0;
	while(b){
		c*=10;
		c+=b%10;
		b/=10;
	}printf("%d\n",c+a);
}