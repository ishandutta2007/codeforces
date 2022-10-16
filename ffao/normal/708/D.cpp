#include <bits/stdc++.h>
using namespace std;
 

#define rep(i,a,n) for (int i=a;i<n;i++)
namespace mincost {
	const int V=103000,E=900000;
	const long long inf=2100000000000000000LL;
	int q[V*30],vis[V],fst[V],pre[V],nxt[E],y[E],S,T,tn;
	long long dis[V],f[E],c[E],flow,cost,tot,ret;
	void init(int s,int t,int Tn) {
		tot=1; tn=Tn;
		rep(i,0,tn) fst[i]=0;
		S=s;T=t;
		ret=0;
	}
	void add(int u,int v, long long ff,long long cc) {
		//printf("add %d %d %lld %lld\n", u,v,ff,cc);
		tot++;y[tot]=v;nxt[tot]=fst[u];f[tot]=ff;c[tot]=cc;fst[u]=tot;
		tot++;y[tot]=u;nxt[tot]=fst[v];f[tot]=0;c[tot]=-cc;fst[v]=tot;
	}
	bool spfa() {
		rep(i,0,tn) dis[i]=inf,vis[i]=0,pre[i]=0;
		dis[S]=0;q[0]=S;vis[S]=1;
		int t=1;
		rep(i,0,t) {
			int u=q[i];
			for (int j=fst[u];j;j=nxt[j]) {
				int v=y[j];
				if (f[j]&&dis[v]-c[j]>dis[u]) {
					dis[v]=dis[u]+c[j];
					pre[v]=j;
					if (!vis[v]) vis[v]=1,q[t++]=v;
				}
			}
			vis[u]=0;
		}
		return dis[T]!=inf;
	}
	void augment() {
		int p=T;
		long long _f=inf;
		while (pre[p]) _f=min(_f,f[pre[p]]),p=y[pre[p]^1];
		flow+=_f;cost+=_f*dis[T];
		ret=flow;
		p=T;
		while (pre[p]) f[pre[p]]-=_f,f[pre[p]^1]+=_f,p=y[pre[p]^1];
	}
	void solve() {
		flow=0,cost=0;
		while (spfa()) augment();
	}
}

int n, m;
int flow[110];

void solve() {
	scanf("%d %d", &n, &m);
	mincost::init(0,n+1,n+2);

	int ans = 0;
	for (int i = 0;i < m; i++) {
		int u,v,c,f;
		scanf("%d %d %d %d", &u , &v, &c, &f);

		int rollback = max(0,f-c);
		ans += rollback;
		c = max(c, f);

		flow[u] -= f;
		flow[v] += f;

		if (u == 1 && v == n) {	
			continue;
		}

		mincost::add(u, v, max(0, c-f), 1);
		mincost::add(u, v, 1000000000000LL, 2);
		
		mincost::add(v, u, rollback, 0);
		mincost::add(v, u, f-rollback, 1);
	}

	for (int i = 2; i < n; i++) {
		if (flow[i] > 0) {
			mincost::add(0,i,flow[i],0);
		}
		else {
			mincost::add(i,n+1,-flow[i],0);
		}
	}

	mincost::add(1,n,1000000000000LL,0);
	mincost::add(n,1,1000000000000LL,0);
	flow[1] = -flow[1];
	if (flow[n] > flow[1]) mincost::add(0,n,flow[n]-flow[1],0);
	if (flow[1] > flow[n]) mincost::add(1,n+1,flow[1]-flow[n],0);
	
	mincost::solve();
	printf("%lld\n", ans + mincost::cost);
}


int main() {
    solve();
}