#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 200020

ll n, m, k;
int rnk[MN], pai[MN];
long double mid;

struct edge {
	long long c;
	int u, v, id;
	bool operator < (const edge &o) const {
		long double c1 = c, co1 = o.c;
		if(u == 1) c1 += mid + (id+1)*(1e-6);
		if(o.u == 1) co1 += mid + (o.id+1)*(1e-6);
		return c1 < co1;
	}
};

vector<edge> edges, ans;

int read(int x) {
	if(x == pai[x]) return x;
	return pai[x] = read(pai[x]);
}

int join(int a, int b) {
	a = read(a), b = read(b);
	if(a == b) return false;
	if(rnk[a] < rnk[b]) swap(a, b);
	pai[b] = a;
	if(rnk[a] == rnk[b]) rnk[a]++;
	return true;
}

int main() {
	scanf("%lld %lld %lld", &n, &m, &k);
	for(int i = 0; i < m; i++) {
		int a, b;
		long long c = 0;
		scanf("%d %d", &a, &b);
		if(a > b) swap(a, b);
		edges.push_back({c, a, b, i});
	}

	long double l = -1, r = 1;
	for(int it = 50; it; it--) {
		mid = (l + r)/2;

		sort(edges.begin(), edges.end());
		ans.clear();

		for(int i = 0; i < MN; i++) {
			pai[i] = i;
			rnk[i] = 0;
		}

		int spec = 0, tot = 0;

		long long cost = 0;
		for(edge ed : edges) {
			if(join(ed.u, ed.v)) {
				tot++;
				if(ed.u == 1) spec++;
				ans.push_back(ed);
			}
		}

		if(tot != n-1) {
			puts("NO");
			return 0;
		}

		if(spec == k) {
			puts("YES");
			for(edge e : ans) printf("%d %d\n", e.u, e.v);
			return 0;
		} else if(spec > k) {
			l = mid;
		} else {
			r = mid;
		}
	}

	printf("NO\n");
	return 0;
}