#include<stdio.h>
int main(){
	int a;
	scanf("%d",&a);
	int now=0;
	for(int i=0;i<a-1;i++){
		now+=(i+1);
		now%=a;
		printf("%d ",now+1);
	}
}