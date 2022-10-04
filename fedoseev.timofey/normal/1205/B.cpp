#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
const int K = 60;
 
vector <int> who[K];
 
const int Inf = 1e9;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <ll> a;
    for (int i = 0; i < n; ++i) {
    	ll x;
    	cin >> x;
    	if (x != 0) {
    		a.push_back(x);
    	} else {
    		continue;
    	}
    	for (int j = 0; j < K; ++j) {
    		if ((a.back() >> j) & 1) {
    			who[j].push_back((int)a.size() - 1);
    		}
    	}
    }
    n = a.size();
    for (int i = 0; i < K; ++i) {
    	if (who[i].size() >= 3) {
    		cout << "3\n";
    		return 0;
    	}
    }
    vector <vector <int>> g(n);
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < n; ++j) {
    		if (i == j) continue;
    		if ((a[i] & a[j])) {
    			g[i].push_back(j);
    		}
    	}
    }
    int ans = n + 1;
    for (int f = 0; f < n; ++f) {
    	for (int s : g[f]) {
    		vector <int> d(n, Inf);
	    	queue <int> q;
	    	d[f] = 0;
	    	q.push(f);
	    	while (!q.empty()) {
	    		int u = q.front();
	    		q.pop();
	    		for (auto v : g[u]) {
	    			if ((u == f && v == s) || (u == s && v == f)) continue;
	    			if (d[v] > d[u] + 1) {
	    				d[v] = d[u] + 1;
	    				q.push(v);
	    			}
	    		}
	    	}
	    	ans = min(ans, d[s] + 1);
    	}
    }
    if (ans == n + 1) {
    	cout << "-1\n";
    } else {
    	cout << ans << '\n';
    }
}