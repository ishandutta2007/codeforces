#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-2;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;

int n, p;
string s;
int a[17][17];
bool dp[1 << 17];
bool cop[1 << 17];

int cnt[17];
int ans[1 << 17];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> p;
	cin >> s;
	fill(dp, dp + (1 << p), true);
	fill(cop, cop + (1 << p), true);
	rep(i, n) {
		cnt[s[i] - 'a']++;
	}
	rep(i, p) {
		rep(j, p) {
			cin >> a[i][j];
		}
	}
	rep(i, p) {
		Rep(j, i + 1, p) {
			if (a[i][j])continue;
			fill(dp, dp + (1 << p), true);
			int ca = -1, cb = -1;
			rep(k, n) {
				if (s[k] == 'a' + i) {
					ca = k;
				}
				else if (s[k] == 'a' + j) {
					cb = k;
				}
				else continue;
				if (ca >= 0 && cb >= 0) {
					if (ca < cb) {
						int rec = 0;
						Rep(l, ca + 1, cb) {
							rec |= (1 << (s[l] - 'a'));
						}
						dp[(1 << p) - 1 - rec] = false;
						ca = -1;
					}
					else {
						int rec = 0;
						Rep(l, cb + 1, ca) {
							rec |= (1 << (s[l] - 'a'));
						}
						dp[(1 << p) - 1 - rec] = false;
						cb = -1;
					}
				}
			}
			per1(i1, (1 << p) - 1) {
				if ((i1&(1 << i)) == 0)continue;
				if ((i1&(1 << j)) == 0)continue;
				if (dp[i1])continue;
				rep(j1, p) {
					if (j1 == i || j1 == j)continue;
					if (i1&(1 << j1)) {
						int ni = i1 ^ (1 << j1);
						dp[ni] = false;
					}
				}
			}
			rep(i1, 1 << p) {
				cop[i1] &= dp[i1];
			}
		}
	}
	rep(i, p) {
		if (a[i][i])continue;
		fill(dp, dp + (1 << p), true);
		int loc = -1;
		rep(j, n) {
			if (s[j] != 'a' + i)continue;
			if (loc >= 0) {
				int rec = 0;
				Rep(l, loc + 1, j) {
					rec |= (1 << (s[l] - 'a'));
				}
				dp[(1 << p) - 1 - rec] = false;
			}
			loc = j;
		}
		per1(i1, (1 << p) - 1) {
			if ((i1&(1 << i)) == 0)continue;
			if (dp[i1])continue;
			rep(j1, p) {
				if (j1 == i)continue;
				if (i1&(1 << j1)) {
					int ni = i1 ^ (1 << j1);
					dp[ni] = false;
				}
			}
		}
		rep(i1, 1 << p) {
			cop[i1] &= dp[i1];
		}
	}
	rep(i1, 1 << p) {
		dp[i1] = cop[i1];
	}
	fill(ans+1, ans + (1 << p), n);
	rep1(i, (1 << p)-1) {
		if (!dp[i])continue;
		ans[i] = 0;
		rep(j, p) {
			if (i&(1 << j)) {
				ans[i] += cnt[j];
			}
		}
		rep(j, p) {
			if (i&(1 << j)) {
				int ni = i ^ (1 << j);
				ans[i] = min(ans[i], ans[ni]);
			}
		}
	}
	cout << ans[(1 << p) - 1] << endl;
	//stop
	return 0;
}