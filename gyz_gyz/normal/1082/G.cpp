#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 100000
#define mo 998244353
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,m,tot,t[N],p[N],nt[N];ll ans,w[N];
void init(int n){
	ans=0;tot=0;rep(i,1,n)t[i]=-1;
}
void lk(int x,int y,int z){
	nt[tot]=t[x];p[tot]=y;w[tot]=z;t[x]=tot++;
	nt[tot]=t[y];p[tot]=x;w[tot]=0;t[y]=tot++;
}
int dl[N],h[N],cur[N];
ll dfs(int n,int x,ll y){
	if(x==n)return y;ll t0=y;
	for(;~cur[x];cur[x]=nt[cur[x]])if(w[cur[x]]&&h[p[cur[x]]]>h[x]){
		ll z=dfs(n,p[cur[x]],min(w[cur[x]],y));
		w[cur[x]]-=z;w[cur[x]^1]+=z;y-=z;if(!y)break;
	}return t0-y;
}
void dinic(int n){
	for(;;){
		rep(i,1,n)h[i]=0,cur[i]=t[i];
		int s=1,ta=1;dl[1]=h[1]=1;
		for(;s<=ta;s++)for(int i=t[dl[s]];~i;i=nt[i])if(w[i]&&!h[p[i]]){
			h[p[i]]=h[dl[s]]+1;dl[++ta]=p[i];
		}
		if(!h[n])return;
		ans+=dfs(n,1,Inf);
	}
}
int main(){ll al=0;
	scanf("%d%d",&n,&m);init(n+m+2);
	rep(i,1,n){int x;
		scanf("%d",&x);
		lk(1,i+1,x);
	}
	rep(i,1,m){int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		lk(x+1,i+n+1,inf);
		lk(y+1,i+n+1,inf);
		lk(i+n+1,n+m+2,z);al+=z;
	}
	dinic(n+m+2);printf("%lld\n",al-ans);
}