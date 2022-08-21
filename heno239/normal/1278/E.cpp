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
const ll INF = (1e+18)+7;
typedef pair<int, int>P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
typedef pair<ll, ll> LP;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-6;
const ld pi = acos(-1.0);
//typedef vector<vector<ll>> mat;
typedef vector<int> vec;

using mat = pair<LP, LP>;
void debug(vec &v) {
	int n = v.size();
	rep(i, n) {
		if (i > 0)cout << " ";
		cout << v[i];
	}
	cout << endl;
}


ll mod_pow(ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1)res = res * a%mod;
		a = a * a%mod; n >>= 1;
	}
	return res;
}

vector<int> G[1 << 19];

vector<int> dfs(int id, int fr) {
	if (fr >= 0 && G[id].size() == 1) {
		return { id,id };
	}
	vector<vector<int>> nexs;
	int ma = 0;
	vector<int> b;
	rep(j, G[id].size()) {
		int to = G[id][j];
		if (to == fr)continue;
		vector<int> nex = dfs(to, id);
		if (nex.size() > ma) {
			ma = nex.size();
			swap(b, nex);
		}
		if (nex.size())nexs.push_back(nex);
	}
	//cout << "!!" << endl;
	//debug(b);
	int cop = b.back(); b.pop_back();
	rep(i, nexs.size()) {
		rep(j, (int)nexs[i].size() - 1) {
			b.push_back(nexs[i][j]);
		}
	}
	b.push_back(id);
	per(i, (int)nexs.size()) {
		b.push_back(nexs[i].back());
	}
	b.push_back(cop);
	b.push_back(id); 

	return b;
}

void solve() {
	int n; cin >> n;
	if (n == 1) {
		cout << "1 2" << endl; return;
	}
	rep(i, n-1) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector<int> ori = dfs(0, -1);
	vector<vector<int>> loc(n);
	rep(i, 2 * n) {
		//cout << ori[i] << endl;
		loc[ori[i]].push_back(i);
	}
	rep(i, n) {
		int l = loc[i][0], r = loc[i][1];
		cout << l + 1 << " " << r + 1 << "\n";
	}
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