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


int main() {
  fio();
  int n;
  cin >> n;
  vl s(n), t(n);
  ll sums = 0, sumt = 0;
  rep (i, n) {
    cin >> s[i];
    sums += s[i];
  }
  rep (i, n) {
    cin >> t[i];
    sumt += t[i];
  }
  if (sums != sumt) {
    cout << "NO" << endl;
    return 0;
  }
  sort(all(t));
  int ti = 0;

  set<pll> st;
  rep (i, n) {
    st.insert(pll(s[i], i));
  }

  vector<pair<pii, int> > ans;
  while (ti < n) {
    pll left = *st.begin();
    st.erase(st.begin());
    ll xl = left.first;
    ll tar = t[ti];
    if (xl == tar) {
      ti++;
      continue;
    }
    if (xl > tar) {
      cout << "NO" << endl;
      return 0;
    }
    auto itr = st.lower_bound(pll(tar, 0));
    if (itr == st.end()) {
      cout << "NO" << endl;
      return 0;
    }
    pll right = *itr;
    st.erase(itr);
    ll xr = right.first;
    if (xr == tar) {
      st.insert(left);
      ti++;
      continue;
    }

    ll d = min(tar - xl, xr - tar);
    left.first += d;
    right.first -= d;
    ans.push_back({pii(left.second + 1, right.second + 1), d});
    if (left.first == tar) {
      st.insert(right);
    }
    else {
      st.insert(left);
    }
    ti++;
  }

  assert(st.size() == 0);
  cout << "YES" << endl;
  cout << ans.size() << endl;
  rep (i, ans.size()) {
    cout << ans[i].first.first << " " << ans[i].first.second << " " << ans[i].second << endl;
  }
}