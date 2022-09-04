#include<stdio.h>
main(){
	long long int n;
	scanf("%I64d",&n);
	if(n==1){
	printf("1");
	return 0;
	}
	long long int min=1,max=100000000;
	while(min+1<max){
		long long int mid=(min+max)/2;
		if((mid*(mid+1))/2>n)
		max=mid;
		else if((mid*(mid+1))/2==n){
		printf("%I64d",mid);
		return 0;
		}
		else
		min=mid;
	}
	printf("%I64d",n-((min*(min+1))/2));
	return 0;
}