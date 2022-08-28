#include <ctime>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long ll;

struct Edge {
	int v;
	ll w;
	Edge* next;
};

const int N = 400010;

int n, cnt;
Edge* g[N];
unordered_map<ll, int> row, col;
ll lim[N];

void addEdge(int u, int v, ll w);
ll gcd(ll a, ll b);

int main() {
	scanf("%d", &n);
	for (int rep = 1; rep <= n; ++rep) {
		ll w, h, c;
		scanf("%I64d%I64d%I64d", &w, &h, &c);
		if (!row[w])
			row[w] = ++cnt;
		if (!col[h])
			col[h] = ++cnt;
		int u = row[w], v = col[h];
		addEdge(u, v, c);
		lim[v] = gcd(lim[v], c);
	}
	if (row.size() * (ll)col.size() != n) {
		puts("0");
		return 0;
	}
	ll lcm = 1, rgg = 0;
	for (Edge* p = g[1]; p; p = p->next) {
		ll gg = gcd(lcm, p->w / lim[p->v]);
		if (((double)(lcm / gg) * (p->w / lim[p->v])) > 1e12) {
			puts("0");
			return 0;
		}
		lcm *= p->w / lim[p->v] / gg;
		rgg = gcd(rgg, p->w);
	}
	if (rgg % lcm != 0) {
		puts("0");
		return 0;
	}
	rgg /= lcm;
	int ans = 0;
	ll x;
	for (x = 1; x * x < rgg; ++x)
		if (rgg % x == 0)
			ans += 2;
	if (x * x == rgg)
		++ans;
	printf("%d\n", ans);
	return 0;
}

ll gcd(ll a, ll b) {
	if (!b)
		return a;
	return gcd(b, a % b);
}

void addEdge(int u, int v, ll w) {
	static Edge pool[N];
	static Edge* p = pool;
	p->v = v;
	p->w = w;
	p->next = g[u];
	g[u] = p;
	++p;
}