#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string S; cin >> S;
	vector<ll> dp(11);
	ll res = 0;
	for (char c : S) {
		vector<ll> ndp(11);
		int ind = 10;
		for (int i = 0; i < 11; i++) {
			if (c - '0' < i) {
				//if (dp[i]) cerr << i << ' ' << c << ' ' << ind + c - '0' << '\n';
				ndp[(ind + c - '0') % 11] += dp[i];
			}
			ind += i;
		}
		assert(ind == 10 + 55);
		if (c != '0') {
			ndp[c - '0'] ++;
		}
		dp = ndp;
		for (int i = 0; i < 11; i++) res += dp[i];
		//for (int i = 0; i < 11; i++)  { cerr << dp[i] << ' '; } cerr << '\n';
	}
	cout << res << '\n';
}