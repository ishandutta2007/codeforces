#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
#define N 100010
typedef long long ll;
const int inf=0x3f3f3f3f;
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
vector<pair<int,pair<int,int> > > G[N];
int T,n,siz[N];
ll S;
struct Edge{
	int sz,w;
	bool operator <(const Edge b)const{
		return 1LL*w*sz-1LL*(w>>1)*sz<1LL*b.w*b.sz-1LL*(b.w>>1)*b.sz;
	}
};
inline ll calc(Edge a){
	return 1LL*a.w*a.sz-1LL*(a.w>>1)*a.sz;
}
priority_queue<Edge> q[2];
void dfs(int u,int fa){
	siz[u]=(u!=1&&(int)G[u].size()==1);
	for(auto qwq:G[u]){
		int v=qwq.first;
		if(v==fa)continue;
		dfs(v,u);
		siz[u]+=siz[v];
		S-=1LL*siz[v]*qwq.second.first;
		q[qwq.second.second-1].push({siz[v],qwq.second.first});
	}
}
void Solve(){
	n=read(),S=read();
	for(int i=1;i<=n;++i)G[i].clear();
	for(int i=1;i<n;++i){
		int u=read(),v=read(),w=read(),c=read();
		G[u].push_back(make_pair(v,make_pair(w,c)));
		G[v].push_back(make_pair(u,make_pair(w,c)));
	}
	while(!q[0].empty())q[0].pop();
	while(!q[1].empty())q[1].pop();
	dfs(1,0);
	int ans=0;
	vector<ll> t1,t2;
	if(!q[0].empty()){
		ll _S=S;
		while(_S<0){
			Edge u=q[0].top();
			q[0].pop();
			ll o=calc(u);
			if(!o)break;
			t1.push_back(o);
			u.w>>=1;
			_S+=o;
			q[0].push(u);
		}
	}
	if(!q[1].empty()){
		ll _S=S;
		while(_S<0){
			Edge u=q[1].top();
			q[1].pop();
			ll o=calc(u);
			if(!o)break;
			t2.push_back(o);
			_S+=o;
			u.w>>=1;
			q[1].push(u);
		}
	}
	int now=0;
	ans=inf;
	for(auto k:t1)S+=k,++now;
	int pos=t1.size()-1;
	if(S>=0)ans=now;
	for(auto k:t2){
		S+=k,now+=2;
		while(~pos&&S-t1[pos]>=0)S-=t1[pos],--pos,--now;
		if(S>=0)ans=min(ans,now);
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