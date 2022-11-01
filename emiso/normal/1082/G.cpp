#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MAXN = 4040;
const ll INF = 10000000000000LL;

struct edge {
	ll a, b, cap, flow;
};

ll n, m, s = MAXN - 2, t = MAXN - 1, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> e;
vector<ll> g[MAXN];

void add_edge (ll a, ll b, ll cap) {
	edge e1 = { a, b, cap, 0 };
	edge e2 = { b, a, 0, 0 };
	g[a].push_back ((ll) e.size());
	e.push_back (e1);
	g[b].push_back ((ll) e.size());
	e.push_back (e2);
}

bool bfs() {
	ll qh=0, qt=0;
	q[qt++] = s;
	memset (d, -1, sizeof d);
	d[s] = 0;
	while (qh < qt && d[t] == -1) {
		ll v = q[qh++];
		for (size_t i=0; i<g[v].size(); ++i) {
			ll id = g[v][i],
				to = e[id].b;
			if (d[to] == -1 && e[id].flow < e[id].cap) {
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
		}
	}
	return d[t] != -1;
}

ll dfs (ll v, ll flow) {
	if (!flow)  return 0;
	if (v == t)  return flow;
	for (; ptr[v]<(ll)g[v].size(); ++ptr[v]) {
		ll id = g[v][ptr[v]],
			to = e[id].b;
		if (d[to] != d[v] + 1)  continue;
		ll pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
		if (pushed) {
			e[id].flow += pushed;
			e[id^1].flow -= pushed;
			return pushed;
		}
	}
	return 0;
}

ll dinic() {
	ll flow = 0;
	for (;;) {
		if (!bfs())  break;
		memset (ptr, 0, sizeof ptr);
		while (ll pushed = dfs (s, INF))
			flow += pushed;
	}

	return flow;
}

int main() {
    scanf("%lld %lld", &n, &m);
    for(ll i = 1; i <= n; i++) {
        ll x;
        scanf("%lld", &x);
        add_edge(i + m, t, x);
    }

    ll tot = 0;
    for(ll i = 1; i <= m; i++) {
        ll a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        add_edge(s, i, c);
        add_edge(i, m + a, INF);
        add_edge(i, m + b, INF);
        tot += c;
    }

    printf("%lld\n", tot - dinic());
    return 0;
}