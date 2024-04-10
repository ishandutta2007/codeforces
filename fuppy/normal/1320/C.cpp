#include <bits/stdc++.h>
 
//#include <unistd.h>
//#include <iostream>
 
using namespace std;
 
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl;
#define DEBUG_MAT(v) cerr<<#v<<endl;for(int i=0;i<v.size();i++){for(int j=0;j<v[i].size();j++) {cerr<<v[i][j]<<" ";}cerr<<endl;}
typedef long long ll;
//#define int ll
 
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
template<class S, class T> pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first + t.first, s.second + t.second); }
template<class S, class T> pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first - t.first, s.second - t.second); }
template<class S, class T> ostream& operator<<(ostream& os, pair<S, T> p) { os << "(" << p.first << ", " << p.second << ")"; return os; }
#define X first
#define Y second
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(n);i>0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(),c.end()
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = (ll)1e18 + 1;
const long double pi = 3.1415926535897932384626433832795028841971L;
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl;
//int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
//int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
vi dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
vi dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
const ll MOD = 1000000007;
//const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'

//*
template <typename T1, typename T2>
class LazySegmentTree {
public:
  using F = function<T1(T1&, T1&)>; // query_func
  using G = function<T2(T2&, T2&)>; // update_func
  using H = function<T1(T1&, T2&, int, int)>; // lazy to node (node, lazy, left, right)
  int n;
  vector<T1> node;
  vector<T2> lazy;
  T1 e1;
  T2 e2;
  F query_func;
  G update_func;
  H eval_func;

  LazySegmentTree(vector<T1> a, F query_func, G update_func, H eval_func, T1 e1, T2 e2)
	:query_func(query_func), update_func(update_func), eval_func(eval_func), e1(e1), e2(e2)
  {
	int _n = a.size();
	n = 1; while (n < _n) n *= 2;
	node.resize(2 * n - 1, e1);
	lazy.resize(2 * n - 1, e2);
	for (int i = 0; i < _n; i++) node[i + n - 1] = a[i];
	for (int i = n - 2; i >= 0; i--) {
	  node[i] = query_func(node[i * 2 + 1], node[i * 2 + 2]);
	}
  }

  // km[hx]s
  inline void eval(int k, int l, int r) {
	if (lazy[k] != e2) { // Change
	  node[k] = eval_func(node[k], lazy[k], l, r);
	  if (r - l > 1) {
		lazy[2 * k + 1] = update_func(lazy[2*k + 1], lazy[k]);
		lazy[2 * k + 2] = update_func(lazy[2*k + 2], lazy[k]);
	  }
	  lazy[k] = e2; // Change
	}
  }

  // [a, b)x
  void update(int a, int b, T2 x, int k, int l, int r) {
	// k m[hx]s
	eval(k, l, r);
	if (b <= l || r <= a) return;
	if (a <= l && r <= b) {
	  lazy[k] = update_func(lazy[k], x);
	  eval(k, l, r);
	}
	else {
	  update(a, b, x, 2 * k + 1, l, (l + r) / 2);
	  update(a, b, x, 2 * k + 2, (l + r) / 2, r);
	  node[k] = query_func(node[2 * k + 1], node[2 * k + 2]);
	}
  }

  T1 query(int a, int b, int k, int l, int r) {
	eval(k, l, r);
	if (b <= l || r <= a) return e1;
	if (a <= l && r <= b) return node[k];
	T1 resl = query(a, b, 2 * k + 1, l, (l + r) / 2);
	T1 resr = query(a, b, 2 * k + 2, (l + r) / 2, r);
	return query_func(resl, resr);
  }
};

 ll f(ll a, ll b) {return max(a, b);}
 ll g(ll a, ll b) {return a + b;}
 ll h(ll a, ll b, int l, int r) {return a + b;}

