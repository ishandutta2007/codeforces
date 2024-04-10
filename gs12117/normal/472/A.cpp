#include<stdio.h>
int n;
int main(){
	scanf("%d",&n);
	if(n%2==0){
		printf("%d %d",4,n-4);
	}
	else{
		printf("%d %d",9,n-9);
	}
}