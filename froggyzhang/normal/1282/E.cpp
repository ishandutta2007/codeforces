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
map<pair<int,int>,int> mp;
int n,a[N],b[N],c[N],d[N],T;
vector<tuple<int,int,int> > G[N];
vector<int> ans,poly,H[N];
set<pair<int,int> > S;
void Add(int x,int y,int u){
	if(x>y)swap(x,y);
	auto t=make_pair(x,y);
	if(mp.count(t)){
		int v=mp[t];
		G[u].emplace_back(v,x,y);
		G[v].emplace_back(u,x,y);
		++d[u],++d[v];
	}
	else mp[t]=u,S.insert(t);
}
inline void Del(int x,int y){
	auto t=make_pair(x,y);
	if(S.count(t))S.erase(t);	
}
inline void check(int x,int y){
	if(x>y)swap(x,y);
	auto t=make_pair(x,y);
	if(S.count(t))H[x].push_back(y),H[y].push_back(x);	
}
void Solve(){
	n=read();
	ans.clear(),poly.clear();
	mp.clear(),S.clear();
	for(int i=1;i<=n;++i){
		G[i].clear();
		H[i].clear();
		d[i]=0;
	}
	for(int i=1;i<=n-2;++i){
		a[i]=read(),b[i]=read(),c[i]=read();
		Add(a[i],b[i],i);
		Add(a[i],c[i],i);
		Add(b[i],c[i],i);
	}
	if(n==3){
		printf("1 2 3\n1\n");
		return;
	}
	queue<int> q;
	for(int i=1;i<=n-2;++i){
		if(d[i]==1)q.push(i);
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		ans.push_back(u);
		for(auto [v,x,y]:G[u]){
			if((--d[v])==1)q.push(v);
			Del(x,y);
		}
		check(a[u],b[u]);
		check(b[u],c[u]);
		check(a[u],c[u]);
	}
	static int vis[N];
	for(int i=1;i<=n;++i)vis[i]=0;
	for(int u=1;;){
		vis[u]=1;
		poly.push_back(u);
		for(auto v:H[u]){
			if(vis[v])continue;
			u=v;
			break;
		}
		if(vis[u])break;
	}
	for(auto x:poly)printf("%d ",x);
	printf("\n");
	for(auto x:ans)printf("%d ",x);
	printf("\n");
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}