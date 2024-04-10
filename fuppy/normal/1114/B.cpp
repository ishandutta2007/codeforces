#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl
#define DEBUG_MAT(v) cerr<<#v<<endl;for(int i=0;i<v.size();i++){for(int j=0;j<v[i].size();j++) {cout<<v[i][j]<<" ";}cout<<endl;}


typedef long long ll;
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
//const ll MOD = 1000000007;
const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
//#define mp make_pair

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

  // k
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
    // k 
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

#define arr array<ll, 62>
vi primes;
int m;

arr f1(arr a, arr b) {
  arr res;
  rep (i, m) {
    res[i] = a[i] + b[i];
  }
  return res;
}

arr f3(arr a, arr b, int l, int r) {
  arr res = a;
  rep (i, m) {
    res[i] += b[i] * (r - l);
  }
  return res;
}

ll mod_pow(ll x, ll p, ll M = MOD) {
	ll a = 1;
	while (p) {
		if (p % 2)
			a = a*x%M;
		x = x*x%M;
		p /= 2;
	}
	return a;
}

ll mod_inverse(ll a, ll M = MOD) {
	return mod_pow(a, M - 2, M);
}

//nn
//O(sqrt(n))
vi eulers;
int eulerSingle(int n) {
  int res = n;
  for (int i = 2; i*i <= n; i++) {
    if (n%i == 0) {
      res = res / i * (i - 1);
      for (; n%i == 0; n /= i);
    }
  }
  if (n != 1) res = res / n * (n - 1);
  return res;
}



arr get_array(ll x) {
  arr res;
  for (int j = 0; j < primes.size(); j++) {
    int p = primes[j];
    res[j] = 0;
    while (x % p == 0) {
      res[j]++;
      x /= p;
    }
  }
  return res;
}


/*
int main() {
  fio();
  for (int i = 2; i <= 300; i++) {
    bool flag = true;
    for (int j = 2; j < i; j++) {
      if (i % j == 0) flag = false;
    }
    if (flag) primes.push_back(i);
  }
  m = primes.size();
  rep (i, m) {
    eulers.push_back(eulerSingle(primes[i]));
  }
  int n, q;
  cin >> n >> q;
  vi a(n);
  rep (i, n) {
    cin >> a[i];
  }
  vector<arr> v(n);
  rep (i, n) {
    v[i] = get_array(a[i]);
  }
  arr e;
  rep (i, m) e[i] = 0;

  vector<arr> add;
  vector<pii> lr;
  int haba = sqrt(n);
  int i = 0;
  while (i < n) {
    lr.push_back(pii(i, min(n, i + haba)));
    add.push_back(e);
    i += haba;
  }

  while (q--) {
    string s;
    cin >> s;
    if (s == "MULTIPLY") {
      int l, r, x;
      cin >> l >> r >> x;
      l--;
      arr mul = get_array(x);
      rep (i, lr.size()) {
        int l2 = lr[i].first, r2 = lr[i].second;
        if (r <= l2) continue;
        if (r2 <= l) continue;
        if (l <= l2 && r2 <= r) {
          rep (j, m) {
            add[i][j] += mul[j];
          }
        }
        else {
          int l3, r3;
          if (l <= l2) l3 = l2;
          else l3 = l;
          if (r <= r2) r3 = r;
          else r3 = r2;
          for (int j = l3; j < r3; j++) {
            rep (k, m) {
              v[j][k] += mul[k];
            }
          }
        }
      }
    }
    else {
      int l, r;
      cin >> l >> r;
      l--;
      ll res = 1;
      arr num;
      rep (j, m) num[j] = 0;
      rep (i, lr.size()) {
        int l2 = lr[i].first, r2 = lr[i].second;
        if (r <= l2) continue;
        if (r2 <= l) continue;
        if (l <= l2 && r2 <= r) {
          rep (j, m) {
            num[j] += add[i][j] * haba;
          }
        }
        else {
          int l3, r3;
          if (l <= l2) l3 = l2;
          else l3 = l;
          if (r <= r2) r3 = r;
          else r3 = r2;
          for (int j = l3; j < r3; j++) {
            rep (k, m) {
              num[k] += v[j][k];
            }
          }
        }
      }
      rep (i, m) {
        int p = primes[i];
        int k = num[i];
        if (k == 0) continue;
        res = res * (mod_pow(p, k) - mod_pow(p, k - 1)) % MOD;
      }
      res = (res + MOD) % MOD;
      cout << res << endl;
    }
  }
  
}
//*/

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vi a(n);
  rep (i, n) {
    cin >> a[i];
  }
  vi b = a;
  sort(all(b));
  reverse(all(b));
  multiset<ll> st;
  ll ans = 0;
  rep (i, m * k) {
    st.insert(b[i]);
    ans += b[i];
  }
  int cnt = 0;
  vi p;
  rep (i, n) {
    auto itr = st.lower_bound(a[i]);
    int temp = *itr;
    if (*itr == a[i]) {
      cnt++;
      st.erase(itr);
      if (cnt == m) {
        p.push_back(i + 1);
        cnt = 0;
      }
    }
  }
  cout << ans << endl;
  p.pop_back();
  rep (i, p.size()) {
    cout << p[i] << " ";
  }
  cout << endl;
  
}