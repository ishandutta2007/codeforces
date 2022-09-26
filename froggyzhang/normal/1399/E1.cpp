#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
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
vector<pair<int,int> > G[N];
int T,n,siz[N];
ll S;
struct Edge{
	int sz,w;
	bool operator <(const Edge b)const{
		return 1LL*w*sz-1LL*(w>>1)*sz<1LL*b.w*b.sz-1LL*(b.w>>1)*b.sz;
	}
};
priority_queue<Edge> q;
void dfs(int u,int fa){
	siz[u]=(u!=1&&(int)G[u].size()==1);
	for(auto qwq:G[u]){
		int v=qwq.first;
		if(v==fa)continue;
		dfs(v,u);
		siz[u]+=siz[v];
		S-=1LL*siz[v]*qwq.second;
		q.push({siz[v],qwq.second});
	}
}
void Solve(){
	n=read(),S=read();
	for(int i=1;i<=n;++i)G[i].clear();
	for(int i=1;i<n;++i){
		int u=read(),v=read(),w=read();
		G[u].emplace_back(v,w);
		G[v].emplace_back(u,w);
	}
	while(!q.empty())q.pop();
	dfs(1,0);
	int ans=0;
	while(S<0){
		Edge u=q.top();
		q.pop();
		S+=1LL*u.w*u.sz;
		u.w>>=1;
		S-=1LL*u.w*u.sz;
		q.push(u);
		++ans;
	}
	printf("%d\n",ans);
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}