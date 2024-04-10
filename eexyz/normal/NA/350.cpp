#include<bits/stdc++.h>
using namespace std;
int dp[2][1<<22],x,ans,y,X,gg,nn,nxt,f[100],cnt,tmp,u,v,n,i,f1,f2;
int main(){
	cin>>nn>>x>>y;X=x+y;
	dp[0][0]=1;
	gg=(1<<max(x,y))-1;
	--x;--y;
	for(n=1;n<=X;++n){
		nxt=tmp^1;
		for(i=0;i<=gg;++i){
			if(dp[tmp][i]){
				if(!(((i>>x)|(i>>y))&1))dp[nxt][(i<<1|1)&gg]=max(dp[nxt][(i<<1|1)&gg],dp[tmp][i]+(nn/X+(n<=nn%X)));
				dp[nxt][(i<<1)&gg]=max(dp[nxt][(i<<1)&gg],dp[tmp][i]);
			}
		}
		tmp=nxt;
		if(n==X){
			for(i=0;i<=gg;++i){
				ans=max(ans,dp[nxt][i]);
			}
		}
	}
	cout<<ans-1;
}