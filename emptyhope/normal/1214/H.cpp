#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
// #define int long long
using namespace std;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;

#define maxn 400005
int n,k,res[maxn];
vector<int>e[maxn];
void color(int u,int pa){
	res[u]=res[pa]^1;
	for(auto v:e[u])if(v!=pa)color(v,u);
}

bool vis[maxn];
int dis[maxn],fa[maxn],d[maxn],cnt,s,t;
void dfs(int u,int pa){
	fa[u]=pa;
	for(auto v:e[u])	
		if(v!=pa) dis[v]=dis[u]+1,dfs(v,u);
}
void find()
{
	s=t=1,dis[1]=0;dfs(1,0);
	For(i,1,n)if(dis[i]>dis[t])t=i;
	dis[t]=fa[t]=0;dfs(t,0);
	For(i,1,n)if(dis[i]>dis[s])s=i;
	int u=s;
	while(fa[u])d[++cnt]=u,vis[u]=1,u=fa[u];
	d[++cnt]=t;vis[t]=1;
}

int mx[maxn],mx2[maxn];
void getlen(int u,int pa)
{
	for(auto v:e[u]){
		if(vis[v]||v==pa)continue;
		getlen(v,u);
		if(mx[v]+1>mx[u]) mx2[u]=mx[u],mx[u]=mx[v]+1;
		else if(mx[v]+1>mx2[u]) mx2[u]=mx[v]+1;
		if(mx2[v]+1>mx2[u]) mx2[u]=mx2[v]+1;
	}
}
void color(int u,int pa,int dt)
{
	for(auto v:e[u]){
		if(vis[v]||v==pa)continue;
		res[v]=(res[u]+dt+k)%k;
		color(v,u,dt);
	}
}

signed main()
{
	n=read(),k=read();
	For(i,2,n){
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}
	if(k==2){
		puts("Yes"),color(1,0);
		For(i,1,n)cout<<res[i]+1<<' ';
		return 0;
	}
	find();
	int now=0,mid=(cnt)/2;
	For(i,1,cnt) res[d[i]]=now,now=(now+1)%k;
	For(i,1,cnt){
		int u=d[i];
		getlen(u,0);
//		cout<<u<<' '<<mx[u]<<' '<<mx2[u]<<' '<<res[u]+1<<endl;
		if(mx[u]&&dis[u]+mx[u]+1>=k && (dis[s]-dis[u]+1)+mx[u]>=k)
			return puts("No")&0;
	}
	For(u,1,n)if(mx[u]+mx2[u]+1>=k)return puts("No")&0;
	For(i,mid+1,cnt) color(d[i],0,1);
	For(i,1,mid) color(d[i],0,-1);
	puts("Yes");
	For(i,1,n)cout<<res[i]+1<<' ';
	return 0;
}