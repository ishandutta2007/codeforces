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

ll arr[2020];
ll dp[2020][2020];

void Main(){
	memset(dp, -1, sizeof(dp));
	int n; cin >> n;
	for (int i = 1; i <= n; i++){ cin >> arr[i]; }
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= i; j++){
			dp[i][j] = dp[i-1][j];
			if (j != 0 && dp[i-1][j-1] != -1 && dp[i-1][j-1]+arr[i] >= 0){
				dp[i][j] = max(dp[i][j], dp[i-1][j-1] + arr[i]);
			}
		}
	}
	for (int i = n; i >= 0; i--){
		if (dp[n][i] != -1){ cout << i; return; }
	}
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