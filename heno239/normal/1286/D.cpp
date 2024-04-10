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
void debug(mat &m) {
	cout << m.first.first << " " << m.first.second << endl;
	cout << m.second.first << " " << m.second.second << endl;
}

ll mod_pow(ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1)res = res * a%mod;
		a = a * a%mod; n >>= 1;
	}
	return res;
}


struct SegT {
private:
	int sz; vector<mat> node;
	const mat init_c = { {1,0},{0,1} };
public:
	SegT(int n) {
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
	}
	SegT(vector<mat> v) {
		int n = v.size();
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
		rep(i, n)node[i + sz - 1] = v[i];
		per(i, sz - 1)node[i] = f(node[2 * i + 1], node[2 * i + 2]);
	}
	mat f(mat a, mat b) {
		mat res;
		res.first.first = (b.first.first*a.first.first + b.first.second*a.second.first)%mod;
		res.first.second = (b.first.first*a.first.second + b.first.second*a.second.second) % mod;
		res.second.first = (b.second.first*a.first.first + b.second.second*a.second.first) % mod;
		res.second.second = (b.second.first*a.first.second + b.second.second*a.second.second) % mod;
		return res;
	}
	void update(int k,int id) {
		k += sz - 1;
		if (id == 0)node[k].first.first = 0;
		else if (id == 3)node[k].second.second = 0;
		else if (id == 1)node[k].second.first = 0;
		while (k > 0) {
			k = (k - 1) / 2;
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	mat query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = sz;
		if (r <= a || b <= l)return init_c;
		else if (a <= l && r <= b)return node[k];
		else {
			mat vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			mat vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			mat res = f(vl, vr);
			return f(vl, vr);
		}
	}

};

ll inv100 = mod_pow(100, mod - 2);

bool comp(pair<LP, P> a, pair<LP, P> b) {
	LP la = a.first, lb = b.first;
	if (la.first*lb.second != la.second*lb.first) {
		return la.first*lb.second < la.second *lb.first;
	}
	else return a.second < b.second;
}
void solve() {
	int n; cin >> n;
	vector<ll> x(n), v(n), p(n);
	rep(i, n) {
		cin >> x[i] >> v[i] >> p[i];
	}

	vector<pair<LP, P>> al;
	rep(i, n - 1) {
		if (v[i] > v[i + 1]) {
			LP z = { x[i + 1] - x[i] , v[i] - v[i + 1] };
			al.push_back({ z,{i,0} });
		}
		else if (v[i] < v[i + 1]) {
			LP z = { x[i + 1] - x[i],v[i + 1] - v[i] };
			al.push_back({ z,{i,3} });
		}
		LP z = { x[i + 1] - x[i],v[i + 1] + v[i] };
		al.push_back({ z,{i,1} });
	}
	vector<mat> ori;
	rep1(i, n - 1) {
		ll x1 = p[i] * inv100%mod;
		ll x2 = (100-p[i]) * inv100%mod;
		mat x = { {x1,x1},{x2,x2} };
		ori.push_back(x);
	}
	LP p0 = { p[0] * inv100%mod,(100 - p[0])*inv100%mod };
	SegT st(ori);
	sort(al.begin(), al.end(), comp);
	ll ans = 0;
	rep(i, al.size()) {
		int id = al[i].second.first;
		int t = al[i].second.second;
		mat le = st.query(0, id);
		//debug(le);
		ll cl = 0;
		if (t == 0 || t == 1) {
			cl = le.first.first*p0.first + le.first.second*p0.second;
			//cout << "! " << le.first.first << " " << le.first.second << endl;
			cl %= mod;
		}
		else {
			cl = le.second.first*p0.first + le.second.second*p0.second;
			cl %= mod;
		}
		LP p1 = { p[id + 1] * inv100%mod,(100 - p[id + 1])*inv100%mod };
		mat ri = st.query(id + 1, n - 1);
		ll cr = 0;
		if (t == 0) {
			cr = ri.first.first*p1.first + ri.second.first*p1.first;
			cr %= mod;
		}
		else {
			cr = ri.first.second*p1.second + ri.second.second*p1.second;
			cr %= mod;
		}
		ll csum = cl * cr%mod;
		//cout << id<<" "<<t<<" "<<csum*16%mod << endl;
		ll val = al[i].first.first*mod_pow(al[i].first.second, mod - 2) % mod;
		csum = csum * val % mod;
		ans += csum;
		st.update(id, t);
	}
	ans %= mod;
	cout << ans << endl;
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(17);
	//init();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	//stop
		return 0;
}