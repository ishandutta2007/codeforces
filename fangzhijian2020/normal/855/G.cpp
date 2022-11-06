#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e5;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a; 
}
int n,q,x,y,h[N+5],cnt;long long ans;
struct edge{int to,next;}e[(N<<1)+5];
void add(int x,int y){
	e[++cnt]=(edge){y,h[x]};h[x]=cnt;
}
long long del[N+5],d[N+5],size[N+5],prt[N+5],fa[N+5],s[N+5];
long long mul(int x){return 1ll*x*x;}
void dfs(int x){
	int i,y;size[x]=1;
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;if(y==prt[x])continue;
		d[y]=d[x]+1;prt[y]=x;
		dfs(y);size[x]+=size[y];
		del[x]+=mul(size[y]);
	}
	del[x]+=mul(n-size[x]);ans-=del[x];
}
int getfzj(int x){
	if(fa[x]==x)return x;
	return fa[x]=getfzj(fa[x]);
}
long long cal(int x){
	return 1ll*s[x]*(s[x]-1)*(s[x]-2)+2ll*(n-s[x])*s[x]*(s[x]-1)+1ll*s[x]*(n-s[x])*(n-s[x])-del[x]*s[x];
}
void merge(int x,int y){
	ans-=cal(x)+cal(y);fa[y]=x;s[x]+=s[y];
	del[x]+=del[y]-mul(size[y])-mul(n-size[y]);
	ans+=cal(x);
}
void solve(int x,int y){
	x=getfzj(x);y=getfzj(y);
	while(x!=y){
		if(d[x]<d[y])swap(x,y);
		merge(getfzj(prt[x]),x);
		x=getfzj(prt[x]);
	}
}
int main(){
	n=read();ans=1ll*n*(n-1)*(n-1);
	for(int i=1;i<n;++i){
		x=read();y=read();
		add(x,y);add(y,x);
	}
	dfs(1);for(int i=1;i<=n;++i)fa[i]=i,s[i]=1;
	cout<<ans<<"\n";q=read();
	for(int i=1;i<=q;++i){
		x=read();y=read();
		solve(x,y);
		cout<<ans<<"\n";
	}
	return 0;
}