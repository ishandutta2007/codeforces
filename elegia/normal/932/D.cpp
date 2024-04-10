#include <cstdio>

using namespace std;

typedef long long ll;

const int N = 400010, LGN = 20, LGN1 = LGN - 1;

int wt[N];
int prt[N][LGN];
ll sum[N][LGN];

void change(int u, int v, int w);
int query(int u, ll x);

int main() {
	ll last = 0;
	int n, cnt = 1;
	scanf("%d", &n);
	while (n--) {
		int opt;
		ll p, q;
		scanf("%d%lld%lld", &opt, &p, &q);
		p ^= last;
		q ^= last;
		if (opt == 1)
			change(++cnt, p, q);
		else
			printf("%lld\n", last = query(p, q));
	}
	return 0;
}

void change(int u, int v, int w) {
	wt[u] = w;
	for (int i = LGN1; i >= 0; --i)
		if (wt[prt[v][i]] < w && prt[v][i] != 0)
			v = prt[v][i];
	if (wt[prt[v][0]] >= w && wt[v] < w && prt[v][0] != 0)
		v = prt[v][0];
	if (wt[v] >= w)
		prt[u][0] = v;
	sum[u][0] = w;
	for (int i = 1; i < LGN; ++i) {
		prt[u][i] = prt[prt[u][i - 1]][i - 1];
		sum[u][i] = sum[u][i - 1] + sum[prt[u][i - 1]][i - 1];
	}
}

int query(int u, ll x) {
	int ret = 0;
	for (int i = LGN1; i >= 0; --i)
		if (prt[u][i] != 0 && sum[u][i] <= x) {
			x -= sum[u][i];
			u = prt[u][i];
			ret += 1 << i;
		}
	if (wt[u] <= x)
		++ret;
	return ret;
}