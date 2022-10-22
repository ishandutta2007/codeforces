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
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int M = 26;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while(T--) {
		string s;
		cin >> s;
		int n = s.size();
		if(n == 1) {
			cout << "YES" << nl;
			for(char c='a'; c<='z'; c++) {
				cout << c;
			}
			cout << nl;
			continue;
		}

		vector<set<int>> adj(M);
		for(int i=1; i<n; i++) {
			adj[s[i-1]-'a'].insert(s[i]-'a');
			adj[s[i]-'a'].insert(s[i-1]-'a');
		}

		set<int> have;
		for(char c : s) {
			have.insert(c);
		}

		int cnt = 0;
		int u = -1;
		for(int i=0; i<M; i++) {
			cnt += !adj[i].empty();
			if(adj[i].size() == 1) {
				u = i;
			}
		}
		assert(cnt == have.size());

		vector<bool> seen(M);
		string ans;
		bool ok = (u != -1);
		for(int p=-1; u!=-1; ) {
			if(adj[u].size() > 2) {
				ok = false;
				break;
			}
			seen[u] = true;
			ans.push_back(u+'a');
			bool foundp = (p == -1);
			int nxt = -1;
			for(int v : adj[u]) {
				if(v == p) foundp = true;
				else nxt = v;
			}
			assert(foundp);
			p = u;
			u = nxt;
		}

		if(ok && ans.size() == cnt) {
			cout << "YES" << nl;
			for(int i=0; i<M; i++) {
				if(!seen[i]) ans.push_back(i+'a');
			}
			cout << ans << nl;
			assert(ans.size() == M);
		} else {
			cout << "NO" << nl;
		}

	}

	return 0;
}