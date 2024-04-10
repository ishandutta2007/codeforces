#include <bits/stdc++.h>

#define int long long

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 4e5 + 7;

vector <pair <int, int>> t[4 * N];

void addEdge(int ql, int qr, pair <int, int> e, int l, int r, int v) {
    if (qr < l || r < ql) return;
    if (ql <= l && r <= qr) {
        t[v].push_back(e);
    }
    else {
        int m = (l + r) >> 1;
        addEdge(ql, qr, e, l, m, 2 * v + 1);
        addEdge(ql, qr, e, m + 1, r, 2 * v + 2);
    }
}

ll cnt = 0;
int p[N];
int l[N], r[N];

vector <pair <int*, int>> s;

int get(int u) {
    if (u == p[u]) return u;
    return get(p[u]);
}

void _set(int &x, int y) {
	s.emplace_back(&x, x);
	x = y;
}

void merge(int u, int v) {
    u = get(u);
    v = get(v);
    if (u != v) {
        if (l[u] + r[u] < l[v] + r[v]) {
            swap(u, v);
        }
        ll nw = cnt;
        nw -= (ll)l[u] * r[u];
        nw -= (ll)l[v] * r[v];
        _set(p[v], u);
        _set(l[u], l[u] + l[v]);
        _set(r[u], r[u] + r[v]);
        nw += (ll)l[u] * r[u];
        _set(cnt, nw);
    }
}

int ans[N];

void rollback(int sz) {
    while (s.size() > sz) {
        *(s.back().first) = (s.back().second);
        s.pop_back();
    }
}

void dfs(int v, int l, int r) {
    int x = s.size();
    for (auto p : t[v]) {
        merge(p.first, p.second);
    }
    if (l == r) {
    	cout << cnt << ' ';
    }
    else {
    	int m = (l + r) >> 1;
    	dfs(2 * v + 1, l, m);
    	dfs(2 * v + 2, m + 1, r);
    }
    rollback(x);
}

signed main() {
    ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20); cin.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int q;
    cin >> q;
    vector <pair <int, int>> qrs(q);
    vector <int> xs, ys;
    for (int i = 0; i < q; ++i) {
    	int x, y;
    	cin >> x >> y;
    	xs.push_back(x);
    	ys.push_back(y);
    	qrs[i] = {x, y};
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
    ys.resize(unique(ys.begin(), ys.end()) - ys.begin());

    int n = xs.size(), m = ys.size();

    for (int i = 0; i < n + m; ++i) {
    	p[i] = i;
    }

    for (int i = 0; i < n; ++i) l[i] = 1;
    for (int i = n; i < n + m; ++i) r[i] = 1;
    map <pair <int, int>, int> tm;
    set <pair <int, int>> have;

    for (int i = 0; i < q; ++i) {
    	int x = qrs[i].first;
    	int y = qrs[i].second;
    	x = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
    	y = lower_bound(ys.begin(), ys.end(), y) - ys.begin();
    	y += n;
    	if (have.count({x, y})) {
    		addEdge(tm[{x, y}], i - 1, make_pair(x, y), 0, q - 1, 0);
    		have.erase({x, y});
    	}
    	else {
    		have.insert({x, y});
    	}
    	tm[{x, y}] = i;
    }
    for (auto p : have) {
    	int x = p.first;
    	int y = p.second;
    	addEdge(tm[{x, y}], q - 1, make_pair(x, y), 0, q - 1, 0);
    }

    dfs(0, 0, q - 1);    
}