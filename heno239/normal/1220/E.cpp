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
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-5;
const ld pi = acos(-1.0);

int n, m;
ll w[1 << 18];
vector<int> G[1 << 18];

bool canr[1 << 18];
ll score[1 << 18];
int c[1 << 18];

bool iseda[1 << 18];

ll dfs(int id, int fr) {
	ll ret = 0;
	rep(j, G[id].size()) {
		int to = G[id][j];
		if (to == fr)continue;
		ret = max(ret, dfs(to, id));
	}
	return ret + w[id];
}

ll ad = 0;
bool sear(int id, int fr) {
	rep(j, G[id].size()) {
		int to = G[id][j];
		if (to == fr)continue;
		if (!iseda[to]) {
			ad += w[id]; w[id] = 0;
			return true;
		}
		if (sear(to, id)) {
			ad += w[id]; w[id] = 0;
			return true;
		}
	}
	return false;
}


void solve() {
	cin >> n >> m;
	rep(i, n) {
		cin >> w[i];
	}
	rep(i, m) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int s; cin >> s; s--;
	queue<int> q; q.push(s); canr[s] = true;
	while (!q.empty()) {
		int id = q.front(); q.pop();
		rep(j, G[id].size()) {
			int to = G[id][j];
			if (canr[to])continue;
			canr[to] = true; q.push(to);
		}
	}
	int cnt = 0; int cnte = 0;
	rep(i, n) {
		if (canr[i]) {
			cnt++;
			cnte += G[i].size();
		}
	}
	cnte /= 2;
	if (cnt == cnte + 1) {
		ll ans = 0;
		rep(j, G[s].size()) {
			ans = max(ans, dfs(G[s][j], s));
		}
		cout << ans + w[s] << endl;
	}
	else {
		queue<int> q;
		rep(i, n) {
			if (canr[i]) {
				c[i] = G[i].size();
			}
		}
		rep(i, n) {
			if (canr[i]) {
				if (c[i] == 1) {
					q.push(i);
					iseda[i] = true;
					score[i] = 0;
				}
			}
		}
		while (!q.empty()) {
			int id = q.front(); q.pop();
			rep(j, G[id].size()) {
				int to = G[id][j];
				if (iseda[to])continue;
				score[to] = max(score[to], score[id] + w[id]);
				c[to]--;
				if (c[to] == 1) {
					q.push(to);
					iseda[to] = true;
				}
			}
		}
		//cout << "hello" << endl;
		if (iseda[s]) {
			ll ans = 0;
			ll ma = 0;
			sear(s, -1);


			rep(i, n) {
				if (canr[i] && !iseda[i]) {
					ans += w[i];
					rep(j, G[i].size()) {
						int to = G[i][j];
						if (iseda[to]) {
							ma = max(ma, dfs(to, i));
						}
					}
				}
			}
			cout << ans + ad + ma << endl;
		}
		else {
			ll ans = 0;
			ll ma = 0;
			rep(i, n) {
				if (canr[i] && !iseda[i]) {
					ans += w[i];
					rep(j, G[i].size()) {
						int to = G[i][j];
						if (iseda[to]) {
							ma = max(ma, dfs(to, i));
						}
					}
				}
			}
			cout << ans + ma << endl;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}