#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
const int inf=0x3f3f3f3f;
int n,m,Q;
int dp[2][N];
unordered_set<int> s[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	int flag=0;
	if(n>m)swap(n,m),flag=1;
	cin>>Q;
	while(Q--){
		int x,y;
		cin>>x>>y;
		if(flag)swap(x,y);
		s[x].insert(y);
	}
	for(int i=1;i<=n;++i){
		dp[0][i]=-inf;	
	}
	#define update(x,y) x=max(x,y)
	dp[0][1]=1;
	for(int i=1;;++i){
		for(int j=1;j<=n;++j){
			dp[i&1][j]=-inf;	
		}
		for(int x=1;x<=n;++x){
			int y=dp[i&1^1][x];
			int w=x+y+s[x].count(y);
			if(w<1)continue;
			update(dp[i&1][min(n,w)],y);
			update(dp[i&1][x],min(m,w));
		}
		if(dp[i&1][n]==m){
			cout<<i<<'\n';
			return 0;
		}
	}
	return 0;
}