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
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 998244353;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<ll> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-5;


int c[60];

bool exi[200][200];

bool used[200];
int ldist[200], rdist[200];

vector<int> G[200];
void solve() {
	int n; cin >> n;
	vector<ll> a(n);
	rep(i, n) {
		cin >> a[i];
		rep(j, 60) {
			if (a[i] & ((ll)1 << j)) {
				c[j]++;
			}
		}
	}
	rep(i, 60) {
		if (c[i] > 2) {
			cout << 3 << endl; return;
		}
	}
	vector<ll> r;
	rep(i, n) {
		if (a[i] > 0)r.push_back(a[i]);
	}
	n = r.size();
	rep(k, 60) {
		ll t = (ll)1 << k;
		rep(i, n) {
			Rep(j, i + 1, n) {
				if ((t&r[i]) > 0 && (t&r[j]) > 0) {
					exi[i][j] = exi[j][i] = true;
				}
			}
		}
	}
	rep(i, n) {
		Rep(j, i + 1, n) {
			if (exi[i][j]) {
				G[i].push_back(j);
				G[j].push_back(i);
			}
		}
	}
	ll ans = mod;
	queue<int> q;
	rep(i, n) {
		Rep(j, i + 1, n) {
			if (!exi[i][j])continue;
			fill(used, used + n, false);
			fill(ldist, ldist + n, mod);
			fill(rdist, rdist + n, mod);
			used[i] = true;
			q.push(i);
			int tmp = 0;
			while (!q.empty()) {
				int len = q.size();
				rep(aa, len) {
					int id = q.front(); q.pop();
					ldist[id] = tmp;
					rep(v, G[id].size()) {
						int to = G[id][v];
						if (id == i && to == j)continue;
						if (used[to])continue;
						used[to] = true;
						q.push(to);
					}
				}
				tmp++;
			}
			tmp = 0;
			fill(used, used + n, false);
			used[j] = true;
			q.push(j);
			while (!q.empty()) {
				int len = q.size();
				rep(aa, len) {
					int id = q.front(); q.pop();
					rdist[id] = tmp;
					rep(v, G[id].size()) {
						int to = G[id][v];
						if (id == j && to == i)continue;
						if (used[to])continue;
						used[to] = true;
						q.push(to);
					}
				}
				tmp++;
			}
			rep(k, n) {
				if (k == i || k == j)continue;
				ans = min(ans, (ll)ldist[k] + rdist[k]+1);
			}
		}
	}
	if (ans == mod)ans = -1;
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(5);
	//init();
	solve();
	//cout << "finish" << endl;
	//stop
	return 0;
}