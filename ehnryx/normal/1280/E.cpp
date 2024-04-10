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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-13;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5+1;
vector<int> adj[N];
int par[N], child[N];
bool add[N];
ll depth[N];
ll val[N];

int dfs(int u) {
	if(adj[u].empty()) {
		val[u] = 0;
		return depth[u] = 1;
	}

	int best = INF;
	int tot = 0;
	child[u] = -1;
	for(int v:adj[u]) {
		int cur = dfs(v);
		tot += cur;
		if(cur < best) {
			best = cur;
			child[u] = v;
		}
	}
	assert(child[u] != -1);

	return depth[u] = (add[u] ? best : tot);
}

void calc(int u, ll g) {
	if(adj[u].empty()) {
		val[u] = g;
		return;
	}

	if(add[u]) {
		calc(child[u], g);
	} else {
		for(int v:adj[u]) {
			calc(v, g);
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	string s;
	getline(cin, s);
	while (T--) {
		getline(cin, s);
		int id = s.find(' ');
		int goal = stoi(s.substr(0, id));
		int len = s.size();

		int n = 0;
		int cur = 0;
		adj[0].clear();
		for(int i=id; i<len; i++) {
			if(s[i] == '(') {
				adj[cur].push_back(++n);
				adj[n].clear();
				par[n] = cur;
				cur = n;
			} else if(s[i] == ')') {
				cur = par[cur];
			} else if(s[i] == '*') {
				adj[cur].push_back(++n);
				adj[n].clear();
				par[n] = cur;
			} else if(s[i] == 'P') {
				add[cur] = 0;
			} else if(s[i] == 'S') {
				add[cur] = 1;
			}
		}

		int cnt = dfs(1);
		calc(1, (ll) cnt * goal);
		cout << "REVOLTING ";
		for(int i=1; i<=n; i++) {
			if(adj[i].empty()) {
				cout << val[i] << " ";
			}
		}
		cout << nl;
	}

	return 0;
}