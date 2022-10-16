#include<bits/stdc++.h>
using namespace std;
#define N 1000005
int T,n,i,fl,a[N],ans,j,k,b[N],sum,res,dp[105][10005];

int main(){
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>n;ans=sum=0;
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;++i)cin>>a[i];
		for(i=1;i<=n;++i)cin>>b[i],sum+=a[i]+b[i],ans+=b[i]*b[i]*(n-2)+a[i]*a[i]*(n-2);
		dp[0][0]=1;
		for(i=0;i<n;++i){
			for(j=0;j<=100*i;++j){
				if(dp[i][j]){
					dp[i+1][j+a[i+1]]=1;
					dp[i+1][j+b[i+1]]=1;
				}
			}
		}
		res=1e9;
		for(i=0;i<=n*100;++i)if(dp[n][i])res=min(res,i*i+(sum-i)*(sum-i));
		cout<<res+ans<<"\n";
	}
}