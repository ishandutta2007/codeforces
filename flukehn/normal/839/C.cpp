#include<bits/stdc++.h>
using namespace std;
#define debug(x) std::cerr << #x << " = " << x << std::endl
#define FOR(i,s,t) for(int i=s;i<=t;i++)
#define FEO(x) {freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);}
inline int rd() {
	int x=0,c=0,f=1;
	for(; c<'0'||c>'9'; c=getchar())f=c!='-';
	for(; c>='0'&&c<='9'; c=getchar())x=x*10+c-'0';
	return f?x:-x;
}
const int N=100011;
struct Edge{
	int v;
	Edge *nex;
}pool[2*N],*cur=pool,*G[N];
void ins(int u,int v){
	cur->v=v;
	cur->nex=G[u],G[u]=cur++;
}
int n,dep[N],in[N];
long double ans;
void dfs(int x,int fa=0,long double tmp=1){
	dep[x]=dep[fa]+1;
	if(in[x]==1&&x!=1)ans+=(long double)dep[x]/tmp;
	if(x==1)tmp*=in[1];
	else tmp*=(in[x]-1);
	for(Edge *i=G[x];i;i=i->nex)if(i->v!=fa){
		dfs(i->v,x,tmp);
	}
}
int main() {
	n=rd(),dep[0]=-1;
	for(int i=1;i<n;i++){
		int u=rd(),v=rd();
		ins(u,v),ins(v,u);
		in[u]++,in[v]++;
	}
	dfs(1);
	printf("%.10Lf\n",ans);
}