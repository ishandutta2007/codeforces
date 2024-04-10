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
//const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
//#define mp make_pair

int main() {
  int n;
  cin >> n;
  vii a(n, vi(2));
  vii p(n);
  rep (i, n) {
    cin >> a[i][0] >> a[i][1];
    a[i][0]--; a[i][1]--;
    sort(all(a[i]));
    p[a[i][0]].push_back(i);
    p[a[i][1]].push_back(i);
  }
  rep (i, n) {
    sort(all(p[i]));
  }
  if (n <= 5) {
    vi p(n);
    rep (i, n) {
      p[i] = i;
    }
    do {
      bool flag = true;
      rep (i, n) {
        int h = p[i];
        int nn1 = p[(i + 1) % n], nn2 = p[(i + 2) % n];
        vi a2 = {nn1, nn2};
        sort(all(a2));
        if (a2 != a[i]) {
          flag = false;
          break;
        }
      }
      if (flag) {
        rep (i, n) {
          cout << p[i] + 1 << " ";
        }
        cout << endl;
        return 0;
      }
    }while(next_permutation(all(p)));
  }
  vi ans(n);
  rep (i, n) {
    int p1 = p[i][0];
    int nn1;
    if (a[p1][0] == i) {
      nn1 = a[p1][1];
    }
    else {
      nn1 = a[p1][0];
    }
    if (nn1 == a[i][0] || nn1 == a[i][1]) {
      ans[p1] = i;
      ans[i] = nn1;
      continue;
    }
    int p2 = p[i][1];
    int nn2;
    if (a[p2][0] == i) {
      nn2 = a[p2][1];
    }
    else {
      nn2 = a[p2][0];
    }
    ans[p2] = i;
    ans[i] = nn2;
  }
  int cnt = 0;
  int now = 0;
  while (cnt < n) {
    cout << ans[now]  + 1 << " ";
    now = ans[now];
    cnt++;
  }
  cout << endl;
}