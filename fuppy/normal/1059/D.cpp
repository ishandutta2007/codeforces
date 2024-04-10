#include <bits/stdc++.h>

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
const ll INF = 1e18;
const ll MOD = 1000000007;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
//#define mp make_pair


#define pdd pair<double, double>
#define ci complex<ll>
//x,y
bool cmp_x(const ci p, const ci q) {
	if (p.real() != q.real()) return p.real() < q.real();
	return p.imag() < q.imag();
}

//a,b
ll det(ci a, ci b) {
	return a.real()*b.imag() - b.real()*a.imag();
}

//a,b
ll dot(ci a, ci b) {
	return a.real()*b.real() + a.imag()*b.imag();
}

double dist(pdd a, pdd b) {
  pdd diff = a - b;
  return sqrt(diff.first * diff.first + diff.second * diff.second);
}
  

//ps: , n: 
vector<ci> convex_hull(vector<ci> ps, int n) {
	sort(ps.begin(), ps.end(), cmp_x);
	int k = 0; //
	vector<ci> qs(n * 2); //
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

vector<pdd> p;

double f(double x) {
  double mi = 0;
  rep (i, p.size()) {
    mi = max(mi, ((x - p[i].first) * (x - p[i].first) + p[i].second * p[i].second) / (2 * p[i].second));
  }
  return mi;
}


int main() {
  int n;
  scanf(" %d", &n);
  vector<ci> ps(n);
  bool up = false, down = false;
  rep (i, n) {
    int x, y;
    scanf(" %d %d", &x, &y);
    if (y > 0) {
      up = true;
    }
    else {
      down = true;
      y = -y;
    }
    ps[i].real(x);
    ps[i].imag(y);
  }
  if (up && down) {
    cout << -1 << endl;
    return 0;
  }
  if (n == 1) {
    cout << (double)ps[0].imag() / 2 << endl;
    return 0;
  }
  auto p2 = convex_hull(ps, n);
  rep (i, p2.size()) {
    p.push_back(pdd(p2[i].real(), p2[i].imag()));
  }

  //DEBUG_VEC(p);
  double phi = (1 + sqrt(5)) / 2.0;
  double left = -10000001, right = 10000001;
  bool pre_l = false, pre_r = false;
  double pre_f1 = -1, pre_f2 = -1;
  double pre_x1 = -1, pre_x2 = -1;
  rep (aaa, 100) {
    double x1 = (phi * left + right) / (1 + phi), x2 = (left + phi * right) / (1 + phi);
    double f1, f2;
    if (!pre_r && !pre_l) {
      f1 = f(x1);
      f2 = f(x2);
    }
    if (pre_r) {
      f2 = pre_f1;
      f1= f(x1);
      
    }
    if (pre_l) {
      f1 = pre_f2;
      f2 = f(x2);
    }
    
    if (f1 < f2) {
      right = x2;
      pre_r = true;
      pre_l = false;
    }
    else {
      left = x1;
      pre_l = true;
      pre_r = false;
    }
    pre_f1 = f1;
    pre_f2 = f2;
    pre_x1 = x1;
    pre_x2 = x2;
  }
  Sp(f(left));
}