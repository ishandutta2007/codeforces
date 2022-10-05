#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
#define int long long
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

#define maxn 300005
int n,a[maxn],pos[maxn],fa[maxn],res,now;
vector<int>e[maxn];

bool cmp(int x,int y){
	return a[x]<a[y];
}

int in[maxn],ed[maxn],idx,out[maxn],val[maxn],idx1,idx2;
int ppos;
void dfs(int u,int d)
{
	in[u]=++idx;
	if(a[u]>=now) val[u]=(++idx2)+now-1;
	for(auto v:e[u]) dfs(v,d+1);
	ed[u]=idx;
	out[u]=++idx1;
	if(out[u]==now) ppos=u;
	if(a[u]<now) val[u]=out[u],res+=d;
}

signed main()
{
	n=read();
	For(i,1,n)a[i]=read(),pos[a[i]]=i;
	For(i,2,n){
		int u=read(),v=read();
		e[u].pb(v); fa[v]=u;
	}
	
	now=max(1ll,a[1]-1);
	int pos_now=pos[now];
	for(int u=pos[now];u!=1;u=fa[u])
		swap(pos[a[u]],pos[a[fa[u]]]),swap(a[u],a[fa[u]]),res++;
	
	For(i,1,n) sort(e[i].begin(),e[i].end(),cmp);
	dfs(1,0);
	For(i,1,n) if(a[i]!=val[i]) return puts("NO")&0; 
	if(!(in[ppos]>=in[pos_now] && ed[ppos]<=ed[pos_now]))return puts("NO")&0;
	puts("YES");
	cout<<res<<endl;
	For(i,1,n)cout<<in[i]<<' ';
	return 0;
}