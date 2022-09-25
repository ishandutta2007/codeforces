#include<bits/stdc++.h>
using namespace std;
#define N 150010
typedef long long ll;
class Union_Set{
public:
	int f[N];
	void init(int n){for(int i=1;i<=n;++i)f[i]=i;}
	inline int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
}S;
int n,Q,f[N],dep[N],md,dp[N][26],cnt[N][26],F[N];
char c[N];
vector<int> G[N],H[N];
int no;
void dfs1(int u){
	md=max(md,dep[u]);
	for(auto v:G[u]){
		dep[v]=dep[u]+1;
		dfs1(v);
	}
	if(G[u].size()==1&&u^1)S.f[u]=G[u][0];
}
void dfs2(int u,int anc){
	F[u]=anc;
	if(u^1&&S.getf(u)==u)H[anc].push_back(u);
	if(G[u].size()>1||u==1)anc=u;
	for(auto v:G[u]){
		dfs2(v,anc);
		for(int i=0;i<26;++i){
			dp[u][i]=max(dp[u][i],dp[v][i]+(c[v]-'a'==i));
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>Q;
	S.init(n);
	for(int i=2;i<=n;++i){
		cin>>f[i]>>c[i];
		G[f[i]].push_back(i);
	}
	dfs1(1);
	for(int i=1;i<=n;++i){
		if(G[i].empty()&&dep[i]^md){
			while(Q--){
				cout<<"Fou\n";
			}
			return 0;	
		}
	}
	dfs2(1,0);
	for(int i=2;i<=n;++i){
		if(c[i]^'?')++cnt[S.getf(i)][c[i]-'a'];
	}
	while(Q--){
		int x;
		cin>>x;
		if(c[x]^'?')--cnt[S.getf(x)][c[x]-'a'];
		cin>>c[x];
		if(c[x]^'?')++cnt[S.getf(x)][c[x]-'a'];
		x=S.getf(x);
		for(int u=F[x];u;u=F[u]){
			if(accumulate(dp[u],dp[u]+26,0)>md-dep[u])--no;
			memset(dp[u],0,sizeof(dp[u]));
			for(auto v:H[u]){
				for(int i=0;i<26;++i){
					dp[u][i]=max(dp[u][i],dp[v][i]+cnt[v][i]);
				}
			}
			if(accumulate(dp[u],dp[u]+26,0)>md-dep[u])++no;
		}
		if(no){
			cout<<"Fou\n";
		}
		else{
			cout<<"Shi\n";
			int tmp=md;
			for(int i=0;i<26;++i)tmp-=dp[1][i];
			int ans=0;
			for(int i=0;i<26;++i){
				ans+=(i+1)*(tmp+dp[1][i]);
			}
			cout<<ans<<'\n';
		}	
	}
	return 0;
}