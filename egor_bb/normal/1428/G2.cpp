#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size())
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); (i) < (b); ++i)
#define all(c) (c).begin(), (c).end()
 
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int N = 1e6;
const ll INF = 1e18;

ll dp[N], f[6], precomp[N];

ll compute(int x) {
	int pos = 0;
	ll ans = 0;
	while(x) {
		int last = x % 10;
		if (last % 3 == 0) {
			ans += f[pos] * (last / 3);
		}
		pos++;
		x /= 10;
	}
	return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int K;
	cin >> K;
	int cur = 1;
	vector<pair<ll, ll>> items;
	forn(i, 6) {
		cin >> f[i];
		int k = (K - 1) * 3;
		int mul = 1;
		while(k) {
			int cnt = 0;
			if (k % 2 == 1) {
				cnt = 1;
			} else {	
				cnt = 2;
			}
			forn(j, cnt) {
				ll val = 3 * cur * 1ll * mul;
				if (val <= N) {
					items.pb(mp(val, mul * 1ll * f[i]));
				}
			}
			k -= cnt;
			mul *= 2;
			k /= 2;
		}
		cur *= 10;
	}
	forn(i, N) {
		dp[i] = -INF;
	}
	dp[0] = 0;
	for(auto p: items) {
		fornr(i, N) {
			if (i + p.fst < N) {
				dp[i + p.fst] = max(dp[i] + p.snd, dp[i + p.fst]);
			}
		}
	}
	cur = 1;
	forn(curD, 6) {
		fornr(i, N) {
			forab(d, 1, 10) {
				int add = cur * d;
				if (i + add < N) {
					ll val = 0;
					if (d % 3 == 0) {
						val = f[curD] * (d / 3);
					}
					dp[i + add] = max(dp[i] + val, dp[i + add]);
				}
			}
		}
		cur *= 10;
	}
	int q;
	cin >> q;
	while(q--) {
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}
    return 0;
}