#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
#define abs(x) ((x)<0?-(x):(x))
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define N 1000000
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define eps 1e-8
using namespace std;
int n,m,q,tot,f[N],sz[N],st[N],ed[N],nt[N],p[N];
ll x,y,z,an,ans,s[N],w[N],r[N],t[N];
void lk(int x,int y,ll z){
	if(!st[x])st[x]=++tot;else nt[ed[x]]=++tot;
	ed[x]=tot;p[tot]=y;w[tot]=z;
}
void dfs(int x){sz[x]=1;
	for(int i=st[x];i;i=nt[i])if(p[i]!=f[x]){
		f[p[i]]=x;s[p[i]]=w[i];dfs(p[i]);sz[x]+=sz[p[i]];
	}
}
int main(){
	scanf("%d%d",&n,&q);
	rep(i,1,n-1){
		scanf("%I64d%I64d%I64d",&x,&y,&z);
		lk(x,y,z);lk(y,x,z);
	}dfs(1);
	for(int i=n;f[i];i=f[i])an+=s[i];ans=-an;
	if(sz[n]>2){
		rep(i,1,q)printf("%I64d\n",an);return 0;
	}t[++m]=s[n];
	for(int i=st[n];i;i=nt[i])if(p[i]!=f[n])r[1]=w[i];
	for(int i=n;f[i];i=f[i]){
		if(f[i]&&(sz[f[i]]-sz[i]>2)){
			rep(j,1,q)printf("%I64d\n",an);return 0;
		}
		t[++m]=s[f[i]];
		for(int j=st[f[i]];j;j=nt[j])
			if((p[j]!=f[f[i]])&&(p[j]!=i))r[m]=w[j];
	}x=r[1]-t[1];
	if(r[1])y=r[1]-t[1];else y=ans;
	rep(i,2,m){
		if(r[i]){if(x+r[i]>ans)ans=x+r[i];}
		else if(y>ans)ans=y;y=x;
		if(r[i]>x){
			x=r[i];if(x)y=x;
		}
		x-=t[i];y-=t[i];
	}
	rep(i,1,q){
		scanf("%I64d",&x);
		if(ans+x>0)printf("%I64d\n",an);
		else printf("%I64d\n",an+ans+x);
	}
}