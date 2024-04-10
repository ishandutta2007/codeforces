#include<stdio.h>
char a[110];
int dsq[220];
int n;
int mod=1000000007;
int ans=0;
int main(){
	int i,j,k;
	scanf("%s",a);
	for(n=0;a[n];n++);
	dsq[0]=1;
	for(i=1;i<2*n+10;i++){
		dsq[i]=dsq[i-1]*2;
		dsq[i]%=mod;
	}
	for(i=0;i<n;i++){
		if(a[i]=='1'){
			ans+=dsq[n*2-2-i];
			ans%=mod;
		}
	}
	printf("%d",ans);
}