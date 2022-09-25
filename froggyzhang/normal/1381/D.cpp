#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,rt,dp[N],ok[N],S,T,dep[N],len,f[N];
vector<int> G[N];
void dfs1(int u,int fa){
	f[u]=fa;
	dep[u]=dep[fa]+1;
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs1(v,u);
		dp[u]=max(dp[u],dp[v]+1);	
	}	
}
inline int LCA(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	while(dep[x]>dep[y])x=f[x];
	while(f[x]^f[y])x=f[x],y=f[y];
	return x==y?x:f[x];
}
void dfs2(int u,int fw){
	vector<int> pre,suf,tmp;
	pre.resize(G[u].size());
	suf.resize(G[u].size());
	tmp.resize(G[u].size());
	for(int i=0;i<(int)G[u].size();++i){
		int v=G[u][i];
		pre[i]=suf[i]=tmp[i]=(v==f[u]?fw:dp[v]);
	}
	for(int i=1;i<(int)G[u].size();++i)pre[i]=max(pre[i],pre[i-1]);
	for(int i=(int)G[u].size()-2;i>=0;--i)suf[i]=max(suf[i],suf[i+1]);
	for(int i=0;i<(int)G[u].size();++i){
		int v=G[u][i];
		if(v==f[u])continue;
		dfs2(v,max(!i?-1:pre[i-1],v==G[u].back()?-1:suf[i+1])+1);
	}
	sort(tmp.begin(),tmp.end(),greater<int>());
	if(tmp.size()>=3&&tmp[0]>=len-1&&tmp[1]>=len-1&&tmp[2]>=len-1)ok[u]=1;
}
void dfs3(int u){
	for(auto v:G[u]){
		if(v==f[u])continue;
		f[v]=u;
		dep[v]=dep[u]+1;
		dfs3(v);
		dp[u]=max(dp[u],dp[v]+1);
	}	
}
bool Solve(){
	n=read();rt=0;S=read(),T=read();
	for(int i=1;i<=n;++i)G[i].clear(),dp[i]=dep[i]=ok[i]=0;
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs1(1,0);
	len=dep[S]+dep[T]-2*dep[LCA(S,T)];
	dfs2(1,0);
	for(int i=1;i<=n;++i){
		if(ok[i]){
			rt=i;break;
		}
	}
	if(!rt)return false;
	for(int i=1;i<=n;++i)dp[i]=0;
	f[rt]=dep[rt]=0;
	dfs3(rt);
	if(dep[S]<dep[T])swap(S,T);
	vector<int> A(1,S),B(1,T);
	int x=dep[S],y=dep[T];
	while(dep[S]>dep[T])S=f[S],A.push_back(S);
	if(S==T)return true;
	while(S^T)S=f[S],T=f[T],A.push_back(S),B.push_back(T);
	reverse(A.begin(),A.end());
	reverse(B.begin(),B.end());
	for(int i=1;i<=n;++i){
		int u=(i&1?A[x-dep[S]]:B[x-dep[S]]);
		y-=dp[u];
		x+=dp[u];
		if(y<=dep[S])return true;
		swap(x,y);
	}
	return false;
}
int main(){
	int T=read();
	while(T--)printf(Solve()?"YES\n":"NO\n");
	return 0;
}