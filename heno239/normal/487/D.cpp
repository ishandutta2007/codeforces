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
const ld eps = 1e-6;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;

typedef vector<int> vec;

int m;

struct SegT {
private:
	int sz; vector<vec> node;
	vec init_c;
public:
	SegT(vector<vec> &v) {
		int n = v.size();
		rep(i, m)init_c.push_back(i);
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
		rep(i, n) {
			node[i+sz-1] = v[i];
		}
		per(i, sz - 1) {
			node[i] = f(node[2 * i + 1], node[2 * i + 2]);
		}
	}
	vec f(vec &a, vec &b) {
		vec ret(m);
		rep(i, m) {
			if (b[i] < 0 || b[i] >= m) {
				ret[i] = b[i];
			}
			else {
				ret[i] = a[b[i]];
			}
		}
		return ret;
	}
	void update(int k, vec a) {
		k += sz - 1;
		node[k] = a;
		while (k > 0) {
			k = (k - 1) / 2;
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	vec query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = sz;
		if (r <= a || b <= l)return init_c;
		else if (a <= l && r <= b)return node[k];
		else {
			vec vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			vec vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
};

int n, q;

char mp[100000][10];

bool used[100000][10];
vector<vec> ans;

int dfs(int x, int y,char z) {
	if (y < 0) {
		return -1 - x;
	}
	else if (y >= m) {
		return m + x + 1;
	}
	else if (x < 0) {
		return y;
	}
	if (used[x][y])return ans[x][y];
	used[x][y] = true;
	int ret;
	if (mp[x][y] == '<') {
		if (z == '>') {
			ret = mod;
		}
		else {
			ret = dfs(x, y - 1, '<');
		}
	}
	else if (mp[x][y] == '>') {
		if (z == '<') {
			ret = mod;
		}
		else {
			ret = dfs(x, y + 1, '>');
		}
	}
	else {
		dfs(x - 1, y, '^'); ret = y;
	}
	return ans[x][y] = ret;
}




void solve() {
	cin >> n >> m >> q;
	rep(i, n) {
		rep(j, m) {
			cin >> mp[i][j];
		}
	}
	ans.resize(n); rep(i, n)ans[i].resize(m);
	rep(i, n) {
		rep(j, m) {
			if (used[i][j])continue;
			dfs(i, j, '?');
		}
	}
	//cout << ans[1][0] << " "<<ans[0][0] << endl;
	/*rep(i, n) {
		rep(j, m) {
			if (j > 0)cout << " ";
			cout << ans[i][j];
		}
		cout << endl;
	}*/
	SegT st(ans);
	while (q--) {
		char t; cin >> t;
		if (t == 'A') {
			int x, y; cin >> x >> y; x--; y--;
			vec v = st.query(0, x + 1);
			//rep(i, m) {
			//	//cout << v[i] << endl;
			//}
			int ans = v[y];
			//cout << "hello "<<ans << endl;
			if (ans == mod) {
				cout << "-1 -1" << endl;
			}
			else if (ans < 0) {
				cout << (-ans) << " " << 0 << endl;
			}
			else if (ans >= m) {
				cout << ans - m << " " << m + 1 << endl;
			}
			else {
				cout << 0 << " " << ans + 1 << endl;
			}
		}
		else {
			int x, y; char z; cin >> x >> y >> z; x--; y--;
			mp[x][y] = z;
			rep(i, m) {
				used[x][i] = false;
			}
			rep(i, m) {
				if (used[x][i])continue;
				dfs(x, i, '?');
			}
			st.update(x, ans[x]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}