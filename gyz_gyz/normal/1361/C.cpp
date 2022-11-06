#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
const int N=2e6+10;
const int inf=1e9;
const int mo=998244353;
int tot,al,w[N],r[N],st[N],nt[N],p[N],f[N],e1[N],e2[N],d[N],id[N];bool v[N];
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
void lk(int x,int y,int ID){
	++tot;nt[tot]=st[x];st[x]=tot;p[tot]=y;id[tot]=ID*2-1;
	++tot;nt[tot]=st[y];st[y]=tot;p[tot]=x;id[tot]=ID*2;
}
int dfs(int x){
	int l0=al,r0=al;
	while(~st[x]){int e=st[x];
		if(v[e]){
			st[x]=nt[e];continue;
		}
		w[++al]=e;
		v[e]=v[e^1]=1;st[x]=nt[e];
		int l1=al;
		int r1=dfs(p[e]);
		if(!r[l0])r0=r1;
		r[r1]=r[l0];r[l0]=l1;
	}
	return r0;
}
int main(){int n,m,ans=0;
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d",&e1[i],&e2[i]);
	dep(i,20,0){m=(1<<i)-1;
		rep(j,0,m)f[j]=j,d[j]=0;
		rep(j,1,n){
			int x=e1[j]&m,y=e2[j]&m;
			++d[x];++d[y];
			if(gf(x)!=gf(y))f[gf(x)]=f[gf(y)];
		}int cnt=0;bool fl=0;
		rep(j,0,m){
			if(d[j]&1)fl=1;
			if(d[j]&&gf(j)==j)++cnt;
		}
		if(!fl&&cnt==1){
			ans=i;break;
		}
	}
	printf("%d\n",ans);
	rep(i,0,m)st[i]=-1;tot=-1;
	rep(i,1,n)lk(e1[i]&m,e2[i]&m,i);
	dfs(e1[1]&m);
	for(int i=r[0];i;i=r[i])printf("%d %d ",id[w[i]],id[w[i]^1]);
}