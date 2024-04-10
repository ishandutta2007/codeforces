#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,b,a) for(int i=(b),i##_st=(a);i>=i##_st;i--)
inline int rd() {
	int x=0,c=0,f=1;
	for(; c<'0'||c>'9'; c=getchar())f=c!='-';
	for(; c>='0'&&c<='9'; c=getchar())x=x*10+c-'0';
	return f?x:-x;
}
const int N=2e5+5;
#define Es(x,i) for(Edge *i=G[x];i;i=i->nex)
struct Edge{
	int v;Edge *nex;
} pl[N<<1],*cur=pl,*G[N];
void ins(int u,int v){
	cur->v=v,cur->nex=G[u],G[u]=cur++;
}
int v[N],n,a[N],ans[N];
void dfs(int x,int dep=0,int fa=0,int now=0){
	ans[x]=now;
	for(int i=1;i*i<=a[x];i++)if(a[x]%i==0){
		if(++v[i]>=dep)ans[x]=max(ans[x],i);
		if(i*i!=a[x]&&++v[a[x]/i]>=dep)ans[x]=max(ans[x],a[x]/i);
	}
	Es(x,i)if(i->v!=fa)dfs(i->v,dep+1,x,__gcd(now,a[x]));
	for(int i=1;i*i<=a[x];i++)if(a[x]%i==0){
		--v[i];
		if(i*i!=a[x])--v[a[x]/i];
	}
}
int main(){
	n=rd();
	rep(i,1,n)a[i]=rd();
	rep(i,2,n){
		int u=rd(),v=rd();
		ins(u,v),ins(v,u);
	}
	dfs(1);
	rep(i,1,n)printf("%d%c",ans[i]," \n"[i==n]);
}