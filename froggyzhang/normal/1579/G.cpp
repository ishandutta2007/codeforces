#include<bits/stdc++.h>
using namespace std;
#define N 2002
typedef long long ll;
int n,dp[N];
void Solve(){
	cin>>n;
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	while(n--){
		int x;
		cin>>x;
		static int g[N];
		memset(g,0x3f,sizeof(g));
		#define update(x,y) x=min(x,y)
		for(int i=0;i<=2000;++i){
			update(g[max(0,i-x)],dp[i]+x);
		}
		for(int i=0;i<=2000-x;++i){
			update(g[i+x],max(0,dp[i]-x));
		}
		memcpy(dp,g,sizeof(dp));
	}
	int ans=1e9;
	for(int i=0;i<=2000;++i){
		ans=min(ans,dp[i]+i);	
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}