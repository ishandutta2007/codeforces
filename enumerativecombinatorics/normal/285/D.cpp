#include<stdio.h>
int magic[]={1,0, 3,0, 15,0, 133,0, 2025,0, 37851,0, 1030367,0, 36362925,0, 1606008513,0};
int main(){
	int a;
	int mod=1000000007;
	scanf("%d",&a);
	long long ret=magic[a-1];
	for(int i=1;i<=a;i++){
		ret=ret*i%mod;
	}
	printf("%d\n",(int)ret);
}