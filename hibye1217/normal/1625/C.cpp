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

// #define DEBUG

int n, l, k;
pl2 arr[520]; bool chk[520];
ll dp[520][520];

void Main(){
	cin >> n >> l >> k;
	for (int i = 1; i <= n; i++){ cin >> arr[i].fr; }
	for (int i = 1; i <= n; i++){ cin >> arr[i].sc; }
	arr[n+1] = {l, 0};
	for (int j = 0; j <= k; j++){
		for (int i = 1; i <= n; i++){
			dp[i][j] = 1e15;
			for (int l = i; l >= 1; l--){
				int cnt = i-l;
				if (j-cnt < 0){ break; }
				ll res = dp[l-1][j-cnt] + arr[l].sc*(arr[i+1].fr-arr[l].fr);
				dp[i][j] = min(dp[i][j], res);
			}
		}
	}
	ll ans = 1e15;
	for (int i = 0; i <= k; i++){ ans = min(ans, dp[n][i]); }
	cout << ans;
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