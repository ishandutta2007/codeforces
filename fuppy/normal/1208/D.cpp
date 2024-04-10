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

ll f1(ll a, ll b) {return a + b;}
ll f2(ll a, ll b) {return b;}

class Bit {
public:
	int n;
	vl bit; // 0-index

	Bit(int _n) { n = _n; bit.resize(n); }

	// [0, i)
	ll sum(int i) {
		ll s = 0;
		while (i > 0) {
			s += bit[i - 1];
			i -= i & -i;
		}
		return s;
	}

  ll sum(int l, int r) {
    return sum(r) - sum(l);
  }

	//i0-index
	void add(int i, ll x) {
		i++;
		while (i <= n) {
			bit[i - 1] += x;
			i += i & -i;
		}
	}
};



int main() {
  int n;
  cin >> n;
  vl a(n);
  rep (i, n) cin >> a[i];

  Bit bit(n);
  vl b(n);
  rep (i, n) {
    bit.add(i, i + 1);
    b[i] = i + 1;
  }

  vl ans(n);
  rrep (i, n) {
    ll x = a[i];
    int ok = n, ng = -1;
    while (ng + 1 < ok) {
      int mid = (ng + ok) / 2;
      //DEBUG(pii(ng, ok));
      //DEBUG(mid);
      ll s = bit.sum(mid);
      //DEBUG(s);
      if (s < x) {
        ng = mid;
      }
      else if (s > x) {
        ok = mid;
      }
      else {
        if (b[mid] != 0) {
          ok = mid;
        }
        else {
          ng = mid;
        }
      }
    }
    ans[i] = ok + 1;
    bit.add(ok, -(ok + 1));
    b[ok] = 0;
  }
  
  rep (i, n) {
    cout << ans[i] << " ";
  }
  cout << endl;
}