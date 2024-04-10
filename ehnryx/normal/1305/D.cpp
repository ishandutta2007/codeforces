//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1e3 + 7;
vector<vector<int>> groups[N];
vector<int> adj[N];

vector<int> build(int u, int p) {
	vector<int> out;
	for(int v : adj[u]) {
		if(v == p) continue;
		auto subtree = build(v, u);
		if(out.size() < subtree.size()) {
			swap(out, subtree);
		}
		for(int w : subtree) {
			out.push_back(w);
		}
	}
	if(out.empty()) {
		out.push_back(u);
	}
	return out;
}

void get_groups(int r) {
	for(int v : adj[r]) {
		groups[r].push_back(build(v, r));
	}
}

// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	for(int i=1; i<n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i=1; i<=n; i++) {
		get_groups(i);
	}

	unordered_set<int> seen;
	int u = 1;
	for(;;) {
		int first = -1;
		int second = -1;
		for(int i=0; i<groups[u].size(); i++) {
			bool ok = true;
			for(int v : groups[u][i]) {
				ok &= !seen.count(v);
			}
			if(ok) {
				if(first == -1) {
					first = i;
				} else if(second == -1) {
					second = i;
				} else {
					break;
				}
			}
		}
		if(first == -1) {
			break;
		}
		int a = groups[u][first][0];
		int b = (second == -1 ? u : groups[u][second][0]);
		seen.insert(a);
		seen.insert(b);
		cout << "? " << a << " " << b << endl;
		cin >> u;
	}

	cout << "! " << u << endl;

	return 0;
}