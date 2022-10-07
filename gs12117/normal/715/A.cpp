#include<stdio.h>
int n;
int main(){
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		long long int res=((long long int)i+1)*(i+1)*i-(i-1);
		if(i==1)res-=2;
		printf("%I64d\n",res);
	}
	return 0;
}