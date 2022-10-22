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
 
 
 
class Bit {
public:
	int n;
	vl bit; // 0-index
 
	Bit(int _n) { n = _n; bit.resize(n); }
 
	// [0, i)a
	ll sum(int i) {
		ll s = 0;
		while (i > 0) {
			s += bit[i - 1];
			i -= i & -i;
		}
		return s;
	}
 
	//i0-index
	void add(int i, ll x) {
		i++;
		while (i <= n) {
			bit[i - 1] += x;
			i += i & -i;
		}
	}
 
	// bitx
	// 1x = 1;
	// bit3add(3, 1), 3oadd(3, -1)
	// return == nx
	ll min_xth(int x) {
		int left = -1, right = n;
		while (left + 1 < right) {
			int mid = (left + right) / 2;
			int temp = sum(mid + 1);
			if (temp < x) {
				left = mid;
			}
			else {
				right = mid;
			}
		}
		return right;
	}
 
 
	// p
	ll bubble(vi p) {
		int n = p.size();
		ll ans = 0;
		for (int j = 0; j < n; j++) {
			ans += (j - sum(p[j] + 1));
			add(p[j], 1);
		}
		return ans;
	}
};
 
 
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
 
int f(int a, int b) {
	return a + b;	
}
int g(int a, int b) {
	return a + b;
}
int h(int a, int b, int l, int r) {
	return a + b * (r - l);
}
 
 
int w;
 
bool cmp(pii a, pii b) {
  if (a.first != b.first) {
    return a.first < b.first;
  }
  else return a.second < b.second;
}

const long double EPS = 1e-8;
 
ll solve1(vector<pii> xv) {
  int n = xv.size();
 
  using P = pair<long double, long double>;
  vector<P> io(n);
  vector<long double> temp;
  rep (i, n) {
	io[i].first = (xv[i].first) / (long double)(-xv[i].second + w + EPS);
	io[i].second = (xv[i].first) / (long double)(-xv[i].second - w - EPS);
    temp.push_back(io[i].first);
    temp.push_back(io[i].second);
  }
  sort(all(temp));
  UNIQUE(temp);
  //DEBUG_VEC(temp);
  map<long double, int> mp;
  rep (i, temp.size()) mp[temp[i]] = i;

  //sort(all(io));
  //DEBUG_VEC(io);
  vector<pii> io2(n);
  rep (i, n) {
    io2[i].first = mp[io[i].first];
    io2[i].second = mp[io[i].second];
  }
  sort(all(io2), cmp);
  //DEBUG_VEC(io2);
 
  Bit bit(2 * n);
  ll ans = 0;
  int i = 0;
  int nex = io2[0].first;
  while (i < n) {
	vector<pii> nx;
	while (i < n and io2[i].first == nex) {
		nx.push_back(io2[i]);
		i++;
	}
	ans += nx.size() * ((int)nx.size() - 1) / 2;
	rep (j, nx.size()) {
		ans += bit.sum(2 * n) - bit.sum(nx[j].second);
	}
	rep (j, nx.size()) {
		bit.add(nx[j].second, 1);
	}
	if (i < n) nex = io2[i].first;
  }
  return ans;
}
 
void solve2(vector<pii> fu, vector<pii> sei) {
	using P = pair<long double, long double>;
	vector<P> fuio(fu.size()), seio(sei.size());
	vector<long double> temp;
	rep (i, fuio.size()) {
		fuio[i].first = (fu[i].first - w) / (long double)(-fu[i].second);
		fuio[i].second = (fu[i].first + w) / (long double)(-fu[i].second);
		temp.push_back(fuio[i].first);
		temp.push_back(fuio[i].second);
	}
	rep (i, seio.size()) {
		seio[i].first = (sei[i].first - w) / (long double)(-sei[i].second);
		seio[i].second = (sei[i].first + w) / (long double)(-sei[i].second);
		temp.push_back(seio[i].first);
		temp.push_back(seio[i].second);
	}
	sort(all(temp));
	map<long double, int> mp;
	rep (i, temp.size()) mp[temp[i]] = i;
 
	vector<pii> io1(fu.size()), io2(sei.size());
	rep (i, fu.size()) {
		io1[i].first = mp[fuio[i].first];
		io1[i].second = mp[fuio[i].second];
	}
	rep (i, sei.size()) {
		io2[i].first = mp[seio[i].first];
		io2[i].second = mp[seio[i].second];
	}
 
	vector<pii> ii(fu.size()), oo(fu.size());
	rep (i, fu.size()) {
		ii[i].first = io1[i].first;
		ii[i].second = i;
		oo[i].first = io1[i].second;
		oo[i].second = i;
	}
	sort(all(ii));
	sort(all(oo));
 
	int n = ii.size();
	LazySegmentTree<int, int> segi(vi(n), f, g, h, 0, 0);
	LazySegmentTree<int, int> sego(vi(n), f, g, h, 0, 0);
 
	int oj = 0, ij = n - 1;
	rep (i, io2.size()) {
		int in_time = io2[i].first;
		while (oj < n) {
			if (oo[oj].first < in_time) oj++;
			else break;
		}
		sego.update(0, oj, -1, 0, 0, sego.n);
		int out_time = io2[i].second;
	}
}
 
signed main() {
  fio();
  int n;
  cin >> n >> w;
 
  vector<pii> fu, sei;
  rep (i, n) {
    int x, v;
    cin >> x >> v;
    if (x > 0) {
      sei.push_back(pii(x, v));
    }
    else {
      sei.push_back(pii(x, v));
    }
  }
 
  ll ans = solve1(sei);
  //ans += solve1(fu);
 
  //solve2(fu, sei);
  cout << ans << endl;
}