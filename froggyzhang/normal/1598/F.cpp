#include<bits/stdc++.h>
using namespace std;
#define N 20
typedef long long ll;
int n,dp[1<<N],dt[N],mn[N],sum[1<<N],ans;
string s[N];
unordered_map<int,int> mp[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>s[i];
	}
	for(int i=0;i<n;++i){
		int now=0;
		for(auto c:s[i]){
			now+=c=='('?1:-1;
			mn[i]=min(mn[i],now);
			if(mn[i]==now)++mp[i][now];
		}
		dt[i]=now;
	}
	for(int i=1;i<(1<<n);++i){
		sum[i]=sum[i^(i&(-i))]+dt[__builtin_ctz(i)];
	}
	memset(dp,~0x3f,sizeof(dp));
	dp[0]=0;
	for(int i=0;i<(1<<n)-1;++i){
		for(int j=0;j<n;++j){
			if(!(i>>j&1)){
				int t=i|(1<<j);
				if(sum[i]+mn[j]<0){
					ans=max(ans,dp[i]+mp[j][-sum[i]]);
				}
				else{
					dp[t]=max(dp[t],dp[i]+mp[j][-sum[i]]);
				}
			}
		}
		
	}
	for(int i=0;i<(1<<n);++i)ans=max(ans,dp[i]);
	cout<<ans<<'\n';
	return 0;
}