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

int ask(int i1, int j1, int i2, int j2) {
  cout << "? " << i1 + 1 << " " << j1 + 1 << " " << i2 + 1 << " " << j2 + 1 << endl << flush;
  int res;
  cin >> res;
  return res;
}

int main() {
  int n;
  cin >> n;
  vii a(n, vi(n, -1));
  a[0][0] = 1;
  a[n - 1][n - 1] = 0;
  rep (i, n) {
    rep (j, n) {
      if (a[i][j] == -1) continue;
      if (i >= 2 and a[i - 2][j] == -1) {
        int res = ask(i - 2, j, i, j);
        if (res) a[i - 2][j] = a[i][j];
        else a[i - 2][j] = 1 - a[i][j];
      }
      if (i + 2 < n and a[i + 2][j] == -1) {
        int res = ask(i, j, i + 2, j);
        if (res) a[i + 2][j] = a[i][j];
        else a[i + 2][j] = 1 - a[i][j];
      }
      if (j >= 2 and a[i][j - 2] == -1) {
        int res = ask(i, j - 2, i, j);
        if (res) a[i][j - 2] = a[i][j];
        else a[i][j - 2] = 1 - a[i][j];
      }
      if (j + 2 < n and a[i][j + 2] == -1) {
        int res = ask(i, j, i, j + 2);
        if (res) a[i][j + 2] = a[i][j];
        else a[i][j + 2] = 1 - a[i][j];
      }
      if (i + 1 < n and j + 1 < n and a[i + 1][j + 1] == -1) {
        int res = ask(i, j, i + 1, j + 1);
        if (res) a[i + 1][j + 1] = a[i][j];
        else a[i + 1][j + 1] = 1 - a[i][j];
      }
    }
  }
  //DEBUG_MAT(a);

  vii b(n, vi(n, -1));
  b[0][1] = 1;
  rep (i, n) {
    rep (j, n) {
      if (b[i][j] == -1) continue;
      if (i >= 2 and b[i - 2][j] == -1) {
        int res = ask(i - 2, j, i, j);
        if (res) b[i - 2][j] = b[i][j];
        else b[i - 2][j] = 1 - b[i][j];
      }
      if (i + 2 < n and b[i + 2][j] == -1) {
        int res = ask(i, j, i + 2, j);
        if (res) b[i + 2][j] = b[i][j];
        else b[i + 2][j] = 1 - b[i][j];
      }
      if (j >= 2 and b[i][j - 2] == -1) {
        int res = ask(i, j - 2, i, j);
        if (res) b[i][j - 2] = b[i][j];
        else b[i][j - 2] = 1 - b[i][j];
      }
      if (j + 2 < n and b[i][j + 2] == -1) {
        int res = ask(i, j, i, j + 2);
        if (res) b[i][j + 2] = b[i][j];
        else b[i][j + 2] = 1 - b[i][j];
      }
      if (i + 1 < n and j + 1 < n and b[i + 1][j + 1] == -1) {
        int res = ask(i, j, i + 1, j + 1);
        if (res) b[i + 1][j + 1] = b[i][j];
        else b[i + 1][j + 1] = 1 - b[i][j];
      }
    }
  }
  //DEBUG_MAT(b);

  pii p1(-1, -1), p2(-1, -1);
  for (int i = 0; i < n - 2; i++) {
    if (p1.first != -1) break;
    for (int j = 0; j < n - 1; j++) {
      vii root(3);
      if (a[i][j] == -1) {
        root[0] = {b[i][j], a[i][j + 1], b[i + 1][j + 1], a[i + 2][j + 1]};
        root[1] = {b[i][j], a[i + 1][j], b[i + 1][j + 1], a[i + 2][j + 1]};
        root[2] = {b[i][j], a[i + 1][j], b[i + 2][j], a[i + 2][j + 1]};
        if (b[i][j] != a[i + 2][j + 1]) {
          rep (k, 3) {
            root[k][0] = 1 - root[k][0];
            root[k][2] = 1 - root[k][2];
          }
        }
      }
      else {
        root[0] = {a[i][j], b[i][j + 1], a[i + 1][j + 1], b[i + 2][j + 1]};
        root[1] = {a[i][j], b[i + 1][j], a[i + 1][j + 1], b[i + 2][j + 1]};
        root[2] = {a[i][j], b[i + 1][j], a[i + 2][j], b[i + 2][j + 1]};
        if (a[i][j] != b[i + 2][j + 1]) {
          rep (k, 3) {
            root[k][1] = 1 - root[k][1];
            root[k][3] = 1 - root[k][3];
          }
        }
      }

      rep (k, 3) {
        vi cop = root[k];
        reverse(all(cop));
        if (cop == root[k]) {
          p1 = pii(i, j);
          p2 = pii(i + 2, j + 1);
          break;
        }
      }
      if (p1.first != -1) break;
    }
  }

  for (int i = 0; i < n - 1; i++) {
    if (p1.first != -1) break;
    for (int j = 0; j < n - 2; j++) {
      vii root(3);
      if (a[i][j] == -1) {
        root[0] = {b[i][j], a[i + 1][j], b[i + 1][j + 1], a[i + 1][j + 2]};
        root[1] = {b[i][j], a[i][j + 1], b[i + 1][j + 1], a[i + 1][j + 2]};
        root[2] = {b[i][j], a[i][j + 1], b[i][j + 2], a[i + 1][j + 2]};
        if (b[i][j] != a[i + 1][j + 2]) {
          rep (k, 3) {
            root[k][0] = 1 - root[k][0];
            root[k][2] = 1 - root[k][2];
          }
        }
      }
      else {
        root[0] = {a[i][j], b[i + 1][j], a[i + 1][j + 1], b[i + 1][j + 2]};
        root[1] = {a[i][j], b[i][j + 1], a[i + 1][j + 1], b[i + 1][j + 2]};
        root[2] = {a[i][j], b[i][j + 1], a[i][j + 2], b[i + 1][j + 2]};
        if (a[i][j] != b[i + 1][j + 2]) {
          rep (k, 3) {
            root[k][1] = 1 - root[k][1];
            root[k][3] = 1 - root[k][3];
          }
        }
      }

      rep (k, 3) {
        vi cop = root[k];
        reverse(all(cop));
        if (cop == root[k]) {
          p1 = pii(i, j);
          p2 = pii(i + 1, j + 2);
          break;
        }
      }
      if (p1.first != -1) break;
    }
  }

  int res = ask(p1.first, p1.second, p2.first, p2.second);
  int a1, a2;
  if (a[p1.first][p1.second] == -1) {
    a1 = b[p1.first][p1.second];
    a2 = a[p2.first][p2.second];
  }
  else {
    a1 = a[p1.first][p1.second];
    a2 = b[p2.first][p2.second];
  }

  bool swap;
  if (res == 1) {
    if (a1 == a2) {
      swap = false;
    }
    else {
      swap = true;
    }
  }
  else {
    if (a1 == a2) swap = true;
    else swap = false;
  }

  rep (i, n) rep (j, n) {
    if (b[i][j] == -1) continue;
    if (swap) b[i][j] = 1 - b[i][j];
  }

  cout << "!" << endl << flush;
  rep (i, n) {
    rep (j, n) {
      if (a[i][j] == -1) cout << b[i][j];
      else cout << a[i][j];
    }
    cout << endl;
  }
  cout << flush;
}