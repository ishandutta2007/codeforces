#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 100050
#define mod 1000000007
typedef double f2;
typedef long long ll;
int head[N],to[N<<1],nxt[N<<1],du[N],val[N<<1],cnt,n;
ll K[N],B[N],dis[N];
inline void add(int u,int v,int w) {
	to[++cnt]=v; nxt[cnt]=head[u]; head[u]=cnt;
}
ll qp(ll x,ll y) {
	ll re=1;
	for(;y;y>>=1,x=x*x%mod) if(y&1) re=re*x%mod; return re;
}
ll INV(ll x) {return qp(x,mod-2);}
void dfs(int x,int y) {
	int i;
	if(x!=1&&du[x]==1) return ;
	K[x]=du[x]; 
	B[x]=dis[x];
	for(i=head[x];i;i=nxt[i]) if(to[i]!=y) {
		dfs(to[i],x);
		K[x]=(K[x]-INV(K[to[i]]))%mod;
		B[x]=(B[x]+B[to[i]]*INV(K[to[i]]))%mod;
	}
}
int main() {
	scanf("%d",&n);
	int i,x,y,z;
	for(i=1;i<n;i++) {
		scanf("%d%d%d",&x,&y,&z);
		x++; y++;
		add(x,y,z); add(y,x,z);
		du[x]++; du[y]++;
		dis[x]=(dis[x]+z)%mod;
		dis[y]=(dis[y]+z)%mod;
	}
	dfs(1,0);
	printf("%lld\n",(B[1]*INV(K[1])%mod+mod)%mod);
}