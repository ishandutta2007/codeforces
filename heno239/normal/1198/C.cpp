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
typedef vector<int> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;

struct edge {
	int to, id;
};
vector<edge> G[1 << 19];
bool used[1 << 19];
void solve() {
	int t; cin >> t;
	rep(aa, t) {
		int n,m; cin >> n>>m;
		rep(i, 3*n) {
			G[i].clear(); used[i] = false;
		}
		rep(i, m) {
			int a, b; cin >> a >> b; a--; b--;
			G[a].push_back({ b,i });
			G[b].push_back({ a,i });
		}
		vector<int> ans;
		rep(i, 3*n) {
			if (used[i])continue;
			rep(j, G[i].size()) {
				int to = G[i][j].to;
				if (!used[to]) {
					ans.push_back(G[i][j].id);
					used[i] = used[to] = true;
					break;
				}
			}
		}
		if (ans.size() >= n) {
			cout << "Matching" << endl;
			rep(i, n) {
				if (i > 0)cout << " ";
				cout << ans[i]+1;
			}
			cout << endl;
		}
		else {
			vector<int> ind;
			rep(i, 3*n)if (!used[i])ind.push_back(i);
			cout << "IndSet" << endl;
			rep(i, n) {
				if (i > 0)cout << " ";
				cout << ind[i]+1;
			}
			cout << endl;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//cout << fixed << setprecision(10);
	//init();
	solve();
	//stop
	return 0;
}