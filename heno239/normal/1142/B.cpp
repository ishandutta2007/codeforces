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
using namespace std;
typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
typedef complex<ld> Point;
const ll mod = 1000000007;
const ll INF = mod * mod;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)

struct SegT {
private:
	int sz; vector<int> node;
	const int init_c = mod;
public:
	SegT(vector<int> c) {
		int n = c.size();
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
		rep(i, n) {
			node[sz - 1 + i] = c[i];
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

int par[1 << 18][18];
vector<int> loc[1 << 18];
void solve() {
	int n, m, q; cin >> n >> m >> q;
	vector<int> p(n), invp(n);
	rep(i, n) {
		cin >> p[i]; p[i]--;
		invp[p[i]] = i;
	}
	vector<int> a(m);
	rep(i, m) {
		cin >> a[i]; a[i]--;
		loc[a[i]].push_back(i);
	}
	rep(i, n)loc[i].push_back(m);
	rep(i, m) {
		int z = invp[a[i]]; z++; if (z == n)z = 0;
		z = p[z];
		int id = upper_bound(loc[z].begin(), loc[z].end(), i) - loc[z].begin();
		par[i][0] = loc[z][id];
	}
	rep(i, 18)par[m][i] = m;
	rep1(i, 17) {
		rep(j, m) {
			par[j][i] = par[par[j][i - 1]][i - 1];
		}
	}
	vector<int> v;
	rep(i, 18) {
		if ((n - 1)&(1 << i)) {
			v.push_back(i);
		}
	}
	vector<int> ri(m);
	rep(i, m) {
		int cur = i;
		rep(j, v.size()) {
			cur = par[cur][v[j]];
		}
		ri[i] = cur;
	}
	SegT st(ri);
	string ans;
	rep(i, q) {
		int l, r; cin >> l >> r; l--; r--;
		int u = st.query(l, r + 1);
		if (r < u)ans.push_back('0');
		else ans.push_back('1');
	}
	cout << ans << endl;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
	//stop
	return 0;
}