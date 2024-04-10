#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

int query(ll c) {
  cout << "? " << c << endl;
  string ans; cin >> ans;
  while (ans != "0" && ans != "1");
  return stoi(ans);
}

void solve() {
  ll n; cin >> n;
  vector<ll> wid;
  {
    ll lb = 0, ub = n;
    while (ub - lb > 1) {
      ll mid = (lb + ub) / 2;
      wid.emplace_back(mid);
      lb = mid;
    }
  }
  reverse(ALL(wid));
  bool add = true;
  ll cur = 1;
  if (wid.size() % 2 == 1) {
    add = false;
    cur = n;
  }
  for (ll e : wid) {
    cur += e * (add ? 1 : -1);
    add = !add;
  }
  query(cur);
  ll lb = 0, ub = n;
  while (ub - lb > 1) {
    ll mid = (lb + ub) / 2, nx = cur + mid * (add ? 1 : -1);
    (query(nx) == 0 ? lb : ub) = mid;
    cur = nx;
    add = !add;
  }
  cout << "= " << ub << endl;
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}