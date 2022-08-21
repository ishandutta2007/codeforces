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
#include<cstdlib>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int>P;
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

int p[1 << 17];
vector<int> G[1 << 17];
ll in[1 << 17], out[1 << 17];

vector<int> great[1 << 17];

void solve() {
	cin >> n >> m;
	rep(i, n) {
		p[i] = i-n;
	}
	rep(i, m) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	ll ans = 0;
	rep(i, n) {
		rep(j, G[i].size()) {
			int to = G[i][j];
			if (p[to] > p[i]) {
				in[i]++;
				great[i].push_back(to);
			}
			else {
				out[i]++;
			}
		}
		ans += in[i] * out[i];
	}
	cout << ans << endl;
	int q; cin >> q;
	rep(aa, q) {
		int v; cin >> v; v--;
		ans -= in[v] * out[v];
		rep(j, great[v].size()) {
			int to = great[v][j];
			ans -= in[to];
			out[to]--; in[to]++;
			ans += out[to];
			great[to].push_back(v);
		}
		great[v].clear();
		out[v] = G[v].size();
		in[v] = 0;

		p[v] = aa;
		//cout << "ans is ";
		cout << ans << endl;
	}
	//rep(i, n)cout << in[i] << " " << out[i] << endl;
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