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
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-6;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;

void debug(vec &v) {
	int n = v.size();
	rep(i, n) {
		if (i > 0)cout << " ";
		cout << v[i];
	}
	cout << "\n";
}

ll mod_pow(ll x, ll n) {
	ll ret = 1;
	while (n > 0) {
		if (n % 2)ret = ret * x%mod;
		x = x * x%mod; n >>= 1;
	}
	return ret;
}

struct edge {
	int to, id;
};
vector<edge> G[101];

ll alf[101][26];
vector<string> ealf;

void yaru(int n) {
	cout << "? " << 1 << " " << n << endl;
	rep1(i, n)rep(j, 26)alf[i][j] = 0;
	vector<vector<string>> v(n + 1);
	string alfs;
	rep(i, n*(n + 1) / 2) {
		string s; cin >> s;
		v[s.size()].push_back(s);
		if (s.size() == 1)alfs += s;
	}
	ealf.push_back(alfs);
	rep1(i, n) {
		rep(j, v[i].size()) {
			rep(k, v[i][j].size()) {
				alf[i][v[i][j][k] - 'a']++;
			}
		}
	}
	int alxor = 0;
	rep(i, 26)if (alf[1][i] % 2)alxor ^= i;
	for (int i = 1; i <= n / 2; i++) {
		rep(j, 26) {
			alf[n + 1 - i][j] = alf[n + 1 - i][j] / i * (i + 1);
		}
		vector<int> rest;
		rep(j, 26) {
			int dif = alf[n + 1 - i][j] - alf[n - i][j];
			rep(k, dif)rest.push_back(j);
		}

		int xs = rest[0] ^ rest[1];
		alxor ^= xs;
		G[i - 1].push_back({ n - i,xs });
		G[n - i].push_back({ i - 1,xs });
		
		rep(j, 2) {
			int x = rest[j];
			rep1(k, n) {
				alf[k][x] -= i;
			}
		}
	}
}

bool used[100];
int ret[100];

void dfs(int v) {
	rep(j, G[v].size()) {
		edge &e = G[v][j];
		if (used[e.to])continue;
		used[e.to] = true;
		ret[e.to] = ret[v] ^ e.id;
		dfs(e.to);
	}
}
void solve() {
	int n; cin >> n;
	if (n <= 3) {
		string ans;
		rep1(i, n) {
			cout << "? " << i << " " << i << endl;
			char t; cin >> t; ans.push_back(t);
		}
		cout << "! "<<ans << endl;
		return;
	}
	int mid = (n + 1) / 2;
	yaru(mid);
	yaru(mid - 1);
	yaru(n);
	int alf[2][26] = {};
	rep(i, 2) {
		rep(j, ealf[i].size()) {
			alf[i][ealf[i][j] - 'a']++;
		}
	}
	int m;
	rep(j, 26)if (alf[0][j] != alf[1][j])m = j;
	used[mid-1] = true; ret[mid-1] = m;
	dfs(mid-1);
	string out; out.resize(n);
	rep(i, n) {
		out[i] = 'a' + ret[i];
	}
	cout << "! " << out << endl;
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(17);
	//init();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	stop
		return 0;
}