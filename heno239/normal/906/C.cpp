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

bool exi[22][22];
int val[22];
void solve() {
	int n, m; cin >> n >> m;
	rep(i, m) {
		int a, b; cin >> a >> b; a--; b--;
		exi[a][b] =exi[b][a]= true;
	}
	rep(i, n) {
		rep(j, n)if (exi[i][j])val[i] += (1 << j);
	}
	{
		bool fin = true;
		rep(i, n) {
			Rep(j, i + 1, n) {
				if (!exi[i][j])fin = false;
			}
		}
		if (fin) {
			cout << 0 << endl; return;
		}
	}
	vector<int> dp(1 << n, mod);
	vector<P> pre(1 << n, { -1,-1 });
	rep(i, n) {
		dp[(1 << i)] = 0;
	}
	rep(i, (1 << n)) {
		//cout << i << " " << dp[i] << endl;
		if (dp[i] == mod)continue;
		rep(j, n) {
			if (i&(1 << j)) {
				int s = i | val[j];
				if (dp[i] + 1 < dp[s]) {
					dp[s] = dp[i] + 1;
					pre[s] = { i,j };
				}
			}
		}
	}
	vector<int> ids;
	int cur = (1 << n) - 1;
	while (pre[cur].first >= 0) {
		ids.push_back(pre[cur].second);
		cur = pre[cur].first;
	}
	reverse(ids.begin(), ids.end());
	cout << ids.size() << endl;
	rep(i, ids.size()) {
		if (i > 0)cout << " ";
		cout << ids[i]+1;
	}
	cout << endl;
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