#include<bits/stdc++.h>
using namespace std;
#define N 1000010
typedef long long ll;
const int inf=1e9;
int R,opt[N],dp[N],id[N],m,n;
vector<int> G[N];
ll ans[N];
void dfs1(int u){
	dp[u]=(!opt[u]?1:(opt[u]==1?inf:0));
	for(auto v:G[u]){
		dfs1(v);
		if(opt[u]==1)dp[u]=min(dp[u],dp[v]);
		else dp[u]+=dp[v];
	}
}
void dfs2(int u){
	if(!opt[u]){
		ans[id[u]]=1LL*dp[1]*R;
		return;
	}
	for(auto v:G[u]){
		if(opt[u]==2)dfs2(v);
		else if(dp[u]==dp[v]){dfs2(v);break;}
	}	
}
void Solve(){
	string s;
	cin>>R;
	getline(cin,s);
	n=m=0;
	static int st[N],top;
	top=0;
	for(auto c:s){
		if(c=='('){++n;if(top)G[st[top]].push_back(n);st[++top]=n;G[n].clear();}
		if(c=='*'){G[st[top]].push_back(++n);opt[n]=0;G[n].clear();id[n]=++m;}
		if(c=='S'){opt[st[top]]=1;}
		if(c=='P'){opt[st[top]]=2;}
		if(c==')'){--top;}
	}
	for(int i=1;i<=m;++i)ans[i]=0;
	dfs1(1);
	dfs2(1);
	cout<<"REVOLTING ";
	for(int i=1;i<=m;++i){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}