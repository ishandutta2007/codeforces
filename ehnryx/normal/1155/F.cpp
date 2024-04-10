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

const int N = 14;
int adj[N][N];
int cyc[N][N][1<<N], dp[1<<N];
tuple<int,int,int> best[1<<N];
int cto[N][N][1<<N];

int cycle(int s, int t, int bm) {
	if(cyc[s][t][bm] != -1) return cyc[s][t][bm];
	assert(bm);
	if(__builtin_popcount(bm) == 1) {
		int u = 31 - __builtin_clz(bm);
		cto[s][t][bm] = u;
		return cyc[s][t][bm] = (adj[s][u] && adj[t][u] && s != t);
	}
	int res = false;
	for(int i=0; i<N; i++) {
		if(!(bm&1<<i) || !adj[s][i]) continue;
		int cur = cycle(i, t, bm^1<<i);
		if(cur) {
			res = cur;
			cto[s][t][bm] = i;
		}
	}
	return cyc[s][t][bm] = res;
}

int solve(int bm) {
	if(dp[bm] != -1) return dp[bm];
	if(bm == 0) return dp[bm] = 0;
	int res = INF;
	for(int i=0; i<N; i++) {
		if(bm&1<<i) continue;
		for(int j=0; j<=i; j++) {
			if(bm&1<<j) continue;
			for(int sm=bm; sm; sm=(sm-1)&bm) {
				if(cycle(i, j, sm)) {
					int cur = solve(bm^sm) + 1;
					if(cur < res) {
						res = cur;
						best[bm] = make_tuple(i, j, sm);
					}
				}
			}
		}
	}
	return dp[bm] = res;
}

vector<pii> ans;

void recover_cycle(int s, int t, int bm) {
	if(bm == 0) {
		ans.push_back(pii(s,t));
	} else {
		int u = cto[s][t][bm];
		ans.push_back(pii(s,u));
		recover_cycle(u, t, bm^1<<u);
	}
}

void recover(int bm) {
	if(!bm) return;
	int s, t, sm;
	tie(s, t, sm) = best[bm];
	recover_cycle(s, t, sm);
	recover(bm^sm);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, m;
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		adj[a][b] = adj[b][a] = true;
	}

	memset(dp, -1, sizeof dp);
	memset(cyc, -1, sizeof cyc);
	assert(solve((1<<(n-1))-1) < INF);
	recover((1<<(n-1))-1);

	cout << ans.size() << nl;
	for(const pii& it:ans) {
		cout << it.first+1 << " " << it.second+1 << nl;
	}

	return 0;
}