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
const ll INF = 2e18;
const ll MOD = 1000000007;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);




int main() {
	int n, k;
	cin >> n >> k;
	vl _c(k*n);
	vi c_num(100010), p_num(100010);
	rep(i, k*n) {
		cin >> _c[i];
		_c[i]--;
		c_num[_c[i]]++;
	}
	vl f(n);
	rep(i, n) {
		cin >> f[i];
		f[i]--;
		p_num[f[i]]++;
	}
	vl h(k + 1);
	rep1(i, k) {
		cin >> h[i];
	}
    vll dp(n + 1, vl(n*k + 1, -INF));
    dp[0][0] = 0;
    rep(i, n) {
      rep(j, n*k + 1) {
        rep(l, k + 1) {
          if (j + l > n*k) {
            break;
          }
          chmax(dp[i + 1][j + l], dp[i][j] + h[l]);
        }
      }
    }
    

	int nokori = 0;
	ll ans = 0;
	rep(i,100000) {
		ll c = c_num[i], p = p_num[i];
		if (c == 0) {
			continue;
		}
		if (c >= p * k) {
			ans += h[k] * p;
			nokori += c - p * k;
			continue;
		}
		ans += dp[p][c];
	}
	cout << ans << endl;
}