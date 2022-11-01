#include <iostream>
#include <cstdio>
#include <stack>
#define N 200050
#define mod 1000000007

using namespace std;

typedef long long LL;

int dfn[N],low[N],belong[N],siz[N],e[N],tme,tot,n;
bool hyy[N];
stack<int> sta;
void Tarjan(int u) {
	dfn[u] = low[u] = ++tme;
	sta.push(u);
	hyy[u] = true;
	if (dfn[ e[u] ] == 0) {
		Tarjan( e[u] );
		low[u] = min(low[ e[u] ] , low[u]);
	} else {
		if (hyy[ e[u] ]) low[u] = min( dfn[ e[u] ] , low[u] );
	}
	if (dfn[u] == low[u]) {
		++tot;
		do {
			int v = sta.top(); sta.pop();
			siz[tot]++;
			belong[v] = tot;
			hyy[v] = false;
		} while (hyy[u]);
	}
}

LL qpow(LL a,LL b) {
	if (b == 1) return a % mod;
	if (b % 2 == 0) {
		LL tmp = qpow(a,b/2);
		return ((tmp * tmp) % mod);
	} else {
		LL tmp = qpow(a,b-1);
		return (tmp * a) % mod;
	}
}

int main()
{
	LL ans = 1LL;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&e[i]);
	for (int i=1;i<=n;i++) if (!dfn[i]) Tarjan(i);
	for (int i=1;i<=tot;i++) if (siz[i] > 1) {
		LL tmp = qpow(2LL,siz[i]);
		tmp = (tmp - 2 + mod) % mod;
		ans = (ans * tmp) % mod;
	} else {
		ans = (ans * 2LL) % mod;
	}
	cout << ans << endl;
	return 0;
}