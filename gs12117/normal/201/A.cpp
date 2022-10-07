#include<stdio.h>
int n;
int main(){
	int i,j;
	scanf("%d",&n);
	for(i=1;;i+=2){
		if((i*i+1)/2>=n)break;
	}
	if(n==3)i+=2;
	printf("%d",i);
}