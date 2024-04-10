#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

using ll = int;
#define f first
#define s second

ll dp[155][155][155][3][3];
bool grid[155][155];
ll ccnt[3][3];
const ll mod = 1000000007;
ll n, m;
string s;

inline void add(ll& a, ll b) {
	a += b;
	while (a >= mod) a -= mod;
	while (a < 0) a += mod;
}

void clear() {
	memset(ccnt, 0, sizeof(ccnt));
}

inline void subv(ll row, ll l, ll r) {
	ccnt[0][0] = (ccnt[0][0] - dp[row][l][r][0][0] < 0 ? ccnt[0][0] - dp[row][l][r][0][0] + mod : ccnt[0][0] - dp[row][l][r][0][0]);
	ccnt[0][1] = (ccnt[0][1] - dp[row][l][r][0][1] < 0 ? ccnt[0][1] - dp[row][l][r][0][1] + mod : ccnt[0][1] - dp[row][l][r][0][1]);
	ccnt[0][2] = (ccnt[0][2] - dp[row][l][r][0][2] < 0 ? ccnt[0][2] - dp[row][l][r][0][2] + mod : ccnt[0][2] - dp[row][l][r][0][2]);
	ccnt[1][0] = (ccnt[1][0] - dp[row][l][r][1][0] < 0 ? ccnt[1][0] - dp[row][l][r][1][0] + mod : ccnt[1][0] - dp[row][l][r][1][0]);
	ccnt[1][1] = (ccnt[1][1] - dp[row][l][r][1][1] < 0 ? ccnt[1][1] - dp[row][l][r][1][1] + mod : ccnt[1][1] - dp[row][l][r][1][1]);
	ccnt[1][2] = (ccnt[1][2] - dp[row][l][r][1][2] < 0 ? ccnt[1][2] - dp[row][l][r][1][2] + mod : ccnt[1][2] - dp[row][l][r][1][2]);
	ccnt[2][0] = (ccnt[2][0] - dp[row][l][r][2][0] < 0 ? ccnt[2][0] - dp[row][l][r][2][0] + mod : ccnt[2][0] - dp[row][l][r][2][0]);
	ccnt[2][1] = (ccnt[2][1] - dp[row][l][r][2][1] < 0 ? ccnt[2][1] - dp[row][l][r][2][1] + mod : ccnt[2][1] - dp[row][l][r][2][1]);
	ccnt[2][2] = (ccnt[2][2] - dp[row][l][r][2][2] < 0 ? ccnt[2][2] - dp[row][l][r][2][2] + mod : ccnt[2][2] - dp[row][l][r][2][2]);
}

inline void addv(ll row, ll l, ll r) {
	ccnt[0][0] = (ccnt[0][0] + dp[row][l][r][0][0] >= mod ? ccnt[0][0] + dp[row][l][r][0][0] - mod : ccnt[0][0] + dp[row][l][r][0][0]);
	ccnt[0][1] = (ccnt[0][1] + dp[row][l][r][0][1] >= mod ? ccnt[0][1] + dp[row][l][r][0][1] - mod : ccnt[0][1] + dp[row][l][r][0][1]);
	ccnt[0][2] = (ccnt[0][2] + dp[row][l][r][0][2] >= mod ? ccnt[0][2] + dp[row][l][r][0][2] - mod : ccnt[0][2] + dp[row][l][r][0][2]);
	ccnt[1][0] = (ccnt[1][0] + dp[row][l][r][1][0] >= mod ? ccnt[1][0] + dp[row][l][r][1][0] - mod : ccnt[1][0] + dp[row][l][r][1][0]);
	ccnt[1][1] = (ccnt[1][1] + dp[row][l][r][1][1] >= mod ? ccnt[1][1] + dp[row][l][r][1][1] - mod : ccnt[1][1] + dp[row][l][r][1][1]);
	ccnt[1][2] = (ccnt[1][2] + dp[row][l][r][1][2] >= mod ? ccnt[1][2] + dp[row][l][r][1][2] - mod : ccnt[1][2] + dp[row][l][r][1][2]);
	ccnt[2][0] = (ccnt[2][0] + dp[row][l][r][2][0] >= mod ? ccnt[2][0] + dp[row][l][r][2][0] - mod : ccnt[2][0] + dp[row][l][r][2][0]);
	ccnt[2][1] = (ccnt[2][1] + dp[row][l][r][2][1] >= mod ? ccnt[2][1] + dp[row][l][r][2][1] - mod : ccnt[2][1] + dp[row][l][r][2][1]);
	ccnt[2][2] = (ccnt[2][2] + dp[row][l][r][2][2] >= mod ? ccnt[2][2] + dp[row][l][r][2][2] - mod : ccnt[2][2] + dp[row][l][r][2][2]);
}

inline void upd(ll row, ll l, ll r, ll v) {
	if (l < 0 || r >= m || l > r) return;
	if (v < 0) subv(row, l, r);
	else addv(row, l, r);
}

void setdp(ll row, ll l, ll r, ll s1, ll s2) {
	ll st1 = (s1 == 0 ? 3 : s1 + 1);
	for (ll ps1 = 0; ps1 < st1; ps1++) {		
		ll ns1 = (ps1 > s1 ? ps1 : s1);
		ll st2 = (s2 == 0 ? 3 : s2 + 1);
		for (ll ps2 = 0; ps2 < st2; ps2++) {
			ll ns2 = (ps2 > s2 ? ps2 : s2);
			
			dp[row][l][r][ns1][ns2] = (dp[row][l][r][ns1][ns2] + ccnt[ps1][ps2] >= mod ? dp[row][l][r][ns1][ns2] + ccnt[ps1][ps2] - mod : dp[row][l][r][ns1][ns2] + ccnt[ps1][ps2]);
		}
	}
	
	clear();
}

