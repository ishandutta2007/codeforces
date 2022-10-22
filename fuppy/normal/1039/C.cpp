#include "bits/stdc++.h"

using namespace std;

#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl

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
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define rep1(i,n) for(ll i=1;i<=(ll)(n);i++)
#define rrep(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define rrep1(i,n) for(ll i=(ll)(n);i>0;i--)
#define REP(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(),c.end()
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = 1e18;
const ll MOD = 1000000007;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
#define mp make_pair


class UnionFind {
public:
	int n;
	vi par; //
	vi ran; //
	vi num; //

  UnionFind(int _n) {
    n = _n;
    par.resize(n); ran.resize(n); num.resize(n);
    for (int i = 0; i < n; i++) {
      par[i] = i; ran[i] = 0; num[i] = 1;
    }
  }

  //
  int find(int x) {
    if (par[x] == x) {
      return x;
    }
    else {
      return par[x] = find(par[x]);
    }
  }

  //xy
  void unite(int x, int y) {
    x = find(x); y = find(y);
    int numsum = num[x] + num[y];
    if (x == y) {
      return;
    }
    if (ran[x]<ran[y]) {
      par[x] = y;
    }
    else {
      par[y] = x;
      if (ran[x] == ran[y]) {
        ran[x]++;
      }
    }
    num[x] = num[y] = numsum;
  }

  //xy
  bool same(int x, int y) {
    return find(x) == find(y);
  }

};


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


int main() {
  fio();
  ll n, m, k;
  cin >> n >> m >> k;
  vl c(n);
  rep (i, n) {
    cin >> c[i];
  }
  if (m == 0) {
    cout << (1LL << k) % MOD * mod_pow(2, n) % MOD << endl;
    return 0;
  }
  
  vector<pair<ll, pll> > p(m);
  set<ll> st;
  rep (i, m) {
    ll u, v;
    cin >> u >> v;
    u--; v--;
    p[i].second.first = u;
    p[i].second.second = v;
    p[i].first = c[u] ^ c[v];
    st.insert(p[i].first);
  }
  sort(all(p));
  ll ans = 0;
  ll temp = ((1LL << k) - (ll)st.size()) % MOD;
  ans = temp * mod_pow(2, n) % MOD;
  //DEBUG(ans);
  ll pre = p[0].first;
  ll nokori = n;
  unordered_set<ll> ust;
  UnionFind uf(n);
  //DEBUG_VEC(p);
  rep (i, m) {
    if (p[i].first != pre) {
      ans = (ans + mod_pow(2, nokori) % MOD) % MOD;
      //DEBUG(ans);
      pre = p[i].first;
      nokori = n;
      for (auto itr = ust.begin(); itr != ust.end(); itr++) {
        ll u = *itr;
        uf.par[u] = u;
        uf.ran[u] = 0;
        uf.num[u] = 1;
      }
      ust.clear();
    }
    ll u = p[i].second.first, v = p[i].second.second;
    if (!uf.same(u, v)) {
      nokori--;
      uf.unite(u, v);
      ust.insert(u); ust.insert(v);
    }
  }
  ans = (ans + mod_pow(2, nokori) % MOD) % MOD;
  while (ans < 0) {
    ans = (ans + MOD) % MOD;
  }
  cout << ans << endl;
}