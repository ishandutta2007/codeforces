#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
using pd2 = pair<ld, ld>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

const ll mod = 1e9 + 7;

ll fpow(ll a, ll b){
	ll res = 1, mul = a, bit = b;
	while (bit){
		if (bit & 1){ res = res*mul % mod; }
		mul = mul*mul % mod; bit >>= 1;
	}
	return res;
}
inline ll finv(ll a){ return fpow(a, mod-2); }

ll inv;
ll dp[2020][2020]; ll k;
ll dpf(int n, int m){
	if (dp[n][m] != -1){ return dp[n][m]; }
	if (n == m){ return dp[n][m] = (k*n) % mod; }
	if (m == 0){ return dp[n][m] = 0; }
	dp[n][m] = ( dpf(n-1, m)+dpf(n-1, m-1) ) % mod;
	dp[n][m] = dp[n][m]*inv % mod;
	return dp[n][m];
}

void Main(){ inv = finv(2);
	int t; cin >> t;
	memset(dp, -1, sizeof(dp));
	while (t--){
		int n, m; cin >> n >> m >> k;
		cout << dpf(n, m) << endl;
		for (int i = 0; i <= n; i++){
			for (int j = 0; j <= m; j++){ dp[i][j] = -1; }
		}
	}
}

//#define DEBUG
int main(){
#ifndef DEBUG
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
#endif
	cout.setf(ios::fixed);
	cout.precision(0);
	Main();
}