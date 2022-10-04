#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 5e5 + 7;

vector <vector <pair <int, int>>> ed;

const int md = 1e9 + 7;

inline int sub(int a, int b) {
	a -= b;
	if (a < 0) a += md;
	return a;
}

inline void add(int &a, int b) {
 	a += b;
	if (a >= md) a -= md;
}

inline int mul(int a, int b) {
	return (int) ((long long) a * b % md);
}

inline int power(int a, long long b) {
	int res = 1;
	while (b > 0) {
	if (b & 1) {
	  res = mul(res, a);
	}
	a = mul(a, a);
	b >>= 1;
	}
	return res;
}

int p[N];
int sz[N];

int get(int a) {
	if (a == p[a]) return a;
	return p[a] = get(p[a]);
}

vector <int> cg;

int cnt;

void merge(int a, int b) {
	a = get(a);
	b = get(b);
	if (a != b) {
		--cnt;
		if (sz[a] > sz[b]) swap(a, b);
		p[a] = b;
		sz[b] += sz[a];
		cg.push_back(a);
		cg.push_back(b);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20); cin.tie(0);
	#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n, m, k;
	cin >> n >> m >> k;
	vector <ll> c(n);
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}
	vector <ll> cmp;
	vector <pair <int, int>> have;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		ll x = c[u] ^ c[v];
		cmp.push_back(x);
		have.push_back({u, v});
	}
	sort(cmp.begin(), cmp.end());
	cmp.resize(unique(cmp.begin(), cmp.end()) - cmp.begin());
	ed.resize(cmp.size());
	for (auto p : have) {
		int u = p.first;
		int v = p.second;
		ll x = c[u] ^ c[v];
		int id = lower_bound(cmp.begin(), cmp.end(), x) - cmp.begin();
		ed[id].push_back({u, v});
	}
	int ans = 0;
	add(ans, mul(sub((1ll << k) % md, ed.size()), power(2, n)));
	for (int i = 0; i < n; ++i) {
		sz[i] = 1;
		p[i] = i;
	}
	for (int i = 0; i < ed.size(); ++i) {
		cnt = n;
		for (auto p : ed[i]) {
			merge(p.first, p.second);
		}
		add(ans, power(2, cnt));
		for (auto x : cg) {
			sz[x] = 1;
			p[x] = x;
		}
		cg.clear();
	}
	cout << ans << '\n';
}