    #include <bits/stdc++.h>
    using namespace std;
     
    typedef long long ll;
    typedef pair<int, int> pii;
    typedef unsigned long long ull;
    typedef long double ld;
     
    struct pt {
    	ll x, y;
     
    	pt() : x(0), y(0) {}
    	pt(ll x, ll y) : x(x), y(y) {}
    };
     
    pt operator+(const pt &a, const pt &b) {
    	return pt(a.x + b.x, a.y + b.y);
    }
     
    pt operator-(const pt &a, const pt &b) {
    	return pt(a.x - b.x, a.y - b.y);
    }
     
    ll cross(const pt &a, const pt &b) {
    	return a.x * b.y - a.y * b.x;
    }
     
    bool isUpper(const pt &a, const pt &b, const pt &c) {
    	return cross(c - a, b - a) > 0;
    }
     
    bool isLower(const pt &a, const pt &b, const pt &c) {
    	return cross(c - a, b - a) < 0;
    }
     
    const int N = (int) 1e5 + 100;
    const int LOG = 17;
     
    vector<int> g[N];
    int up[N][LOG];
    int h[N];
     
    void dfs(int v) {
    	for (int i = 1; i < LOG; i++) {
    		up[v][i] = up[up[v][i - 1]][i - 1];
    	}
     
    	for (int to : g[v]) {
    		h[to] = h[v] + 1;
    		up[to][0] = v;
    		dfs(to);
    	}
    }
     
    int lca(int a, int b) {
    	for (int i = LOG - 1; i >= 0; i--) {
    		if (h[up[a][i]] >= h[b]) {
    			a = up[a][i];
    		}
     
    		if (h[up[b][i]] >= h[a]) {
    			b = up[b][i];
    		}
    	}
     
    	for (int i = LOG - 1; i >= 0; i--) {
    		if (up[a][i] != up[b][i]) {
    			a = up[a][i];
    			b = up[b][i];
    		}
    	}
     
    	return a == b ? a : up[a][0];
    }
     
    int main() {
    	ios_base::sync_with_stdio(0);
    	cin.tie(0);
     
    	int n;
    	cin >> n;
     
    	vector<pt> pts(n);
     
    	for (pt &p : pts) {
    		cin >> p.x >> p.y;
    	}
     
    	vector<pt> hull;
    	vector<int> nextId(n);
     
    	hull.push_back(pts[n - 1]);
    	nextId[n - 1] = n - 1;
    	vector<int> ptsId;
    	ptsId.push_back(n - 1);
     
    	for (int i = n - 2; i >= 0; i--) {
    		while (hull.size() > 1 && isLower(pts[i], hull.back(), hull[hull.size() - 2])) {
    			hull.pop_back();
    			ptsId.pop_back();
    		}
     
    		hull.push_back(pts[i]);
    		nextId[i] = ptsId.back();
    		ptsId.push_back(i);
    	}
     
    	for (int i = 0; i + 1 < n; i++) {
    		g[nextId[i]].push_back(i);
    	}
     
    	up[n - 1][0] = n - 1;
    	dfs(n - 1);
     
    	int q;
    	cin >> q;
     
    	while (q--) {
    		int a, b;
    		cin >> a >> b;
     
    		--a;
    		--b;
     
    		cout << lca(a, b) + 1 << " ";
    	}
     
    	return 0;
    }