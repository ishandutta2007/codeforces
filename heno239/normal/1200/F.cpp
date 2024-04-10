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
const ld eps = 1e-8;

P nex[1000][2520];
vector<int> G[1000];
int len[1000];

int ans[1000][2520];
bool used[1000][2520];
bool subused[1000][2520];

void solve() {
	int n; cin >> n;
	vector<int> c(n);
	rep(i, n) {
		cin >> c[i];
		c[i] = (c[i] % 2520 + 2520) % 2520;
	}
	rep(i, n) {
		int m; cin >> m; len[i] = m;
		rep(j, m) {
			int to; cin >> to;
			to--;
			G[i].push_back(to);
		}
	}
	rep(i, n) {
		rep(j, 2520) {
			int id = j % len[i];
			int to = G[i][id];
			nex[i][j] = { to,(j + c[to]) % 2520 };
		}
	}
	rep(i, n) {
		rep(j, 2520) {
			if (used[i][j])continue;
			bool pass = false;
			vector<P> memo; 
			P cur = { i,j }; memo.push_back(cur); 
			subused[i][j] = true;
			while (true) {
				P to = nex[cur.first][cur.second];
				int id = to.first, jd = to.second;
				if (used[id][jd]) {
					int mem = ans[id][jd];
					rep(k, memo.size()) {
						ans[memo[k].first][memo[k].second] = mem;
						used[memo[k].first][memo[k].second] = true;
					}

					pass = true; break;
				}
				else if (subused[id][jd]) {
					P las = to;
					int chk = 0;
					set<int> ids;
					for (int k = (int)memo.size() - 1; k >= 0; k--) {
						ids.insert(memo[k].first);
						if (las == memo[k]) {
							chk = k; break;
						}
					}
					int mem = ids.size();
					rep(k, memo.size()) {
						used[memo[k].first][memo[k].second] = true;
						ans[memo[k].first][memo[k].second] = mem;
					}
					break;
				}
				else {
					cur = to;
					subused[id][jd] = true;
					memo.push_back(cur);
				}
			}
			if (pass)continue;

		}
	}
	int q; cin >> q;
	rep(i, q) {
		int x, val; cin >> x >> val; x--;
		val += c[x];
		val = (val % 2520 + 2520) % 2520;
		//cout << "ans is ";
		cout << ans[x][val] << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init();
	solve();
	//cout << "finish" << endl;
	//stop
	return 0;
}