#include<bits/stdc++.h>
using namespace std;
#define N 200020
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
set<int> s;
int n,Q,p[N],f[N],dep[N],top[N],son[N],siz[N],cnt[N],vis[N];
#define int ll
ll dis[N],w[N],ans,a[N],b[N];
vector<int> G[N];
void dfs1(int u){
	siz[u]=1;
	for(auto v:G[u]){
		dep[v]=dep[u]+1;
		dfs1(v);
		siz[u]+=siz[v];
		if(!son[u]||siz[v]>siz[son[u]])son[u]=v;	
	}
}
void dfs2(int u,int topf){
	top[u]=topf;
	if(!son[u])return;
	dfs2(son[u],topf);
	for(auto v:G[u]){
		if(v^son[u])dfs2(v,v);
	}
}
int LCA(int x,int y){
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=f[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	return x;
}
inline ll Dis(int x,int y){
	return dis[x]+dis[y]-2*dis[LCA(x,y)];
}
void Insert(int x){
	auto it=s.insert(x).first;
	int l=(*--it);
	++ ++it;
	int r=(it==s.end()?0:(*it));
	ans+=Dis(l,x)+Dis(x,r)-Dis(l,r);
}
void Del(int x){
	auto it=s.find(x);
	int l=(*--it);
	++ ++it;
	int r=(it==s.end()?0:(*it));
	ans-=Dis(l,x)+Dis(x,r)-Dis(l,r);
	s.erase(x);
}
signed main(){
	n=read(),Q=read();
	for(int i=1;i<=n;++i){
		p[i]=read();
	}
	for(int i=1;i<=n;++i){
		static int st[N],top;
		while(top&&p[i]>p[st[top]])--top;
		f[i]=st[top];
		G[f[i]].push_back(i);
		st[++top]=i;
	}
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=n;++i)b[i]=read();
	for(int i=1;i<=n;++i){
		w[i]+=a[i]-b[i];
		w[f[i]]+=b[i];
	}
	dfs1(0);
	dfs2(0,0);
	for(int i=n;i>=1;--i){
		dis[i]+=w[i];
		dis[f[i]]+=min(0LL,dis[i]);
		dis[i]-=min(0LL,dis[i]);
	}
	dis[0]+=w[0];
	for(int i=1;i<=n;++i){
		dis[i]+=dis[f[i]];
	}
	++cnt[0];
	s.insert(0);
	while(Q--){
		int x=read();
		if(vis[x]){
			vis[x]=0;
			if(!--cnt[f[x]])Del(f[x]);
		}
		else{
			vis[x]=1;
			if(!cnt[f[x]]++)Insert(f[x]);
		}
		printf("%lld\n",(ans/2)+dis[0]);
	}
	return 0;
}