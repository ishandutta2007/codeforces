#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1e5+1;
ll dps[N], dpd[N];
ll same(int,int);
ll diff(int,int);

ll same(int n, int k) {
	if (dps[n] != -1) return dps[n];
	if (n == 0) return dps[n] = 0;
	else return dps[n] = (k-1)*diff(n-1,k)%MOD;
}

ll diff(int n, int k) {
	if (dpd[n] != -1) return dpd[n];
	if (n == 0) return dpd[n] = 1;
	else return dpd[n] = ((k-2)*diff(n-1,k)%MOD + same(n-1,k)) % MOD;
}

//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	memset(dps, -1, sizeof dps);
	memset(dpd, -1, sizeof dpd);

	int n, k;
	cin >> n >> k;

	vector<int> v[2];
	for (int i=0; i<n; i++) {
		int a;
		cin >> a;
		v[i%2].push_back(a);
	}

	ll ans[2];
	ans[0] = ans[1] = 1;
	for (int t=0; t<2; t++) {
		int m = v[t].size();
		int pre = -1;
		for (int i=0; i<m; i++) {
			if (v[t][i] != -1) {
				int len = i-pre-1;
				if (pre == -1) {
					if (i!=0) {
						ans[t] = ans[t] * ((k-1)*diff(len-1,k)%MOD + same(len-1,k)) % MOD;
					}
				}
				else {
					if (v[t][pre] == v[t][i]) {
						ans[t] = ans[t] * same(len, k) % MOD;
					} else {
						ans[t] = ans[t] * diff(len, k) % MOD;
					}
				}
				pre = i;
			}
		}
		{
			int len = m-pre-1;
			if (pre == -1) {
				if (len <= 1) {
					ans[t] = k;
				} else {
					ans[t] = ans[t] * ((ll)k*(k-1)%MOD*diff(len-2,k)%MOD + k*same(len-2,k)%MOD) % MOD;
				}
			} else if (pre < m-1) {
				ans[t] = ans[t] * ((k-1)*diff(len-1,k)%MOD + same(len-1,k)) % MOD;
			}
		}
	}

	cerr << "ANS = " << ans[0] << " * " << ans[1] << nl;

	cout << ans[0]*ans[1] % MOD << nl;

	return 0;
}