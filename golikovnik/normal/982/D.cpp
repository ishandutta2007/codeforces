#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

vector<int> p, r;
vector<int> w;
vector<int> used;
multiset<int> lengths;

int get(int u) {
	return p[u] == u ? u : get(p[u]);
}

void erase_one(int x) {
	auto itr = lengths.find(x);
	if (itr != lengths.end()) lengths.erase(itr);
}

void unite(int u, int v) {
	u = get(u), v = get(v);
	if (u == v) return;
	if (r[u] == r[v]) ++r[u];
	if (r[u] < r[v]) swap(u, v);
	int new_length = w[u] + w[v];
	if (used[u])
	    erase_one(w[u]);
	if (used[v])
	    erase_one(w[v]);
	lengths.insert(new_length);
	w[u] = new_length;
	p[v] = u;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	vector<pair<int, int>> order(n);
	p.resize(n);
	r.resize(n);
	w.resize(n);
	used.resize(n);
	for (int i = 0; i < n; ++i) {
		w[i] = 1;
		p[i] = i;
		int x;
		cin >> x;
		a[i] = x;
		order[i] = make_pair(x, i);
	}
	sort(all(order));
	int k = 0;
	int loc_num = 0;
	for (int i = 1; i < n; ++i) {
		int j = order[i - 1].second;
		int did = 0;
		if (j > 0 && used[j - 1]) {
			did = 1;
			unite(j, j - 1);
		}
		if (j + 1 < n && used[j + 1]) {
			did = 1;
			unite(j, j + 1);
		}
		if (!did) {
			lengths.insert(1);
		}
		used[j] = 1;
		if (*lengths.begin() == *lengths.rbegin()) {
			if (lengths.size() > loc_num) {
			    k = order[i - 1].first + 1;
			    loc_num = lengths.size();
			} else if (lengths.size() == loc_num) {
			    k = min(k, order[i - 1].first + 1);
			}
		}
	}
	if (loc_num < 1) {
	    k = *max_element(all(a)) + 1;
	}
	cout << k << "\n";
	return 0;	
}