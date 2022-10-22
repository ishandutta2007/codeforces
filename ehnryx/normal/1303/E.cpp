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
const int N = 400 + 1;
int dp[N][N];
vector<int> idx[M], nxt[M];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while(T--) {
		string s, t;
		cin >> s >> t;
		int n = s.size();
		int m = t.size();

		for(int i=0; i<M; i++) {
			idx[i].clear();
			nxt[i].clear();
		}
		for(int i=0; i<n; i++) {
			idx[s[i]-'a'].push_back(i);
		}
		for(int j=0; j<M; j++) {
			idx[j].push_back(INF);
			for(int i=0; i<=n; i++) {
				nxt[j].push_back(*lower_bound(idx[j].begin(), idx[j].end(), i));
			}
		}

		bool ok = false;
		for(int split=0; split<m; split++) {
			dp[0][0] = 0;
			for(int i=0; i<=split; i++) {
				for(int j=0; j<=m-split; j++) {
					if(i == 0 && j == 0) continue;
					dp[i][j] = INF;
					if(i > 0 && dp[i-1][j] < INF) {
						int c = t[i-1] - 'a';
						dp[i][j] = min(dp[i][j], nxt[c][dp[i-1][j]] + 1);
					}
					if(j > 0 && dp[i][j-1] < INF) {
						int c = t[split + j-1] - 'a';
						dp[i][j] = min(dp[i][j], nxt[c][dp[i][j-1]] + 1);
					}
				}
			}
			ok |= (dp[split][m-split] < INF);
		}

		if(ok) {
			cout << "YES" << nl;
		} else {
			cout << "NO" << nl;
		}
	}

	return 0;
}