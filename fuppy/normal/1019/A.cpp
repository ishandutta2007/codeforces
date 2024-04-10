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
const ll INF = 1e18;
const ll MOD = 1000000007;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
#define mp make_pair


int main () {
  int n, m;
  scanf("%d %d", &n, &m);
  if (m == 1) {
    cout << 0 << endl;
    return 0;
  }
  vll c(m);
  multiset<ll> st;
  rep (i, n) {
    int j, co;
    scanf("%d %d", &j, &co);
    j--;
    c[j].push_back(co);
    if (j != 0) {
      st.insert(co);
    }
  }
  rep (i, m) {
    sort(all(c[i]));
  }
  vll sum(m);
  rep (i, m) {
    sum[i].resize(c[i].size() + 1);
    rep (j, c[i].size()) {
      sum[i][j + 1] = sum[i][j] + c[i][j];
    }
  }
  ll ans = INF;
  for (int i = 0; i < n; i++) {
    int cnt = c[0].size();
    ll cost = 0;
    auto mst = st;
    rep1 (j, m - 1) {
      if (c[j].size() > i) {
        int add = (int)c[j].size() - i;
        for (int k = 0; k < add; k++) {
          cost += c[j][k];
          auto itr = mst.lower_bound(c[j][k]);
          mst.erase(itr);
        }
        cnt += add;
      }
    }
    while (cnt <= i) {
      cost += *mst.begin();
      mst.erase(mst.begin());
      cnt++;
    }
    chmin(ans, cost);
  }
  cout << ans << endl;   
}