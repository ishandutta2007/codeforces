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

map <vector <int>, int> ans;

int cnt = 0;

int query(vector <int> &a) {
	if (a.size() <= 1) return 0;
	sort(a.begin(), a.end());
	if (ans.count(a)) {
		return ans[a];
	}
	cout << "? " << a.size() << '\n';
	for (int i = 0; i < a.size(); ++i) {
		cout << a[i] + 1 << ' ';
	}
	cout << endl;
	int x;
	cin >> x;
	if (x == -1) exit(1);
	ans[a] = x;
	return x;
}

int get(vector <int> &a, vector <int> &b) {
	vector <int> c;
	for (auto x : a) c.push_back(x);
	for (auto x : b) c.push_back(x);
	return query(c) - query(a) - query(b);
}

const int N = 607;

vector <int> g[N];

vector <int> path;

void dfs(int u, int x, int p) {
	path.push_back(u);
	if (u == x) {
		cout << "N " << path.size() << '\n';
		for (auto v : path) {
			cout << v + 1 << ' ';
		}
		cout << endl;
		exit(0);
	}
	for (auto v : g[u]) {
		if (v != p) dfs(v, x, u);
	}
	path.pop_back();
}

void find_edge(vector <int> a, vector <int> b, int &u, int &v) {
	while (a.size() > 1) {
		int m = a.size();
		vector <int> ta = vector <int> (a.begin(), a.begin() + m / 2);
		vector <int> tb = vector <int> (a.begin() + m / 2, a.end());
		int x = get(ta, b);
		if (x != 0) a = ta;
		else a = tb;
	}
	while (b.size() > 1) {
		int m = b.size();
		vector <int> ta = vector <int> (b.begin(), b.begin() + m / 2);
		vector <int> tb = vector <int> (b.begin() + m / 2, b.end());
		int x = get(ta, a);
		if (x != 0) b = ta;
		else b = tb;
	}
	assert(a.size() == b.size() && a.size() == 1);
	u = a[0];
	v = b[0];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <int> a = {0};
    vector <int> used(n);
    vector <int> color(n);
    used[0] = 1;
    while (a.size() < n) {
    	vector <int> b;
    	for (int i = 0; i < n; ++i) if (!used[i]) b.push_back(i);
    	int u, v;
   		find_edge(a, b, u, v);
    	used[v] = 1;
    	g[u].push_back(v);
    	g[v].push_back(u);
    	color[v] = color[u] ^ 1;
    	a.push_back(v);
    }
    vector <int> pt[2];
    for (int i = 0; i < n; ++i) {
    	pt[color[i]].push_back(i);
    }
    for (int i = 0; i < 2; ++i) {
    	if (query(pt[i]) != 0) {
    		for (auto x : pt[i]) {
    			vector <int> a = {x};
    			vector <int> b;
    			for (auto y : pt[i]) if (y != x) b.push_back(y);
    			if (get(a, b)) {
    				int u, v;
    				find_edge(a, b, u, v);
    				dfs(u, v, -1);
    			}
    		}
    	}
    }
    cout << "Y " << pt[0].size() << '\n';
    for (auto x : pt[0]) cout << x + 1 << ' ';
    cout << endl;
}