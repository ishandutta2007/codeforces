#include<bits/stdc++.h>
using namespace std;
#define N 10005
long long i,ans,n,l,v[N],dp[N];
int main(){
	cin>>n>>l;
	for(i=1;i<=30;++i)v[i]=1e18;
	for(i=0;i<n;++i)cin>>v[i];
	for(i=1;i<30;++i)v[i]=min(v[i-1]<<1,v[i]);
	if(l&1)dp[0]=v[0];
	else dp[0]=0;
	for(i=1;i<=30;++i){
		if((l>>i)&1){
			dp[i]=min((l&-l)==(1<<i)?v[i]:(v[i]*2),dp[i-1]+v[i]);
		}
		else {
			if((l&-l)>(1<<i))dp[i]=0;
			else dp[i]=min(dp[i-1],v[i]);
		}
	}
	cout<<dp[30];
}