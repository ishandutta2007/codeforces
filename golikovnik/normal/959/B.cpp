#include <bits/stdc++.h>
using namespace std;

int get(vector<int> &p, int v) {
	return p[v] == v ? v : get(p, p[v]);
}

void unite(vector<int> &p, vector<int> &r, vector<int> &data, int v, int u) {
	v = get(p, v), u = get(p, u);
	if (v == u) return;
	if (r[v] == r[u]) ++r[v];
	if (r[v] < r[u]) swap(v, u);
	p[u] = v;
	data[v] = min(data[u], data[v]);
}

int main() {
	int n, k, m;
	cin >> n >> k >> m;
	map<string, int> a;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		a[s] = i;
	}
	vector<int> values(n);
	for (int &x: values) cin >> x;
	vector<int> p(n), r(n), data(n);
	for (int i = 0; i < n; ++i) {
		p[i] = i;
		data[i] = values[i];
	}
	for (int i = 0; i < k; ++i) {
		int x;
		cin >> x;
		int who;
		cin >> who;
		--who;
		for (int j = 0; j < x - 1; ++j) {
			int son;
			cin >> son;
			--son;
			unite(p, r, data, who, son);
		}
	}
        long long ans = 0;
	for (int i = 0; i < m; ++i) {
		string s;
		cin >> s;
		ans += data[get(p, a[s])];
	}
	cout << ans << "\n";
	return 0;
}