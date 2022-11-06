#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<bitset>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define N 2000000
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 998244353
#define eps 1e-8
using namespace std;
int n,m,k,tt,tot,x,y;bool c[N];ll ans,z,w[N];
int a[N],b[N],g[N],f[N],r[N],h[N],st[N],ed[N],nt[N],p[N];
void lk(int x,int y,bool z){
	if(!st[x])st[x]=++tot;else nt[ed[x]]=++tot;
	ed[x]=tot;p[tot]=y;c[tot]=z;
}
int gf(int x){
	if(g[x]==x)return x;
	g[x]=gf(g[x]);return g[x];
}
int rf(int x){
	if(r[x]==x)return x;
	r[x]=rf(r[x]);return r[x];
}
void dfs(int x){
	for(int i=st[x];i;i=nt[i])if(p[i]!=f[x]){
		if(c[i])r[p[i]]=r[x];else r[p[i]]=p[i];
		f[p[i]]=x;h[p[i]]=h[x]+1;dfs(p[i]);
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n)g[i]=i;
	rep(i,1,m){
		scanf("%d%d",&x,&y);
		lk(x,y,0);lk(y,x,0);g[gf(x)]=gf(y);
	}
	rep(i,1,k){
		scanf("%d%d%I64d",&x,&y,&z);
		if(gf(x)!=gf(y)){
			lk(x,y,1);lk(y,x,1);g[g[x]]=g[y];
		}else{
			a[++tt]=x;b[tt]=y;w[tt]=z;
		}
	}
	r[1]=1;dfs(1);
	rep(i,1,tt){
		x=rf(a[i]);y=rf(b[i]);
		while(x!=y){ans+=w[i];
			if(h[x]>h[y])x=r[x]=rf(f[x]);else y=r[y]=rf(f[y]);
		}
	}
	rep(i,1,n)if(rf(i)!=1){printf("-1");return 0;}
	printf("%I64d",ans);
}