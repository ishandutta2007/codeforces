#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = a-1; i >= (b); --i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll binom[100][100];

void solve() {
	ll n;
	cin >> n;
	ll awins = 0;
	rep(i,0,n) {
		if ((n-i)%4 == 1) {
			awins += binom[i][i/2];
		}
		if ((n-i)%4 == 0) {
			awins += binom[i][i/2+1];
		}
	}
	awins %= MOD;
	ll draws = 1;
	ll bwins = binom[n][n/2]-awins-draws;
	bwins %= MOD;
	if (bwins < 0)
		bwins += MOD;
	cout << awins << " " << bwins << " " << draws << endl;
}

int main() {
	rep(n,0,100)
	rep(k,0,100) {
		if (k < 0 || k > n)
			binom[n][k] = 0;
		else if (k == 0 || k == n)
			binom[n][k] = 1;
		else
			binom[n][k] = (binom[n-1][k-1]+binom[n-1][k])%MOD;
	}
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while (t--)
		solve();
}