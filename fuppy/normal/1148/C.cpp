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
#define endl '\n'
//#define mp make_pair

vi a;
vi pos;
vector<pii> ans;
int n;

void my_swap(int i, int j) {
  if (i == j) return;
  assert(abs(i - j) * 2 >= n);
  int x = a[i], y = a[j];
  ans.push_back(pii(i, j));
  swap(a[i], a[j]);
  pos[x] = j;
  pos[y] = i;
}

int main() {
  fio();
  cin >> n;
  a.resize(n);
  pos.resize(n);
  rep (i, n) {
    cin >> a[i];
    a[i]--;
    pos[a[i]] = i;
  }

  int l = n / 2 - 1, r = n / 2;
  rep (q, n) {
    if (q % 2 == 0) {
      int i = pos[l];
      if (i >= n / 2) {
        my_swap(0, i);
      }
      i = pos[l];
      my_swap(i, n - 1);
      my_swap(n - 1, l);
      l--;
    }
    else {
      int i = pos[r];
      if (i < n / 2) {
        my_swap(i, n - 1);
      }
      i = pos[r];
      my_swap(i, 0);
      my_swap(0, r);
      r++;
    }
  }
  cout << ans.size() << endl;
  rep (i, ans.size()) {
    cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
  }
}