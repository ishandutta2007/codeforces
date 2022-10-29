#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,m;
vector<vi> vis,dp1,dp2;
vector<string> s;
int dfs1(int x,int y){
	if(x==n-1 and y==m-1) return 1;
	if(dp1[x][y]!=-1) return dp1[x][y];
	if(x+1<n and s[x+1][y]!='#' and dfs1(x+1,y)){
		vis[x][y]++;
		return dp1[x][y]=1;
	}
	if(y+1<m and s[x][y+1]!='#' and dfs1(x,y+1)){
		vis[x][y]++;
		return dp1[x][y+1]=1;
	}
	return dp1[x][y]=0;
}
int dfs2(int x,int y){
	if(x==n-1 and y==m-1) return 1;
	if(dp2[x][y]!=-1) return dp2[x][y];
	if(y+1<m and s[x][y+1]!='#' and dfs2(x,y+1)){
		vis[x][y]++;
		return dp2[x][y+1]=1;
	}
	if(x+1<n and s[x+1][y]!='#' and dfs2(x+1,y)){
		vis[x][y]++;
		return dp2[x][y]=1;
	}
	return dp2[x][y]=0;
}
void solve(){
	cin>>n>>m;
	s.resize(n);
	vis.resize(n);
	dp1.resize(n);
	dp2.resize(n);
	rep(i,0,n) cin>>s[i];
	rep(i,0,n) vis[i].resize(m),dp1[i].resize(m),dp2[i].resize(m);
	rep(i,0,n){
		rep(j,0,m){
			dp1[i][j]=dp2[i][j]=-1;
		}
	}
	if(dfs1(0,0)==0){
		cout<<0<<endl;
		return;
	}
	dfs2(0,0);
	rep(i,0,n){
		rep(j,0,m){
			if(i==0 and j==0) continue;
			if(i==n-1 and j==m-1) continue;
			if(vis[i][j]==2){
				cout<<1<<endl;
				return;
			}
		}
	}
	cout<<2<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
    // cin>>t;
	while(t--){
		solve();
	}
	return 0;
}