#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second

//#pragma GCC optimize ("O3")
//#pragma GCC target("tune=native")

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

const int nax = 200 * 1000 + 10;
int t, n, m;
ll a[nax];
vi valid[nax], valid2[nax];
bool done[nax];

void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for(int x, i = 1; i <= n; ++i) {
		cin >> x;
		a[i] -= x;
	}
	for(int i = 1; i <= n; ++i) {
		a[i] += a[i - 1];
		valid[i] = {};
		valid2[i] = {};
		done[i] = false;
	}
	valid[0] = {}; valid2[0] = {};
	for(int l, r, i = 1; i <= m; ++i) {
		cin >> l >> r;
		l--;
		valid[l].PB(r);
		valid2[r].PB(l);
	}
	done[0] = false;
	set<int>nzer = {};
	queue<int>Q = {};
	for(int i = 0; i <= n; ++i) {
		if(a[i] == 0) {
			Q.push(i);
			done[i] = true;
		} else {
			nzer.insert(i);
		}
	}
	while(!Q.empty()) {
		int x = Q.front();
		Q.pop();
		for(auto l : valid[x]) {
			if(!nzer.count(l)) {
				auto it = nzer.lower_bound(x);
				auto it2 = it;
				while(it != nzer.end() && (*it) <= l) {
					Q.push((*it));
					done[(*it)] = true;
					it = next(it);
				}
				nzer.erase(it2, it);
			}
		}
		for(auto r : valid2[x]) {
			if(!nzer.count(r)) {
				auto it = nzer.lower_bound(r);
				auto it2 = it;
				while(it != nzer.end() && (*it) <= x) {
					Q.push((*it));
					done[(*it)] = true;
					it = next(it);
				}
				nzer.erase(it2, it);
			}
		}
	}
	if(nzer.empty()) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		solve();
	}
}