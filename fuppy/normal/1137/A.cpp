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
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
//#define mp make_pair


int main() {
  fio();
  int h, w;
  cin >> h >> w;
  vll a(h, vl(w));
  rep (i, h) {
    rep (j, w) {
      cin >> a[i][j];
    }
  }

  vll tate(h, vl(w)), yoko(h, vl(w));
  rep (j, w) {
    vl temp(h);
    rep (i, h) {
      temp[i] = a[i][j];
    }
    sort(all(temp));
    int cnt = 0;
    map<ll, int> mp;
    rep (i, h) {
      if (mp[temp[i]] == 0) mp[temp[i]] = ++cnt;
    }
    rep (i, h) {
      tate[i][j] = mp[a[i][j]];
    }
  }
  rep (i, h) {
    vl temp = a[i];
    sort(all(temp));
    int cnt = 0;
    map<ll, int> mp;
    rep (j, w) {
      if (mp[temp[j]] == 0) mp[temp[j]] = ++cnt;
    }
    rep (j, w) {
      yoko[i][j] = mp[a[i][j]];
    }
  }
  //DEBUG_MAT(tate);
  //DEBUG_MAT(yoko);

  vl tatema(w, -1), yokoma(h, -1);
  rep (i, h) {
    rep (j, w) {
      chmax(yokoma[i], yoko[i][j]);
    }
  }
  rep (j, w) {
    rep (i, h) {
      chmax(tatema[j], tate[i][j]);
    }
  }
  rep (i, h) {
    rep (j, w) {
      if (tate[i][j] >= yoko[i][j]) {
        cout << max(tatema[j], yokoma[i] + (tate[i][j] - yoko[i][j])) << " ";
      }
      else {
        cout << max(yokoma[i], tatema[j] + (yoko[i][j] - tate[i][j])) << " ";
      }
    }
    cout << endl;
  }
}