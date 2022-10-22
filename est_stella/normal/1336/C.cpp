#include<bits/stdc++.h>  
using namespace std;  
  
#define fast ios::sync_with_stdio(false);cin.tie(NULL)  
#define fi first  
#define se second  
#define all(v) (v).begin(),(v).end()  
#define pb push_back  
#define eb emplace_back
#define pre(a) cout<<fixed; cout.precision(a)
#define mp make_pair
  
typedef long long ll;  
typedef pair<int,int> pii;  
typedef pair<ll,ll> pll;  
const long long INF = 1e18;  
const int inf = 1e9;
const ll Mod = 998244353;

int n, m;
string s;
string t;
ll dp[3010][3010];
ll dt[3010][3010];
ll p[3010];
ll ans;

int main() {
	cin >> s;
	cin >> t;

	n = s.size();
	m = t.size();

	s = "*" + s;
	t = "*" + t;

	for(int i=1; i<=m; i++) {
		if(s[1] == t[i]) dp[i][i] = 2;
	}

	for(int i=2; i<=m; i++) {
		for(int j=1; j<=m; j++) {
			if(s[i] == t[j]) {
				if(j-i+1 >= 1) {
					dp[j-i+1][j] += dp[j-i+1][j-1];
					dp[j-i+1][j] %= Mod;
				}
				if(j+i-1 <= m) {
					dp[j][j+i-1] += dp[j+1][j+i-1];
					dp[j][j+i-1] %= Mod;
				}
			}
		}
	}

	for(int i=n+1; i>=2; i--) {
		dt[i][0] = (n - i + 2);
	}

	for(int i=n; i>=2; i--) {
		for(int j=1; j<=m; j++) {
			dt[i][j] += dt[i+1][j];
			if(s[i] == t[j]) {
				dt[i][j] += dt[i+1][j-1];
			}

			dt[i][j] %= Mod;
		}
	}

	for(int i=1; i<=m; i++) {
		ll k = dp[m-i+1][m-1];
		if(i == 1 && t[m] == s[1]) k = 2;
		if(t[m] != s[i]) k = 0;

		ans += k * dt[i+1][m-i] % Mod;
		ans %= Mod;
	}

	p[0] = 1;
	for(int i=1; i<=n; i++) {
		p[i] = p[i-1] * 2 % Mod;
	}

	for(int i=2; i<=n; i++) {
		ans += (dt[i][m] - dt[i+1][m]) * p[i-1] % Mod;
		ans %= Mod;
	}

	cout << ans;
}