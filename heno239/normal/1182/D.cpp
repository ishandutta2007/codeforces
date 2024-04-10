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
#include<cassert>
using namespace std;

typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
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
const ld eps = 1e-4;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
typedef vector<int> vec;
typedef vector<string> svec;

int n;
vector<int> G[1 << 17];

vector<int> depth;
void dfs(int id, int fr, int k) {
	depth[id] = k;
	rep(j, G[id].size()) {
		int to = G[id][j];
		if (to == fr)continue;
		dfs(to, id, k + 1);
	}
}
int par[1 << 17];
void solve() {
	cin >> n;
	fill(par, par + n, -1);
	vector<int> cntfr(n, 0);
	depth.resize(n, 0);
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	queue<int> q;
	vector<bool> used(n, false);
	rep(i, n) {
		if (G[i].size() == 1)q.push(i), used[i] = true;
	}
	if (q.size() == 2) {
		cout << q.front() + 1 << endl; return;
	}
	int root = 0;
	while (!q.empty()) {
		int len = q.size();
		vector<int> rnex;
		vector<P> nex,nex2;
		rep(aa, len) {
			int id = q.front(); q.pop();
			root = id;
			rep(j, G[id].size()) {
				int to = G[id][j];
				cntfr[to]++;
				if (!used[to]) {
					used[to] = true;
					q.push(to);
					par[to] = id;
					rnex.push_back(to);
				}
			}
		}
		rep(j, rnex.size()) {
			nex.push_back({ cntfr[rnex[j]],rnex[j] });
			nex2.push_back({ G[rnex[j]].size(),rnex[j] });
		}
		sort(nex.begin(), nex.end());
		sort(nex2.begin(), nex2.end());
		rep(j, (int)nex.size() - 1) {
			if (nex[j].first != nex[j + 1].first) {
				if (j > 0) {
					root = nex[j + 1].second;
				}
				else {
					root = nex[j].second;
				}
				while (par[root] >= 0)root = par[root];
				while (!q.empty())q.pop();
				break;
			}
		}
		if (q.empty())break;
		rep(j, (int)nex2.size() - 1) {
			if (nex2[j].first != nex2[j + 1].first) {
				if (j > 0) {
					root = nex2[j + 1].second;
				}
				else {
					root = nex2[j].second;
				}
				while (par[root] >= 0)root = par[root];
				while (!q.empty())q.pop();
				break;
			}
		}
	}
	dfs(root, -1, 0);
	vector<P> v;
	rep(i, n) {
		v.push_back({ depth[i],i });
	}
	sort(v.begin(), v.end());
	rep(i, n - 1) {
		if (v[i].first == v[i + 1].first) {
			if (G[v[i].second].size() != G[v[i + 1].second].size()) {
				cout << -1 << endl; return;
			}
		}
	}
	cout << root + 1 << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(11);
	/*while (cin >> n, n) {
		solve();
	}*/
	solve();
	//stop
	return 0;
}