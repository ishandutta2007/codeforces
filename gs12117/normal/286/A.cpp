#include<stdio.h>
int n;
int main(){
	int i;
	scanf("%d",&n);
	if(n%4==2||n%4==3){
		printf("-1");
		return 0;
	}
	for(i=0;i<n/2;i++){
		if(i%2==0){
			printf("%d ",i+2);
		}
		else{
			printf("%d ",n-i+1);
		}
	}
	if(n%4==1){
		printf("%d ",n/2+1);
	}
	for(i=n/2-2;i>-2;i-=2){
			printf("%d %d ",i+1,n-i-1);
	}
	return 0;
}