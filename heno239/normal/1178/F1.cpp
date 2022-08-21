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
typedef vector<LP> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;

struct SegT {
private:
	int sz; vector<int> node;
	const int init_c = mod;
public:
	void init(vector<int> v) {
		int n = v.size();
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
		rep(i, n) {
			node[i + sz - 1] = v[i];
		}
		per(i, sz - 1) {
			node[i] = f(node[2 * i + 1], node[2 * i + 2]);
		}
	}
	int f(int a, int b) {
		return min(a, b);
	}
	void update(int k, int a) {
		k += sz - 1;
		node[k] = a;
		while (k > 0) {
			k = (k - 1) / 2;
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	int query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = sz;
		if (r <= a || b <= l)return init_c;
		else if (a <= l && r <= b)return node[k];
		else {
			int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
};

vector<vector<int>> loc;
vector<int> c;
SegT st;
int le[500], ri[500];

//map<P,bool>used;
bool used[500][500];
//map<P, ll> memo;
ll memo[500][500];

ll memo2[500];
bool used2[500];

ll dfs(int l, int r) {
	if (l >= r)return 1;
	//if (used[{l, r}])return memo[{l, r}];
	if (used[l][r])return memo[l][r];
	//used[{l, r}] = true;
	used[l][r] = true;
	int id = st.query(l, r + 1);
	ll ret = 1;
	if (used2[id]) {
		ret = memo2[id];
	}
	else {
		rep(j, (int)loc[id].size() - 1) {
			int nl = loc[id][j] + 1; int nr = loc[id][j + 1] - 1;
			ret = ret * dfs(nl, nr) % mod;
		}
		used2[id] = true;
		memo2[id] = ret;
	}
	ll lesum = 0;
	ll risum = 0;
	{
		int nr = loc[id][0] - 1;
		int nl = le[id];
		lesum = dfs(l,nl-1)*dfs(nl,nr)%mod;
		while (nl > l) {
			nl = le[c[nl - 1]];
			lesum = (lesum + dfs(l,nl-1)*dfs(nl, nr)) % mod;
		}
	}
	{
		int nl = loc[id].back()+1;
		int nr = ri[id];
		risum = dfs(nl, nr)*dfs(nr+1,r)%mod;
		while (nr < r) {
			nr = ri[c[nr + 1]];
			risum = (risum + dfs(nl, nr)*dfs(nr+1,r)) % mod;
		}
	}
	ret = ret * lesum%mod;
	ret = ret * risum%mod;
	return memo[l][r] = ret;
}
void solve() {
	int n, m; cin >> n >> m;
	loc.resize(n); c.resize(m);
	rep(i, m) {
		cin >> c[i]; c[i]--;
		loc[c[i]].push_back(i);
	}
	st.init(c);
	rep(i, n) {
		rep(j, (int)loc[i].size() - 1) {
			int nl = loc[i][j];
			int nr = loc[i][j + 1];
			int z = st.query(nl + 1, nr);
			if (z < i) {
				cout << 0 << endl; return;
			}
		}
	}
	per(i, n) {
		if (loc[i].empty())continue;
		le[i] = loc[i][0];
		ri[i] = loc[i].back();
		for (int j = i + 1; j < n; j++) {
			if (loc[j].empty())continue;
			if (le[i] <= le[j] && le[j] <= ri[i]) {
				ri[i] = max(ri[i], ri[j]);
			}
			if (le[i] <= ri[j] && ri[j] <= ri[i]) {
				le[i] = min(le[i], le[j]);
			}
		}
	}
	cout << dfs(0, m - 1) << endl;
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