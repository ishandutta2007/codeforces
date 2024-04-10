#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <climits>
#define For(i,x,y)  for(int i=x;i<=y;i++)
#define Forn(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
typedef long long LL;
typedef double db;

struct e{
	int u,v,pre;
	e(int u=0,int v=0,int p=0):u(u),v(v),pre(p) {}
}edge[100005];int adj[100005],dex,n,st[100005],ed[100005],cnt;
int dep[100005],root[100005];
int lc[7000005],rc[7000005],sum[7000005],tot;
int fa[100005][21];

inline void setIO(string a){
#ifndef ONLINE_JUDGE
	string in=a+".in",out=a+".out";
	freopen(in.c_str(),"r",stdin);
	freopen(out.c_str(),"w",stdout);
#endif
}

inline void dfs(int x){
	st[x]=++cnt;
	for(int i=adj[x];i;i=edge[i].pre){
		int v=edge[i].v;
		dep[v]=dep[x]+1;
		fa[v][0]=x;
		For(i,1,20) fa[v][i]=fa[fa[v][i-1]][i-1];
		dfs(v);
	}ed[x]=cnt;
}

int x,v;

void add(int &x,int L,int R){
	if(!x) x=++tot;
	if(L==R){
		sum[x]++;
		return;
	}
	int md=(L+R)>>1;
	if(v<=md)add(lc[x],L,md);else
	add(rc[x],md+1,R);
	*sum=0;
	sum[x]=sum[lc[x]]+sum[rc[x]];
}

inline void add(int _x,int _v){
	x=_x;v=_v;
	add(root[x],1,n);
}

int Lv,Rv;

int ask(int x,int L,int R){
	if(Lv<=L && R<=Rv) return sum[x];
	int md=(L+R)>>1;
	int Ans=0;
	if(Lv<=md) Ans+=ask(lc[x],L,md);
	if(md<Rv)   Ans+=ask(rc[x],md+1,R);
	return Ans;
}

int ask(int x){
	return ask(root[x],1,n);
}

int Fa(int x,int y){
	Forn(i,20,0)
	if((1<<i)<=y) x=fa[x][i],y-=1<<i; 
	return x;
}

int Q;
int main(){
	scanf("%d",&n);++n;
	For(i,2,n){
		int x;
		scanf("%d",&x);++x;
		edge[++dex]=e(x,i,adj[x]);adj[x]=dex;
	}dep[1]=1;dfs(1);
	For(i,1,n){
		add(dep[i],st[i]);
	}scanf("%d",&Q);
	For(i,1,Q){
		int x,y;
		scanf("%d%d",&x,&y);++x;
		int p=Fa(x,y);
		if(p<=1){
			printf("0\n");
			continue;
		}
		Lv=st[p];Rv=ed[p];
		int Ans=ask(dep[x])-1;
		printf("%d\n",Ans);
	}
	return 0;
}