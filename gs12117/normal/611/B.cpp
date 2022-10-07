#include<stdio.h>
int f(long long int x){
	int res=0;
	int i,j;
	for(i=0;i<62;i++){
		for(j=0;j<i-1;j++){
			if(((1LL)<<i)-1-((1LL)<<j)<=x){
				res++;
			}
		}
	}
	return res;
}
int main(){
	long long int a,b;
	scanf("%I64d%I64d",&a,&b);
	printf("%d",f(b)-f(a-1));
	return 0;
}