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

const int K = 14;
const int N = 1e3 + 7;

struct AhoCorasick {
	int toi(char c) { return c - 'a'; }
	int nxt[N][K], par[N], val[N], fail[N], to[N][K];
	int uid;

	AhoCorasick() {
		memset(nxt, -1, sizeof nxt);
		memset(par, -1, sizeof par);
		memset(val, 0, sizeof val);
		memset(fail, 0, sizeof fail);
		uid = 0;
	}

	void add(const string& s, int v) {
		int u = 0;
		for(char c : s) {
			if(nxt[u][toi(c)] == -1) {
				nxt[u][toi(c)] = ++uid;
				par[uid] = u;
			}
			u = nxt[u][toi(c)];
		}
		val[u] += v;
	}

	int build() {
		queue<int> bfs;
		bfs.push(0);
		while(!bfs.empty()) {
			int u = bfs.front();
			bfs.pop();
			val[u] += val[fail[u]];
			for(int c=0; c<K; c++) {
				if(nxt[u][c] == -1) continue;
				int w = fail[u];
				while(w && nxt[w][c] == -1) {
					w = fail[w];
				}
				if(w == u || nxt[w][c] == -1) {
					fail[nxt[u][c]] = w;
					assert(w == 0);
				} else {
					fail[nxt[u][c]] = nxt[w][c];
				}
				bfs.push(nxt[u][c]);
			}
		}
		return uid + 1;
	}

	void compress() {
		for(int u=0; u<=uid; u++) {
			for(int c=0; c<K; c++) {
				int w = u;
				while(w && nxt[w][c] == -1) {
					w = fail[w];
				}
				if(nxt[w][c] == -1) {
					to[u][c] = w;
				} else {
					to[u][c] = nxt[w][c];
				}
			}
		}
	}

	pair<int,ll> go(int u, int l, int r, const string& s) {
		ll res = 0;
		for(int i=l; i<r; i++) {
			u = to[u][toi(s[i])];
			res += val[u];
		}
		return make_pair(u, res);
	}

	pair<int,ll> walk(int u, char c) {
		u = to[u][toi(c)];
		return make_pair(u, val[u]);
	}
};

pair<int,ll> jump[K+2][N]; // pos, state -> next state, value
ll dp[N][1<<K]; // pos, state, used

// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	AhoCorasick ac;
	for(int i=0; i<n; i++) {
		string s; int c;
		cin >> s >> c;
		ac.add(s, c);
	}
	int states = ac.build();
	ac.compress();

	string s;
	cin >> s;
	int m = s.size();
	vector<int> idx;
	idx.push_back(-1);
	for(int i=0; i<m; i++) {
		if(s[i] == '?') {
			idx.push_back(i);
		}
	}
	idx.push_back(m);

	for(int i=1; i<idx.size(); i++) {
		for(int j=0; j<states; j++) {
			jump[i-1][j] = ac.go(j, idx[i-1]+1, idx[i], s);
		}
	}

	memset(dp, 0x3f ^ 0xff, sizeof dp);
	dp[0][0] = 0;
	for(int i=1; i+1<idx.size(); i++) {
		for(int j=0; j<states; j++) {
			auto [nj, value] = jump[i-1][j];
			for(int bm=0; bm<1<<K; bm++) {
				if(__builtin_popcount(bm) != i) continue;
				for(char c=0; c<K; c++) {
					if(!(bm & 1<<c)) continue;
					auto [nxtj, nxtvalue] = ac.walk(nj, c+'a');
					dp[nxtj][bm] = max(dp[nxtj][bm], dp[j][bm^1<<c] + value + nxtvalue);
				}
			}
		}
	}

	ll ans = -INFLL;
	int cnt = (int)idx.size() - 2;
	assert(cnt >= 0);
	for(int bm=0; bm<1<<K; bm++) {
		if(__builtin_popcount(bm) == cnt) {
			for(int j=0; j<states; j++) {
				ans = max(ans, dp[j][bm] + jump[cnt][j].second);
			}
		}
	}
	cout << ans << nl;

	return 0;
}