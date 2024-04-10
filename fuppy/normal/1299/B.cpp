#include <bits/stdc++.h>
 
//#include <unistd.h>
//#include <iostream>
 
using namespace std;
 
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl;
#define DEBUG_MAT(v) cerr<<#v<<endl;for(int i=0;i<v.size();i++){for(int j=0;j<v[i].size();j++) {cerr<<v[i][j]<<" ";}cerr<<endl;}
typedef long long ll;
#define int ll
 
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


#define ci complex<ll>
//x,y\[g
bool cmp_x(const ci p, const ci q) {
	if (p.real() != q.real()) return p.real() < q.real();
	return p.imag() < q.imag();
}

//uxNga,bO
ll det(ci a, ci b) {
	return a.real()*b.imag() - b.real()*a.imag();
}

//uxNga,b
ll dot(ci a, ci b) {
	return a.real()*b.real() + a.imag()*b.imag();
}

//ps: SW, n: WBW
vector<ci> convex_hull(vector<ci> ps, int n) {
	sort(ps.begin(), ps.end(), cmp_x);
	int k = 0; //_
	vector<ci> qs(n * 2); //\z
	for (int i = 0; i < n; i++) {
		while (k > 1 && det(qs[k - 1] - qs[k - 2], ps[i] - qs[k - 1]) <= 0) k--;
		qs[k++] = ps[i];
	}
	for (int i = n - 2, t = k; i >= 0; i--) {
		while (k > t && det(qs[k - 1] - qs[k - 2], ps[i] - qs[k - 1]) <= 0) k--;
		qs[k++] = ps[i];
	}
	qs.resize(k - 1);
	return qs;
}


signed main() {
  fio();
  int n;
  cin >> n;
  vector<ci> xy(n);
  rep (i, n) {
    ll x, y;
    cin >> x >> y;
    xy[i] = ci(x, y);
  }

  vector<ci> xy2 = convex_hull(xy, n);
  if (xy2.size() < xy.size()) {
	  cout << "No" << endl;
	  return 0;
  }
  if (n % 2 == 1) {
	  cout << "No" << endl;
	  return 0;
  }

  rep (i, n / 2) {
	  ci p1 = xy[i + 1] - xy[i];
	  ci p2 = xy[(i + n / 2 + 1) % n] - xy[(i + n / 2) % n];
	  if (p1 != -p2) {
		  cout << "No" << endl;
		  return 0;
	  }
  }
  cout << "Yes" << endl;
  
}