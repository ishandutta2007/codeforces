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
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
#include<complex>
using namespace std;
 
#define int long long
typedef long long ll;
 
typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 998244353;
const ll INF = mod * mod;
typedef pair<int, int>P;
typedef pair<int, bool> sP;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<ll> vec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-5;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;
 
vector<int> a[15];
map<int, P> mp;
P need[15][5000];
ll sums[15];
 
P G[1 << 15];
 
int pre[1 << 15];
bool exi[1 << 15];
void solve() {
	int n; cin >> n;
	ll sum = 0;
 
	rep(i, n) {
		int len; cin >> len;
		a[i].resize(len);
		rep(j, len) {
			cin >> a[i][j];
			sum += a[i][j];
			mp[a[i][j]] = { i,j };
		}
	}
	if (sum%n != 0) {
		cout << "No" << endl; return;
	}
	ll res = sum / n;
	rep(i, n) {
		rep(j, a[i].size()) {
			sums[i] += a[i][j];
		}
	}
	rep(i, n) {
		ll ad = res - sums[i];
		rep(j, a[i].size()) {
			int x = a[i][j];
			if (mp.find(x + ad) == mp.end()) {
				need[i][j] = { -1,-1 };
			}
			else {
				need[i][j] = mp[x + ad];
			}
		}
	}
	rep(i, (1 << n))G[i] = { -1,-1 };
	rep(i, n) {
		rep(j, a[i].size()) {
			vector<int> used(n, -1);
			used[i] = j;
			P cur = { i,j };
			int s = (1 << i);
			bool ok = true;
			vector<P> memo;
			memo.push_back(cur);
			while (true) {
				P nex = need[cur.first][cur.second];
				memo.push_back(nex);
				if (nex.first < 0) {
					ok = false; break;
				}
				if (used[nex.first] >= 0) {
					if (used[nex.first] == nex.second) {
						break;
					}
					else {
						ok = false; break;
					}
				}
				else {
					used[nex.first] = nex.second;
					s |= (1 << nex.first);
					cur = nex;
				}
			}
			if (!ok)continue;
			s = 0;
			rep(k, memo.size()) {
				if (memo[k] == memo.back()) {
					Rep(l, k + 1, memo.size()) {
						s |= (1<<memo[l].first);
					}
					G[s] = memo[k];
					break;
				}
			}
		}
	}
	exi[0] = true;
	rep(i, (1 << n) - 1) {
		if (!exi[i])continue;
		vector<int> v;
		rep(j, n) {
			if (i&(1 << j))continue;
			v.push_back(j);
		}
		int len = v.size();
		rep(j, (1 << len)) {
			int s = 0;
			rep(k, len) {
				if (j&(1 << k)) {
					s |= (1 << v[k]);
				}
			}
			if (G[s].first >= 0) {
				pre[i^s] = i;
				exi[i^s] = true;
			}
		}
	}
	if (!exi[(1 << n) - 1]) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
		int c = (1 << n) - 1;
		vector<P> ans(n);
		while (c > 0) {
			int z = c;
			c = pre[c];
			P cur = G[z^c];
			//cout << c<<" "<<cur.first << " " << cur.second << endl;
			vector<int> used(n, -1);
			used[cur.first] = cur.second;
			while (true) {
				P nex = need[cur.first][cur.second];
				ans[nex.first] = { cur.first,nex.second };
				if (used[nex.first] >= 0) {
					if (used[nex.first] == nex.second) {
						break;
					}
				}
				else {
					used[nex.first] = nex.second;
					cur = nex;
				}
			}
		}
		rep(i, n) {
			cout << a[i][ans[i].second] << " " << ans[i].first + 1 << endl;
		}
	}
}
 
 
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init();
	solve();
	//stop
	return 0;
}