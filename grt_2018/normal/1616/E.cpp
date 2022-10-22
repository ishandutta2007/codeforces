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

const int nax = 1e5 + 10, INF = 1e9;
const ll INFLL = 1e18;
int q, n;
string s, t;
int let[26];
bool av[nax];
int T[nax];

void add(int a, int x) {
	while(a <= n) {
		T[a] += x;
		a += a &(-a);
	}
}

int qr(int a) {
	int w = 0;
	while(a > 0) {
		w += T[a];
		a -= a &(-a);
	}
	return w;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> q;
	while(q--) {
		cin >> n >> s >> t;
		for(int i = 1; i <= n; ++i) {
			T[i] = 0;
		}
		for(int i = 1; i <= n; ++i) {
			add(i, 1);
		}
		for(int j = 0; j < 26; ++j) {
			let[j] = INF;
			for(int i = 0; i < n; ++i) {
				if(s[i] - 'a' == j) {
					let[j] = i;
					break;
				}
			}
		}
		ll ans = INFLL;
		ll cur = 0;
		for(int i = 0; i < n; ++i) {
			int id = t[i] - 'a';
			for(int j = 0; j < id; ++j) {
				if(let[j] != INF)
				ans = min(ans, qr(let[j] + 1) - 1 + cur);
			}
			//cout << "CUR: " << cur << " " << let[id] + 1 << "\n";
			if(let[id] == INF) break;
			//cout << "ZAPL " << let[id] << " " << qr(let[id] + 1) << "\n";
			cur += qr(let[id] + 1) - 1;
			add(let[id] + 1, -1);
			bool f = false;
			for(int j = let[id] + 1; j < n; ++j) {
				if(s[j] - 'a' == id) {
					let[id] = j;
					f = true;
					break;
				}
			}
			if(!f) let[id] = INF;
		}
		if(ans >= INFLL) {
			cout << "-1\n";
		} else {
			cout << ans << "\n";
		}
	}
}