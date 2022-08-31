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
const ll mod = 1000000007;
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
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;

int n, k;
int a[1 << 18];
struct edge {
	int to, cost;
};
vector<int> G[200000];

vector<vector<P>> memo;
void init(int id,int fr) {
	rep(j, G[id].size()) {
		int to = G[id][j];
		if (to == fr)continue;
		init(to, id);
		memo[id].push_back({ -1,-1 });
	}
}

int inf;
bool yes = false;

P dfs(int id, int fr) {
	if (a[id] < inf) {
		return { 0,false };
	}
	P res = { 1,true };
	vector<P> nex;
	vector<int>ids;
	rep(j, G[id].size()) {
		int to = G[id][j];
		if (to == fr)continue;
		P z = dfs(to, id);
		nex.push_back(z);
		memo[id][ids.size()] = z;
		ids.push_back(to);
	}
	int ma = -1;
	rep(j, nex.size()) {
		if (nex[j].second == true) {
			res.first += nex[j].first;
		}
		else {
			ma = max(ma, nex[j].first);
		}
	}
	if (ma < 0) {
		return res;
	}
	else {
		res.second = false; res.first += ma;
	}
	return res;
}
void dfs2(int id, int fr, P frs) {
	if (fr < 0) {
		if (a[id] < inf) {
			rep(j, G[id].size()) {
				int to = G[id][j];
				dfs2(to, id, { 0,false });
			}
		}
		else {
			vector<P> v;
			vector<int> ids;
			rep(j, G[id].size()) {
				int to = G[id][j];
				v.push_back(memo[id][ids.size()]);
				ids.push_back(to);
			}
			vector<int> mal(v.size() + 1, -1);
			vector<int> mar(v.size() + 1, -1);
			rep(i, v.size()) {
				if (!v[i].second) {
					mal[i + 1] = max(mal[i], v[i].first);
				}
				else {
					mal[i + 1] = mal[i];
				}
			}
			per(i, (int)v.size()) {
				if (!v[i].second) {
					mar[i] = max(mar[i + 1], v[i].first);
				}
				else {
					mar[i] = mar[i + 1];
				}
			}
			int sum = 1;
			rep(j, v.size()) {
				if (v[j].second)sum += v[j].first;
			}
			rep(j, v.size()) {
				int to = ids[j];
				if (v[j].second) {
					int ssum = sum - v[j].first;
					int ma = max(mal[j], mar[j + 1]);
					if (ma == -1) {
						dfs2(to, id, { ssum,true });
					}
					else {
						dfs2(to, id, { ssum + ma,false });
					}
				}
				else {
					int ssum = sum;
					int ma = max(mal[j], mar[j + 1]);
					if (ma == -1) {
						dfs2(to, id, { ssum,true });
					}
					else {
						dfs2(to, id, { ssum + ma,false });
					}
				}
			}
		}
	}
	else {
		if (a[id] < inf) {
			rep(j, G[id].size()) {
				int to = G[id][j];
				if (to == fr)continue;
				dfs2(to, id, { 0,false });
			}
		}
		else {
			vector<P> v;
			vector<int> ids;
			rep(j, G[id].size()) {
				int to = G[id][j];
				if (to == fr)continue;
				if(memo[id][ids.size()].first>=0){
					v.push_back(memo[id][ids.size()]);
				}
				else {
					v.push_back(dfs(to, id));
				}
				ids.push_back(to);
			}
			v.push_back(frs);
			vector<int> mal(v.size() + 1, -1);
			vector<int> mar(v.size() + 1, -1);
			rep(i, v.size()) {
				if (!v[i].second) {
					mal[i + 1] = max(mal[i], v[i].first);
				}
				else {
					mal[i + 1] = mal[i];
				}
			}
			per(i, (int)v.size()) {
				if (!v[i].second) {
					mar[i] = max(mar[i + 1], v[i].first);
				}
				else {
					mar[i] = mar[i + 1];
				}
			}
			int sum = 1;
			rep(j, v.size()) {
				if (v[j].second)sum += v[j].first;
			}
			int mma = 0;
			rep(j, v.size()) {
				if (!v[j].second)mma = max(mma, v[j].first);
			}
			if (sum + mma >= k)yes = true;
			rep(j, v.size() - 1) {
				int to = ids[j];
				if (v[j].second) {
					int ssum = sum - v[j].first;
					int ma = max(mal[j], mar[j + 1]);
					if (ma == -1) {
						dfs2(to, id, { ssum,true });
					}
					else {
						dfs2(to, id, { ssum + ma,false });
					}
				}
				else {
					int ssum = sum;
					int ma = max(mal[j], mar[j + 1]);
					if (ma == -1) {
						dfs2(to, id, { ssum,true });
					}
					else {
						dfs2(to, id, { ssum + ma,false });
					}
				}
			}
		}
	}
}

bool can() {
	yes = false;
	P z = dfs(0, -1);
	if (z.first >= k)return true;
	dfs2(0, -1, { 0,0 });
	return yes;
}

void solve() {
	cin >> n >> k;
	rep(i, n) {
		cin >> a[i];
	}
	memo.resize(n);
	rep(i, n - 1) {
		int u, v; cin >> u >> v; u--; v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	init(0, -1);

	int le = 0, ri = 1000001;
	while (ri - le > 1) {
		int mid = (le + ri) / 2;
		rep(i, n)rep(j, memo[i].size())memo[i][j] = { -1,-1 };
		inf = mid;
		if (can()) {
			le = mid;
		}
		else {
			ri = mid;
		}
	}
	cout << le << endl;
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