#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ld = long double;

#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
using pd2 = pair<ld, ld>;

#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

// #define DEBUG

const int N = 5000;
const ll mod = 998244353;
ll ncr[5020][5020];
ll dp[5020][5020];

typedef pair<int, pi2> pi3;
vector<pi3> v;

void Main(){
	for (int i = 0; i <= N; i++){
		for (int j = 0; j <= i; j++){
			if (j == 0 || j == i){ ncr[i][j] = 1; }
			else{ ncr[i][j] = (ncr[i-1][j] + ncr[i-1][j-1]) % mod; }
		}
	}
	int cnt = 0;
	int n, k; cin >> n >> k;
	string s; cin >> s;
	for (char c : s){ if (c == '1'){ cnt += 1; } }
	if (cnt < k){ cout << 1; return; }
	for (int i = 0; i < n; i++){
		if (s[i] == '0'){ continue; }
		int st = i-1, ed = i+1;
		while (0 <= st){ if (s[st] == '1'){ break; } st -= 1; } st += 1;
		while (ed < n){ if (s[ed] == '1'){ break; } ed += 1; } ed -= 1;
		v.push_back({ i, {st, ed} });
	}
	int vl = v.size();
	ll ans = 1;
	for (int j = 1; j <= k; j++){
		if (j == 1){
			for (int i = 0; i < vl; i++){
				int st = v[i].sc.fr, ed = v[i].sc.sc;
				dp[i][1] = ed-st+1;
				ans += dp[i][1] - 1;
				ans += mod*5; ans %= mod;
				//cout << "IJ " << i << ' ' << j << ' ' << ans << endl;
			}
		}
		else if (j == 2){
			for (int i = 0; i < vl; i++){
				int i1 = i, i2 = i+j-1;
				if (i2 >= vl){ break; }
				int st = v[i1].sc.fr, ed = v[i2].sc.sc;
				dp[i][j] = ncr[ed-st+1][j];
				ans += dp[i][j];
				ans -= dp[i][j-1] + dp[i+1][j-1];
				ans += 1;
				ans += mod*5; ans %= mod;
				//cout << "IJ " << i << ' ' << j << ' ' << ans << endl;
			}
		}
		else{
			for (int i = 0; i < vl; i++){
				int i1 = i, i2 = i+j-1;
				if (i2 >= vl){ break; }
				int st = v[i1].sc.fr, ed = v[i2].sc.sc;
				dp[i][j] = ncr[ed-st+1][j];
				ans += dp[i][j];
				ans -= dp[i][j-1] + dp[i+1][j-1];
				ans += dp[i+1][j-2];
				ans += mod*5; ans %= mod;
				//cout << "IJ " << i << ' ' << j << ' ' << ans << endl;
			}
		}
	}
	cout << ans << endl;
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