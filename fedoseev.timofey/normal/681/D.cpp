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

struct fenwick {
	vector <int> f;
	int n;
	fenwick(int nn) {
		n = nn;
		f.resize(nn);
	}
	void modify(int x, int y) {
		for (int i = x; i < n; i |= (i + 1)) f[i] += y;
	}
	int get(int r) {
		int res = 0;
		for (int i = r; i >= 0; i &= i + 1, --i) {
			res += f[i];
		}
		return res;
	}
};

vector <int> e;

const int N = 1e5 + 7;

vector <int> g[N];
int l[N], r[N];

vector <int> h[N];

void dfs(int u, int d = 0) {
	h[d].push_back(u);
	l[u] = e.size();
	e.push_back(u);
	for (auto v : g[u]) {
		dfs(v, d + 1);
	}
	r[u] = (int)e.size() - 1;
}

vector <int> res;
vector <int> who[N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int m, n;
    cin >> n >> m;
    vector <int> was(n);
    vector <int> a(n);
    for (int i = 0; i < m; ++i) {
    	int u, v;
    	cin >> u >> v;
    	--u, --v;
    	g[u].push_back(v);
    	was[v] = 1;
    }
    vector <int> need(n);
    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
    	--a[i];
    	who[a[i]].push_back(i);
    	need[a[i]] = 1;
    }
    for (int i = 0; i < n; ++i) {
    	if (!was[i]) dfs(i);
    }
    for (int i = N - 1; i >= 0; --i) {
    	for (auto x : h[i]) {
    		if (need[x]) res.push_back(x);
    	}
    }
    fenwick f(N);
    for (auto x : res) {
    	f.modify(l[x], 1);
    	f.modify(r[x] + 1, -1);
    	for (auto t : who[x]) {
    		if (f.get(l[t]) != 1) {
    			cout << "-1\n";
    			return 0;
    		}
    	}
    }
    cout << res.size() << '\n';
    for (auto x : res) {
    	cout << x + 1 << '\n';
    }
}