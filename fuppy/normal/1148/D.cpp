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
//const ll MOD = 1000000007;
const ll MOD = 1000003;
//const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { -1,0, 1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
//#define mp make_pair

bool cmp(pii a, pii b) {
  return a.second > b.second;
}

vector<pii> solve(vector<pii> a) {
  int n = a.size();
  sort(all(a), cmp);
  int pre = inf;
  vector<pii> res;
  rep (i, n) {
    if (a[i].first < pre) {
      res.push_back(a[i]);
      pre = a[i].second;
    }
  }
  return res;
}


int main() {
  fio();
  int n;
  cin >> n;
  vector<pii> a, b;
  map<pii, int> mp;
  rep (i, n) {
    int x, y;
    cin >> x >> y;
    mp[pii(x, y)] = i;
    if (x < y) {
      a.push_back(pii(x, y));
    }
    else {
      b.push_back(pii(-x, -y));
    }
  }
  vector<pii> p1 = solve(a), p2 = solve(b);
  if (p1.size() >= p2.size()) {
    cout << p1.size() << endl;
    rep (i, p1.size()) {
      int j = mp[p1[i]];
      cout << j + 1 << " ";
    }
    cout << endl;
  }
  else {
    cout << p2.size() << endl;
    rep (i, p2.size()) {
      p2[i].first *= -1; p2[i].second *= -1;
      int j = mp[p2[i]];
      cout << j + 1 << " ";
    }
    cout << endl;
  }
}