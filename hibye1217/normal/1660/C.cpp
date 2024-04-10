#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;
using ll = long long;
using ld = long double;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

const int INF = 1e9;
int dp[200020][2], ptr[30];

void Main(){
	int t; cin >> t;
	while (t--){
		string s; cin >> s; int sl = s.size(); s = " " + s;
		for (int i = 1; i <= sl; i++){ dp[i][0] = dp[i][1] = INF; }
		dp[0][0] = 0;
		for (int i = 0; i < 26; i++){ ptr[i] = 0; }
		int ans = sl, mn = 0;
		for (int i = 1; i <= sl; i++){
			if (ptr[ s[i]-'a' ] != 0){
				int j = ptr[ s[i]-'a' ];
				dp[i][0] = dp[j][1] + i-j-1;
			}
			ptr[ s[i]-'a' ] = i;
			dp[i][1] = mn;
			mn = min(mn+1, dp[i][0]);
			ans = min(ans, dp[i][0] + sl-i);
			//cout << "DP " << i << " = " << dp[i][0] << ' ' << dp[i][1] << "   " << mn << endl << flush;
		}
		cout << ans << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}