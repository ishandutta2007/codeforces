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

int main() {
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  vector<int> fr;
  REP(j, a[0]) fr.emplace_back(j);
  FOR(i, 1, n) {
    FOR(j, a[i - 1] + 1, a[i]) fr.emplace_back(j);
  }
  FOR(j, a[n - 1] + 1, 1000000) fr.emplace_back(j);
  reverse(ALL(fr));
  set<int> rem;
  REP(i, n + 1) rem.emplace(i);
  REP(i, n) {
    if (*rem.begin() == a[i]) {
      while (rem.count(fr.back()) == 0) fr.pop_back();
      cout << fr.back() << " \n"[i + 1 == n];
      rem.erase(fr.back());
      fr.pop_back();
    } else {
      cout << *rem.begin() << " \n"[i + 1 == n];
      rem.erase(rem.begin());
    }
  }
  return 0;
}