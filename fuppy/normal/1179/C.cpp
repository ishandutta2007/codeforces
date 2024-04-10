#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl
#define DEBUG_MAT(v) cerr<<#v<<endl;for(int i=0;i<v.size();i++){for(int j=0;j<v[i].size();j++) {cerr<<v[i][j]<<" ";}cerr<<endl;}


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
const ll MOD = 1000000007;
//const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { -1,0, 1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
// #define mp make_pair
//#define endl '\n'

const int N = 1000000;

class LazySegmentTree {
public:
	int n;
  vl node, lazy;
	bool ismax; //truefalse

	LazySegmentTree(vl a, bool _ismax) {
		ismax = _ismax;
		int _n = a.size();
		n = 1; while (n < _n) n *= 2;
		node.resize(2 * n - 1);
        fill(all(node), INF * (1 - (int)ismax * 2));
		lazy.resize(2 * n - 1, 0);
		for (int i = 0; i < _n; i++) node[i + n - 1] = a[i];
		for (int i = n - 2; i >= 0; i--) {
			if (ismax) node[i] = max(node[i * 2 + 1], node[i * 2 + 2]);
			else node[i] = min(node[i * 2 + 1], node[i * 2 + 2]);
		}
	}

	// k
	inline void eval(int k, int l, int r) {
      if (lazy[k] != 0) {
        node[k] += lazy[k];
        if (r - l > 1) {
          lazy[2 * k + 1] += lazy[k]; /////
          lazy[2 * k + 2] += lazy[k]; /////
        }
        lazy[k] = 0;
      }
	}

	void add(int a, int b, ll x, int k, int l, int r) {
		// k 
		eval(k, l, r);
		if (b <= l || r <= a) return;
		if (a <= l && r <= b) {
			lazy[k] += x; //////
			eval(k, l, r);
		}
		else {
			add(a, b, x, 2 * k + 1, l, (l + r) / 2);
			add(a, b, x, 2 * k + 2, (l + r) / 2, r);
			if (ismax) node[k] = max(node[2 * k + 1], node[2 * k + 2]);
			else node[k] = min(node[2 * k + 1], node[2 * k + 2]);
		}
	}

	ll getmax(int a, int b, int k, int l, int r) {
		eval(k, l, r);
		if (b <= l || r <= a) return (ismax ? -INF : INF);
		if (a <= l && r <= b) return node[k];
		ll resl = getmax(a, b, 2 * k + 1, l, (l + r) / 2);
		ll resr = getmax(a, b, 2 * k + 2, (l + r) / 2, r);
		if (ismax) return max(resl, resr);
		else return min(resl, resr);
	}

};


int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vi a(n), b(m);
  rep (i, n) {
    scanf("%d", &a[i]);
    a[i] = N - a[i];
  }
  rep (i, m) {
    scanf("%d", &b[i]);
    b[i] = N - b[i];
  }

  vl s(N);
  rep (i, n) {
    s[a[i]]++;
  }
  rep (i, m) {
    s[b[i]]--;
  }
  for (int i = 1; i < N; i++) {
    s[i] += s[i - 1];
  }
  LazySegmentTree lst(s, true);

  int q;
  scanf("%d", &q);
  rep (aaa, q) {
    int t, idx, x;
    scanf("%d %d %d", &t, &idx, &x);
    x = N - x;
    idx--;
    if (t == 1) {
      lst.add(a[idx], lst.n, -1, 0, 0, lst.n);
      a[idx] = x;
      lst.add(a[idx], lst.n, 1, 0, 0, lst.n);
    }
    else {
      lst.add(b[idx], lst.n, 1, 0, 0, lst.n);
      b[idx] = x;
      lst.add(b[idx], lst.n, -1, 0, 0, lst.n);
    }
    if (lst.getmax(0, lst.n, 0, 0, lst.n) <= 0) {
      printf("-1\n");
      continue;
    }
    int ng = -1, ok = lst.n;
    while (ng + 1 < ok) {
      int mid = (ng + ok) / 2;
      if (lst.getmax(0, mid, 0, 0, lst.n) > 0) {
        ok = mid;
      }
      else {
        ng = mid;
      }
    }
    printf("%d\n", N - ok + 1);
  }
}