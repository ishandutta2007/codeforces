#include<stdio.h>
int n,h;
int a[2010];
int mod=1000000007;
long long int ans;
int main(){
	int i,d;
	scanf("%d%d",&n,&h);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		a[i]=h-a[i];
	}
	ans=1;
	for(i=0;i<n+2;i++){
		if(a[i]<0)ans=0;
		if(a[i]-a[i+1]==1){
			ans*=a[i];
			ans%=mod;
		}
		else if(a[i]-a[i+1]==0){
			ans*=a[i]+1;
			ans%=mod;
		}
		else if(a[i]-a[i+1]==-1){
			ans*=1;
			ans%=mod;
		}
		else ans=0;
	}
	printf("%I64d",ans);
}