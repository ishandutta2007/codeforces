#pragma GCC optimize(2)
#include<bits/stdc++.h> 
using namespace std;
#define N 5005
int n,l,r,q,len,ii,j,rr,k,ans,i,x,v[N<<1],a[N],dp[N][N];
int main(){
	cin>>n;
	for(i=1;i<=n;++i)cin>>a[i],dp[i][i]=a[i];
	for(ii=1;ii<=n;++ii){
		for(j=ii;j<=n;++j)v[j-ii]=a[j];
		x=n-ii;
		for(i=1;i<=x;i<<=1)
			for(rr=i<<1,j=0;j<=x;j+=rr)
				for(k=0;k<i;++k)v[j|k|i]^=v[j|k];
		for(i=1;i<=x;++i)dp[ii][i+ii]=v[i];
	}
	for(i=1;i<n;++i)
		for(j=1;j<=n-i;++j)
			dp[j][j+i]=max(dp[j][j+i],max(dp[j][j+i-1],dp[j+1][j+i]));
	cin>>q;
	while(q--){
		cin>>l>>r;
		cout<<dp[l][r]<<"\n";
	}
}