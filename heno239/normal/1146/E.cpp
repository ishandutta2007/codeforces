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
typedef vector<int> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;

struct SegT {
private:
	int sz; vector<P> node;
	const P init_c = { 0,1 };
public:
	SegT(int n) {
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
	}
	P f(P a, P b) {
		P ret;
		if (a.first == 0)ret.first = b.first;
		else ret.first = b.second;
		if (a.second == 0)ret.second = b.first;
		else ret.second = b.second;
		return ret;
	}
	void update(int k, P a) {
		k += sz - 1;
		node[k] = a;
		while (k > 0) {
			k = (k - 1) / 2;
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	P query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = sz;
		if (r <= a || b <= l)return init_c;
		else if (a <= l && r <= b)return node[k];
		else {
			P vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			P vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
};

vector<int> pans(1<<17), nans(1<<17);
typedef pair<char, int> speP;
vector<pair<int,speP>> loc[1 << 17];
void solve() {
	int n, q; cin >> n >> q;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	SegT st(q);
	vector<speP> s(q);
	rep(i, q) {
		cin >> s[i].first >> s[i].second;
		loc[abs(s[i].second)].push_back({ i,s[i] });
		if (s[i].first == '<'&&s[i].second >= 0) {
			st.update(i, { 1,0 });
		}
		if (s[i].first == '>'&&s[i].second <= 0) {
			st.update(i, { 1,0 });
		}
	}
	rep(i, 100001) {
		rep(j, loc[i].size()) {
			int id = loc[i][j].first;
			char t = loc[i][j].second.first;
			int x = loc[i][j].second.second;
			if (t == '<'&&x >= 0) {
				st.update(id,{ 1,1 });
			}
			if (t == '>'&&x <= 0) {
				st.update(id, { 0,0 });
			}
		}
		P v = st.query(0, q);
		if (v.first == 0)nans[i] = -i;
		else nans[i] = i;
		if (v.second == 0)pans[i] = -i;
		else pans[i] = i;

		rep(j, loc[i].size()) {
			int id = loc[i][j].first;
			char t = loc[i][j].second.first;
			int x = loc[i][j].second.second;
			if (t == '<'&&x <= 0) {
				st.update(id, { 1,1 });
			}
			if (t == '>'&&x >= 0) {
				st.update(id, { 0,0 });
			}
		}
	}
	rep(i, n) {
		if (i > 0)cout << " ";
		if (a[i] >= 0) {
			cout << pans[a[i]];
		}
		else {
			cout << nans[-a[i]];
		}
	}
	cout << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(10);
	//init();
	solve();
	//cout << "finish" << endl;
	//stop
	return 0;
}