signed main() {
	fio();
	int n, m, p;
	cin >> n >> m >> p;
	vector<pll> ac(n);
	rep (i, n) {
		cin >> ac[i].first >> ac[i].second;
	}
	sort(all(ac));
	vector<pll> bc(m);
	rep (i, m) {
		cin >> bc[i].first >> bc[i].second;
	}
	sort(all(bc));
 
	vector<pair<int, pii>> acz(p);
	rep (i, p) {
		cin >> acz[i].first >> acz[i].second.first >> acz[i].second.second;
	}
	sort(all(acz));
 
	vl ini(m);
	rep (i, m) {
		ini[i] = -bc[i].second;
	}
	//DEBUG_VEC(ini);
	LazySegmentTree<ll, ll> lst(ini, f, g, h, -INF, 0);
 
	int pi = 0;
 
	//DEBUG_VEC(ac);
	//DEBUG_VEC(bc);
	//DEBUG_VEC(acz);
 
	ll ma = -INF;
	rep (i, n) {
		int x = ac[i].first;
		while (pi < p and acz[pi].first < x) {
			//DEBUG(pi);
			int d = acz[pi].second.first;
			int z = acz[pi].second.second;
			auto itr = lower_bound(all(bc), pll(d + 1, -INF));
			int idx = itr - bc.begin();
			//DEBUG(idx);
			//DEBUG(z);
			lst.update(idx, m, z, 0, 0, lst.n);
			pi++;
		}

		chmax(ma, lst.query(0, lst.n, 0, 0, lst.n) - ac[i].second);
	}
	cout << ma << endl;
 
 
}

