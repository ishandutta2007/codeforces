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
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-5;
const ld pi = acos(-1.0);

struct SegT {
private:
	int n;
	vector<LP> node; vector<ll> lazy;
	const LP init_c = { -INF,0 };
public:
	SegT(vector<ll> x) {
		int sz = x.size();
		n = 1;
		while (n < sz)n <<= 1;
		node.resize(2 * n - 1, init_c);
		lazy.resize(2 * n - 1, 0);
		rep(i, sz) {
			node[i + n - 1] = { -x[i],i };
		}
		per(i, n - 1) {
			node[i] = f(node[2 * i + 1], node[2 * i + 2]);
		}
	}
	LP f(LP a, LP b) {
		return max(a, b);
	}
	void eval(int k, int l, int r) {
		node[k].first += lazy[k];
		if (r - l > 1) {
			lazy[2 * k + 1] += lazy[k];
			lazy[2 * k + 2] += lazy[k];
		}
		lazy[k] = 0;
	}
	void add(ll x, int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return;
		if (a <= l && r <= b) {
			lazy[k] += x; eval(k, l, r);
		}
		else {
			add(x, a, b, k * 2 + 1, l, (l + r) / 2);
			add(x, a, b, k * 2 + 2, (l + r) / 2, r);
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	LP query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return init_c;
		if (a <= l && r <= b)return node[k];
		else {
			LP vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			LP vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
};

void solve() {
	int n; cin >> n;
	vector<ll> v;
	vector<pair<int, P>> u;
	rep(i, n) {
		int x, y, c; cin >> x >> y >> c;
		int mi = min(x, y);
		v.push_back(mi);
		int dif = max(x - mi, y - mi);
		v.push_back(mi + dif);
		u.push_back({ mi,{ mi + dif,c } });
	}
	map<int, int> mp;
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	rep(i, v.size())mp[v[i]] = i;
	SegT st(v);
	sort(u.begin(), u.end(), greater<pair<int, P>>());
	ll ma = 0; int x1 = mod, d1 = mod;
	rep(i, u.size()) {
		int le = i;
		while (i + 1 < u.size() && u[i].first == u[i + 1].first)i++;
		Rep1(j, le, i) {
			int loc = mp[u[j].second.first];
			int c = u[j].second.second;
			st.add(c, loc, v.size());
			//cout << u[j].first << endl;
		}
		LP p = st.query(mp[u[i].first], v.size());
		p.first += u[i].first;
		//cout << u[i].first<<" "<<p.first << endl;
		if (ma < p.first) {
			ma = p.first; x1 = u[i].first;
			d1 = v[p.second];
		}
	}
	cout << ma << endl;
	cout << x1 << " " << x1 << " " << d1 << " " << d1 << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}