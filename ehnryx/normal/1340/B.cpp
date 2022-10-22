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

vector<int> bits {
	0b1110111,
	0b0010010,
	0b1011101,
	0b1011011,
	0b0111010,
	0b1101011,
	0b1101111,
	0b1010010,
	0b1111111,
	0b1111011,
};

const int N = 2e3 + 1;
int dp[N][N];

// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i=0; i<n; i++) {
		string s;
		cin >> s;
		a[i] = stoi(s, 0, 2);
	}

	memset(dp, -1, sizeof dp);
	dp[n][0] = 0;
	for(int i=n-1; i>=0; i--) {
		for(int j=0; j<=k; j++) {
			for(int v : bits) {
				if((v & a[i]) != a[i]) continue;
				int use = __builtin_popcount(v ^ a[i]);
				if(use > j || dp[i+1][j-use] == -1) continue;
				dp[i][j] = v;
			}
		}
	}

	if(dp[0][k] == -1) {
		cout << -1 << nl;
		return 0;
	}

	for(int i=0, j=k; i<n; i++) {
		int v = dp[i][j];
		j -= __builtin_popcount(v ^ a[i]);
		int num = find(bits.begin(), bits.end(), v) - bits.begin();
		cout << num;
	}
	cout << nl;

	return 0;
}