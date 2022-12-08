#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <set>
using namespace std;

typedef long long LL;
typedef pair<LL, int> PII;
#define MP(a, b) make_pair(a, b)

const int MAXN=100010;
const int MAXE=100010*2;

int g[MAXN], g_lnk[MAXE], g_nxt[MAXE], g_cst[MAXE];
set<LL> used[MAXN];
LL f[MAXN];
int n;

int main() {
	int m;
	scanf("%d%d", &n, &m);
	for(int i=1, e=0; i<=m; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a,&b,&c);
		g_lnk[++e]=b, g_cst[e]=c, g_nxt[e]=g[a], g[a]=e;
		g_lnk[++e]=a, g_cst[e]=c, g_nxt[e]=g[b], g[b]=e;
	}
	for(int i=1; i<=n; ++i) {
		used[i].clear();
		int cnt; scanf("%d", &cnt);
		while(cnt--) {
			int x; scanf("%d", &x);
			used[i].insert((LL)x);
		}
	}
	memset(f, 50, sizeof(f));
	LL maxval=f[0];
	f[1]=0;
	set<PII> q;
	for(int i=1; i<=n; ++i) q.insert(MP(f[i], i));
	while(q.size()>0) {
		PII cur=*q.begin();
		q.erase(q.begin());
		int x=cur.second;
		if(x==n) break;
		//if(f[x]>=maxval) continue;
		if(used[x].find(f[x])==used[x].end()) {
			for(int i=g[x]; i>0; i=g_nxt[i]) {
				int y=g_lnk[i];
				LL tmp=f[x]+g_cst[i];
				if(tmp<f[y]) {
					q.erase(q.find(MP(f[y], y)));
					f[y]=tmp;
					q.insert(MP(f[y], y));
				}
			}
		} else {
			++f[x];
			q.insert(MP(f[x], x));
		}
	}
	if(f[n]<maxval) cout<<f[n]<<endl;//printf("%d\n", f[n]);
		else printf("-1\n");
	return 0;
}