#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
#define N 200050
int head[N],to[N<<1],nxt[N<<1],cnt,n;
int even[N],odd[N];
ll ans[N],ANS,f[N],g[N];
inline void add(int u,int v) {
	to[++cnt]=v; nxt[cnt]=head[u]; head[u]=cnt;
}
void df1(int x,int y) {
	int i;
	even[x]=1;
	for(i=head[x];i;i=nxt[i]) if(to[i]!=y) {
		df1(to[i],x);
		even[x]+=odd[to[i]];
		odd[x]+=even[to[i]];
		f[x]+=g[to[i]]+even[to[i]];
		g[x]+=f[to[i]]+odd[to[i]];
	}
}
void df2(int x,int y,int CO,ll CF,int CE,ll CG) {
	int i;
	for(i=head[x];i;i=nxt[i]) if(to[i]!=y) {
		int co=even[x]-odd[to[i]],ce=odd[x]-even[to[i]];
		ll cf=g[x]-f[to[i]]-odd[to[i]]+co,
			cg=f[x]-g[to[i]]-even[to[i]]+ce;

		co+=CE;
		ce+=CO;
		cf+=CE+CG;
		cg+=CO+CF;
		ans[to[i]]=(f[to[i]]+odd[to[i]])/2+g[to[i]]/2+(cf+co)/2+cg/2;
		df2(to[i],x,co,cf,ce,cg);
	}
}
int main() {
	scanf("%d",&n);
	int i,x,y;
	for(i=1;i<n;i++) {
		scanf("%d%d",&x,&y); add(x,y); add(y,x);
	}
	df1(1,0);
	ans[1]=(f[1]+odd[1])/2+g[1]/2;
	df2(1,0,0,0,0,0);
	for(i=1;i<=n;i++) ANS+=ans[i];
	printf("%lld\n",ANS/2);
}