#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define endl '\n'
#define all(v) v.begin(),v.end()
#define fr(p) get<0>(p)
#define sc(p) get<1>(p)
#define th(p) get<2>(p)
#define fo(p) get<3>(p)
#define fi(p) get<4>(p)
#define dec(x) cout.precision(x);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef tuple<int, int> pii;
typedef tuple<int, int, int> piii;
typedef tuple<int, int, int, int> piiii;
typedef tuple<int, int, int, int, int> piiiii;
typedef tuple<ll, ll> pll;
typedef tuple<ll, ll, ll> plll;
typedef tuple<ll, ll, ll, ll> pllll;
typedef tuple<ll, ll, ll, ll, ll> plllll;
const int N = 512;

int a[220], b[220];
bool dp[220][520];

int main(){
	Fast;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	dp[0][0] = true;
	for (int i = 1; i <= n; i++){
		bool res[520] = {};
		for (int j = 1; j <= m; j++){
			int c = a[i] & b[j];
			res[c] = true;
		}
		for (int j = 0; j < N; j++){
			for (int k = 0; k < N; k++){
				if (!dp[i-1][j] || !res[k]) continue;
				dp[i][j|k] = true;
			}
		}
		//for (int j = 0; j < 8; j++){
		//	cout << dp[i][j] << ' ';
		//}
		//cout << endl;
	}
	int ans = 1e9;
	for (int i = 0; i < N; i++) if (dp[n][i]) ans = min(ans, i);
	cout << ans;
}