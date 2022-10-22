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
const ll MOD = 998244353;
const ld EPS = 1e-13;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

typedef vector<vector<ll>> Matrix;
typedef vector<ll> Row;

Matrix mul(const Matrix& a, const Matrix& b) {
	int n = a.size();
	Matrix res(n, Row(n, 0));
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			for(int k=0; k<n; k++) {
				res[i][j] += a[i][k] * b[k][j] % MOD;
			}
			res[i][j] %= MOD;
		}
	}
	return res;
}

vector<ll> mulvec(const vector<ll>& v, const Matrix& a) {
	int n = v.size();
	vector<ll> res(n, 0);
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			res[i] += a[i][j] * v[j] % MOD;
		}
		res[i] %= MOD;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;

	int len[n+1];
	for(int i=1; i<=n; i++) {
		cin >> len[i];
	}

	int m;
	cin >> m;
	set<pii> col[n+1];
	for(int i=0; i<m; i++) {
		int row, cell, c;
		cin >> row >> cell >> c;
		col[row].insert(make_pair(cell, c-1));
	}

	int trans[3][3];
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			cin >> trans[i][j];
		}
	}

	const int M = 1<<6;
	Matrix mat(M, Row(M, 0));

	Matrix small[3];
	int mask = 0b1111;
	for(int c=0; c<3; c++) {
		small[c] = Matrix(M, Row(M, 0));
		for(int bm=0; bm<M; bm++) {
			for(int to=0; to<M; to++) {
				if((to&mask) != (bm>>2)) continue;
				set<int> cur;
				for(int v=0; v<=3; v++) {
					cur.insert(v);
				}
				for(int j=0; j<3; j++) {
					if(trans[c][j]) {
						cur.erase(to>>(2*j) & 0b11);
					}
				}
				if((bm & 0b11) == *cur.begin()) {
					small[c][bm][to] = 1;
					mat[bm][to]++;
				}
			}
		}
	}

	const int L = 30;
	Matrix memo[L];
	memo[0] = mat;
	for(int j=1; j<L; j++) {
		memo[j] = mul(memo[j-1], memo[j-1]);
	}

	ll memres[n+1][4];
	memset(memres, 0, sizeof memres);
	for(int i=1; i<=n; i++) {
		vector<ll> res(M, 0);
		res[M-1] = 1;
		int cur = 0;
		while(!col[i].empty()) {
			int nxt, c;
			tie(nxt, c) = *col[i].begin();
			col[i].erase(col[i].begin());
			assert(cur < nxt);
			for(int j=0; j<L; j++) {
				if(1<<j & (nxt-cur-1)) {
					res = mulvec(res, memo[j]);
				}
			}
			res = mulvec(res, small[c]);
			cur = nxt;
		}

		assert(cur <= len[i]);
		for(int j=0; j<L; j++) {
			if(1<<j & (len[i]-cur)) {
				res = mulvec(res, memo[j]);
			}
		}

		for(int bm=0; bm<M; bm++) {
			memres[i][bm&0b11] += res[bm];
		}
		for(int j=0; j<4; j++) {
			memres[i][j] %= MOD;
		}
	}

	ll dp[n+1][4];
	memset(dp, 0, sizeof dp);
	dp[0][0] = 1;
	for(int i=1; i<=n; i++) {
		for(int j=0; j<4; j++) {
			for(int k=0; k<4; k++) {
				dp[i][j] += dp[i-1][j^k] * memres[i][k] % MOD;
			}
			dp[i][j] %= MOD;
		}
	}
	cout << dp[n][0] << nl;

	return 0;
}