/*
struct dice {
  mt19937 mt;
  dice() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
  // [0, x)
  ll operator()(ll x) { return this->operator()(0, x); }
  // [x, y)
  ll operator()(ll x, ll y) {
	uniform_int_distribution<ll> dist(x, y - 1);
	return dist(mt);
  }
  vl operator()(int n, ll x, ll y) {
	vl res(n);
	for (int i = 0; i < n; i++) res[i] = this->operator()(x, y);
	return res;
  }
} rnd;

using ull = unsigned long long;
const ull MASK30 = (1UL << 30) - 1;
const ull MASK31 = (1UL << 31) - 1;
const ull M = (1UL << 61) - 1;
const ull B = rnd(2, M >> 1);
const ull POSITIVIZER = M * 3;;

class RollingHash {
public:
  
  vector<ull> hash;
  vector<ull> Bpower;

  RollingHash(string s) {
	int n = s.size();
	hash.resize(n + 1); Bpower.resize(n + 1);
	Bpower[0] = 1;
	
	for (int i = 0; i < n; i++) {
	  hash[i + 1] = _calc_mod(_mul(hash[i], B) + s[i]);
	  Bpower[i + 1] = _calc_mod(_mul(Bpower[i], B));
	}
  }

  //S[l, r)
  ull part(int l, int r) {
	return _calc_mod(hash[r] + POSITIVIZER - _mul(hash[l], Bpower[r - l]));
  }

  ull _mul(ull a, ull b) {
	ull au = a >> 31;
	ull ad = a & MASK31;
	ull bu = b >> 31;
	ull bd = b & MASK31;
	ull mid = ad * bu + au * bd;
	ull midu = mid >> 30;
	ull midd = mid & MASK30;
	return au * bu * 2 + midu + (midd << 31) + ad * bd;
  }

  ull _calc_mod(ull val) {
	val = (val & M) + (val >> 61);
	if (val > M) val -= M;
	return val;
  }
};

template <typename T>
class SegmentTree {
public:
  using F = function<T(T&, T&)>;
  int n;
  vector<T > dat;
  T e; // P
  F query_func;
  F update_func;
  
  SegmentTree(vector<T> a, F query_func, F update_func, T e) :n(a.size()), query_func(query_func), update_func(update_func), e(e) {
	dat.resize(4 * n);
	init(0, 0, n, a);
  }

  void init(int k, int l, int r, vector<T> &a) {
	if (r - l == 1) {
	  dat[k] = a[l];
	}
	else {
	  int lch = 2 * k + 1, rch = 2 * k + 2;
	  init(lch, l, (l + r) / 2, a);
	  init(rch, (l + r) / 2, r, a);
	  dat[k] = query_func(dat[lch], dat[rch]);
	}
  }

  //klaX
  void update(int k, T a, int v, int l, int r) {
	if (r - l == 1) {
	  dat[v] = update_func(dat[v], a);
	}
	else {
	  if (k < (l + r) / 2)
		update(k, a, 2 * v + 1, l, (l + r) / 2);
	  else {
		update(k, a, 2 * v + 2, (l + r) / 2, r);
	  }
	  dat[v] = query_func(dat[v * 2 + 1], dat[v * 2 + 2]);
	}
  }
	

  //[a,b)l
  //vZP
  //k_,l,r_[l,r)\
  //]AOquery(a,b,0,0,n)
  T query(int a, int b, int k, int l, int r) {
	if (r <= a || b <= l) {
	  return e;
	}
	if (a <= l && r <= b) {
	  return dat[k];
	}
	else {
	  T ul = query(a, b, k * 2 + 1, l, (l + r) / 2);
	  T ur = query(a, b, k * 2 + 2, (l + r) / 2, r);
	  return query_func(ul, ur);
	}
  }

  // ET
  int find(int a, int b, int k, int l, int r, int x) {
	// 
	if (dat[k] < x || r <= a || b <= l) return -1;
	if (l + 1 == r) {
	  // 
	  if (dat[k] >= x) return l;
	  else return -1;
	}
	int rv = find(a, b, 2 * k + 2, (l + r) / 2, r, x);
	if (rv != -1) return rv;
	return find(a, b, 2 * k + 1, l, (l + r) / 2, x);
  }
};

int f(int a, int b) {return max(a, b);}
int g(int a, int b) {return b;}

signed main() {
	fio();
	int n;
	cin >> n;
	string s;
	cin >> s;

	RollingHash rh(s);

	vi left(n, -1), right(n, -1);
	int start = -1;
	rep (i, n) {
		if (s[i] == '1') {
			if (start == -1) start = i;
			left[i] = start;
		}
		else {
			start = -1;
		}
	}

	start = -1;
	rrep (i, n) {
		if (s[i] == '1') {
			if (start == -1) start = i + 1;
			right[i] = start;
		}
		else {
			start = -1;
		}
	}

	vi a(n);
	vi b(n);
	rep (i, n) {
		if (i == 0 or s[i - 1] == '0') {
			if (s[i] == '1') {
				if ((right[i] - left[i]) % 2 == 1) {
					a[i] = 1;
				}
				b[i] = right[i] - left[i];
			}
		}
	}

	SegmentTree<int> seg(b, f, g, 0);

	vi sum(n + 1);
	rep (i, n) {
		sum[i + 1] = sum[i] + a[i];
	}

	vi sum2(n + 1);
	rep (i, n) sum2[i + 1] = sum2[i] + (s[i] - '0');



	// DEBUG_VEC(left);
	// DEBUG_VEC(right);
	// DEBUG_VEC(sum);
	// DEBUG_VEC(sum2);

	int q;
	cin >> q;
	while (q--) {
		int l1, l2, len;
		cin >> l1 >> l2 >> len;
		l1--; l2--;
		int r1 = l1 + len, r2 = l2 + len;
		if (sum2[r1] - sum2[l1] != sum2[r2] - sum2[l2]) {
			cout << "No" << endl;
			continue;
		}

		int l11 = l1, l22 = l2, r11 = r1, r22 = r2;

		bool flag = false;

		int t1 = 0, t2 = 0;
		if (s[l1] == '1') {
			int ri = right[l1];
			if ((ri - l1) % 2 == 1) t1++;
			l1 = ri;
		}
		if (s[r1 - 1] == '1') {
			int le = left[r1 - 1];
			if ((r1 - le) % 2 == 1) t1++;
			r1 = le;
		}
		if (l1 >= r1) {
			if ((r11 - l11) % 2 == 1) t1 = 1;
			else t1 = 0;
		}
		else {
			t1 += sum[r1] - sum[l1];
			if (l1 - l11 <= 1 and r11 - r1 <= 1) {
				int ma = seg.query(l1, r1, 0, 0, seg.n);
				if (ma <= 1) {
					auto h1 = rh.part(l11, r11);
					auto h2 = rh.part(l22, r22);
					if (h1 != h2) {
						cout << "No" << endl;
						continue;
					}
				}
			}
		}

		if (s[l2] == '1') {
			int ri = right[l2];
			if ((ri - l2) % 2 == 1) t2++;
			l2 = ri;
		}
		if (s[r2 - 1] == '1') {
			int le = left[r2 - 1];
			if ((r2 - le) % 2 == 1) t2++;
			r2= le;
		}
		if (l2 >= r2) {
			if ((r22 - l22) % 2 == 1) t2 = 1;
			else t2 = 0;
		}
		else {
			t2 += sum[r2] - sum[l2];
			if (l2 - l22 <= 1 and r22 - r2 <= 1) {
				int ma = seg.query(l2, r2, 0, 0, seg.n);
				if (ma <= 1) {
					auto h1 = rh.part(l11, r11);
					auto h2 = rh.part(l22, r22);
					if (h1 != h2) {
						cout << "No" << endl;
						continue;
					}
				}
			}
		}

		if (t1 == t2) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
}
//*/