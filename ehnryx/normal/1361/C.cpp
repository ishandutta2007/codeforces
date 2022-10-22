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

const int N = 1<<20;

namespace ET {
	vector<pair<int,int>> adj[N];
	vector<pair<int,int>>::iterator cur[N]; int eid, in[N];
	void clear(int n=N) {
		eid = 0; for(int i=0; i<n; i++) { adj[i].clear(); in[i] = 0; }
	}
	void add_edge(int a, int b, bool bi) {
		if(bi) adj[b].emplace_back(a, eid); else in[b]++;
		adj[a].emplace_back(b, eid++);
	}
	bool is_bad(int u, bool bi) {
		return bi ? adj[u].size() % 2 : in[u] != adj[u].size();
	}
	vector<pair<int,int>> euler_tour(int r, bool bi, int n=N) {
		int bad = 0;
		for(int i=0; i<n && bad<=1; i++) if(i!=r) bad += is_bad(i, bi);
		if(bad > 1) return {};
		vector<bool> vis(eid); // only needed for undirected graphs
		for(int i=0; i<n; i++) cur[i] = adj[i].begin();
		vector<pair<int,int>> res; stack<pair<int,int>> stk;
		for(stk.emplace(r, -1); !stk.empty(); ) {
			int u = stk.top().first; auto end = adj[u].end(), &i = cur[u];
			while(i != end && vis[i->second]) i++;
			if(i != end) { stk.push(*i); vis[i->second] = true; }
			else { res.push_back(stk.top()); stk.pop(); }
		}
		if(res.size() != eid+1) return {};
		reverse(res.begin(), res.end());
		return res;
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
	vector<int> a(2*n);
	for(int i=0; i<2*n; i++) {
		cin >> a[i];
	}

	for(int k=20; k>=0; k--) {
		int mask = (1<<k) - 1;
		ET::clear(1<<k);
		for(int i=0; i<2*n; i+=2) {
			ET::add_edge(a[i] & mask, a[i^1] & mask, true);
		}
		vector<pair<int,int>> ans = ET::euler_tour(a[0] & mask, true, 1<<k);
		if(ans.empty() || ans.front().first != ans.back().first) continue;

		cout << k << nl;
		for(auto [u, i] : ans) {
			if(i == -1) continue;
			if(u == (a[2*i+1] & mask)) {
				cout << 2*i+1 << " " << 2*i+2 << " ";
			} else {
				cout << 2*i+2 << " " << 2*i+1 << " ";
			}
		}
		cout << nl;
		break;
	}

	return 0;
}