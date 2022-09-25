#include<bits/stdc++.h>
using namespace std;
#define N 50050
typedef long long ll;
const int mod=998244353;
inline void add(int &x,int y){(x+=y)>=mod?x-=mod:233;}
int n,m,dp[N][1<<10];
int g[N],h[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		int x,y;
		cin>>x>>y;
		g[y]|=1<<x;
		h[x]|=1<<y;
	}
	dp[0][0]=1;
	for(int i=1;i<=n;++i){
		for(int x=0;x<1024;++x){
			int w=dp[i-1][x];
			if(!w)continue;
			for(int j=0;j<10;++j){
				if(x>>j&1)continue;
				add(dp[i][(x&h[j])|g[j]],w);
			}
		}
	}
	int ans=0;
	for(int j=0;j<1024;++j){
		add(ans,dp[n][j]);
	}
	cout<<ans<<'\n';
	return 0;
}