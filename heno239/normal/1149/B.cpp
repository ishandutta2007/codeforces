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
typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef double ld;
typedef complex<ld> Point;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second

string s; int n;
int nex[100002][26];
string a[3]; int lensum;

int dp[251][251][251];
vector<int> loc[26];

void solve() {
	int q; cin >> n >> q;
	cin >> s;
	rep(i, n) {
		loc[s[i] - 'a'].push_back(i);
	}
	rep(i, n) {
		rep(j, 26) {
			int id = lower_bound(loc[j].begin(), loc[j].end(), i) - loc[j].begin();
			if (id == loc[j].size())nex[i][j] = n+1;
			else nex[i][j] = loc[j][id];
		}
	}
	rep(j, 26)nex[n][j] =nex[n+1][j]= n+1;
	rep(i, 251) {
		rep(j, 251) {
			rep(k, 251)dp[i][j][k] = n+1;
		}
	}
	dp[0][0][0] = 0;
	bool yes = true;
	rep(aa, q) {
		char t; cin >> t;
		if (t == '+') {
			int id; char al; cin >> id >> al; id--;
			int len = a[id].length();
			a[id].push_back(al);
			if (id == 2) {
				int l1 = a[0].length(), l2 = a[1].length();
				rep(i, l1+1) {
					rep(j, l2+1) {
						dp[i][j][len + 1] = min(dp[i][j][len + 1], nex[dp[i][j][len]][al - 'a']+1);

					}
				}
				rep(i, l1 + 1) {
					rep(j, l2 + 1) {
						if (i < l1) {
							dp[i + 1][j][len+1] = min(dp[i + 1][j][len+1], nex[dp[i][j][len+1]][a[0][i]-'a'] + 1);
						}
						if (j < l2) {
							dp[i][j+1][len+1] = min(dp[i][j+1][len+1], nex[dp[i][j][len+1]][a[1][j] - 'a'] + 1);
						}
					}
				}
				yes = (dp[l1][l2][len+1] <= n);
			}
			else if (id == 1) {
				int l1 = a[0].length(), l2 = a[2].length();
				rep(i, l1 + 1) {
					rep(j, l2 + 1) {
						dp[i][len+1][j] = min(dp[i][len+1][j], nex[dp[i][len][j]][al - 'a'] + 1);

					}
				}
				rep(i, l1 + 1) {
					rep(j, l2 + 1) {
						if (i < l1) {
							dp[i + 1][len+1][j] = min(dp[i + 1][len+1][j], nex[dp[i][len+1][j]][a[0][i] - 'a'] + 1);
						}
						if (j < l2) {
							dp[i][len + 1][j + 1] = min(dp[i][len + 1][j + 1], nex[dp[i][len+1][j]][a[2][j] - 'a'] + 1);
						}
					}
				}
				yes = (dp[l1][len+1][l2] <= n);
			}
			else {
				int l1 = a[1].length(), l2 = a[2].length();
				rep(i, l1 + 1) {
					rep(j, l2 + 1) {
						dp[len+1][i][j] = min(dp[len+1][i][j], nex[dp[len][i][j]][al - 'a'] + 1);

					}
				}
				rep(i, l1 + 1) {
					rep(j, l2 + 1) {
						if (i < l1) {
							dp[len + 1][i + 1][j] = min(dp[len + 1][i + 1][j], nex[dp[len+1][i][j]][a[1][i] - 'a'] + 1);
						}
						if (j < l2) {
							dp[len+1][i][j + 1] = min(dp[len+1][i][j + 1], nex[dp[len+1][i][j]][a[2][j] - 'a'] + 1);
						}
					}
				}
				yes = (dp[len+1][l1][l2] <= n);
			}
		}
		else {
			lensum--;
			int id; cin >> id; id--; a[id].pop_back();
			int len = a[id].size(); len++;
			if (id == 0) {
				int l1 = a[1].length(), l2 = a[2].length();
				rep(i, l1+1) {
					rep(j, l2+1) {
						dp[len][i][j] = n+1;
					}
				}
			}
			if (id == 1) {
				int l1 = a[0].length(), l2 = a[2].length();
				rep(i, l1 + 1) {
					rep(j, l2 + 1) {
						dp[i][len][j] = n+1;
					}
				}
			}
			if (id == 2) {
				int l1 = a[0].length(), l2 = a[1].length();
				rep(i, l1 + 1) {
					rep(j, l2 + 1) {
						dp[i][j][len] = n+1;
					}
				}
			}
			yes = (dp[a[0].length()][a[1].length()][a[2].length()] <= n);
		}
		if (yes) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
		return 0;
}