int main() {
	// lol
	// for (ll i = 0; i < 3; i++) for (ll j = 0; j < 3; j++) {
		// string s = "ccnt[i][j] = (ccnt[i][j] + dp[row][l][r][i][j] >= mod ? ccnt[i][j] + dp[row][l][r][i][j] - mod : ccnt[i][j] + dp[row][l][r][i][j]);";
		// for (ll k = 0; k < s.length(); k++) {
			// if (s[k] == 'i') s[k] = (char)('0' + i);
			// if (s[k] == 'j') s[k] = (char)('0' + j);
		// }
		// cout << s << endl;
	// }
	
	cin >> n >> m;
	
	for (ll i = 0; i < n; i++) {
		// cin >> s;
		for (ll j = 0; j < m; j++) {
			grid[i][j] = 1;
		}
	}
	
	auto start = high_resolution_clock::now();
	
	// n = 150;
	
	// for (ll i = 0; i < n; i++) {
		// for (ll j = 0; j < n; j++) {
			// grid[i][j] = 1;
		// }
	// }
	
	ll ans = 0;
	memset(dp, 0, sizeof(dp));
	
	for (ll i = 1; i <= n; i++) {
		for (ll j1 = 0; j1 < m; j1++) {
			for (ll j2 = j1; j2 < m; j2++) {
				if (!grid[i - 1][j2]) break;
				add(dp[i][j1][j2][0][0], 1);
			}
		}
		
		for (ll j1 = 0; j1 < m; j1++) {
			for (ll j2 = j1; j2 < m; j2++) {
				if (!grid[i - 1][j2]) break;
				clear();
				
				upd(i - 1, j1, j2, 1);
				upd(i - 1, j1 + 1, j2, -1);
				upd(i - 1, j1, j2 - 1, -1);
				upd(i - 1, j1 + 1, j2 - 1, 1);
				setdp(i, j1, j2, 0, 0);
				
				if (j2 < m - 1) {
					upd(i - 1, j1, m - 1, 1);
					upd(i - 1, j1 + 1, m - 1, -1);
					upd(i - 1, j1, j2, -1);
					upd(i - 1, j1 + 1, j2, 1);
					setdp(i, j1, j2, 0, 2);
				}
				
				if (j1 != j2) {
					upd(i - 1, j1, j2 - 1, 1);
					upd(i - 1, j1 + 1, j2 - 1, -1);
					setdp(i, j1, j2, 0, 1);
				}
				
				if (j1 > 0) {
					upd(i - 1, 0, j2, 1);
					upd(i - 1, 0, j2 - 1, -1);
					upd(i - 1, j1, j2, -1);
					upd(i - 1, j1, j2 - 1, 1);
					setdp(i, j1, j2, 2, 0);
				}
				
				if (j1 > 0 && j2 < m - 1) {
					upd(i - 1, 0, m - 1, 1);
					upd(i - 1, 0, j2, -1);
					upd(i - 1, j1, m - 1, -1);
					upd(i - 1, j1, j2, 1);
					setdp(i, j1, j2, 2, 2);
				}
				
				if (j1 != j2 && j1 > 0) {
					upd(i - 1, 0, j2 - 1, 1);
					upd(i - 1, 0, j1 - 1, -1);
					upd(i - 1, j1, j2 - 1, -1);
					setdp(i, j1, j2, 2, 1);
				}
				
				if (j1 != j2) {
					upd(i - 1, j1 + 1, j2, 1);
					upd(i - 1, j1 + 1, j2 - 1, -1);
					setdp(i, j1, j2, 1, 0);
				}
				
				if (j1 != j2 && j2 < m - 1) {
					upd(i - 1, j1 + 1, m - 1, 1);
					upd(i - 1, j1 + 1, j2, -1);
					upd(i - 1, j2 + 1, m - 1, -1);
					setdp(i, j1, j2, 1, 2);
				}
				
				if (j2 - j1 > 1) {
					upd(i - 1, j1 + 1, j2 - 1, 1);
					setdp(i, j1, j2, 1, 1);
				}
			}
		}
		
		for (ll j1 = m - 1; j1 >= 0; j1--) {
			for (ll s1 = 0; s1 < 3; s1++) {
				for (ll s2 = 0; s2 < 3; s2++) {
					ll r = 0;
					for (ll j2 = j1; j2 < m; j2++) {	
						r = (r + dp[i][j1][j2][s1][s2] >= mod ? r + dp[i][j1][j2][s1][s2] - mod : r + dp[i][j1][j2][s1][s2]);
						
						ll val = r;
						if (j1 < j2) {
							val = (val + dp[i][j1 + 1][j2][s1][s2] >= mod ? val + dp[i][j1 + 1][j2][s1][s2] - mod : val + dp[i][j1 + 1][j2][s1][s2]);
						}
						
						dp[i][j1][j2][s1][s2] = val;
					}
					add(ans, r);
				}
			}
		}
	}
	
	cout << ans << '\n';
	
	// cout << "time: " << duration_cast<duration<double>>(high_resolution_clock::now() - start).count() << '\n';
}