#include <bits/stdc++.h>
#define endl '\n'
#define fr first
#define sc second
#define all(v) v.begin(),v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() )
#define bout(x) cout << bitset<sizeof(x)*8>(x) << endl
#define mkp(a,b) make_pair(a,b)
#define gcd(a,b) __gcd(a,b)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using cpl = complex<ld>;
const ld pi = 3.14159265358979323846264338327950288;
const ld tau = 2 * pi;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

//#define DEBUG

const ll mod = 1e9 + 7;

ll dp[120][120];
ll sum[120][120];

void Main(){
	int n, k, d; cin >> n >> k >> d;
	dp[0][0] = sum[0][0] = 1;
	for (int i = 1; i <= k; i++){ sum[0][i] = sum[0][i-1] + dp[0][i]; }
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= k; j++){
			dp[i][j] = i>=j ? sum[i-j][j] : 0;
			for (int l = 1; l < j; l++){
				dp[i][j] += dp[i-l][j]; dp[i][j] %= mod;
			}
		}
		for (int j = 1; j <= k; j++){ sum[i][j] = sum[i][j-1] + dp[i][j]; sum[i][j] %= mod; }
	}
	cout << (sum[n][k] - sum[n][d-1] + mod) % mod;
}

int main(){
#ifndef DEBUG
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	cout.setf(ios::fixed);
	cout.precision(0);
	Main();
}