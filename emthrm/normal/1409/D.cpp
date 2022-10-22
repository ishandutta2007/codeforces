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

void solve() {
  string n; int s; cin >> n >> s;
  reverse(ALL(n));
  int sum = 0;
  for (char c : n) sum += c - '0';
  ll ans = 0, wei = 1;
  for (int i = 0; sum > s; ++i, wei *= 10) {
    if (n[i] == '0') continue;
    ans += wei * (10 - (n[i] - '0'));
    sum -= n[i] - '0';
    n[i] = '0';
    bool carry = true;
    for (int j = i + 1; carry; ++j) {
      if (j == n.length()) {
        n += '1';
        ++sum;
        carry = false;
      } else {
        sum -= n[j] - '0';
        int val = n[j] - '0' + 1;
        if (val < 10) {
          sum += val;
          n[j] = '0' + val;
          carry = false;
        } else {
          n[j] = '0';
        }
      }
    }
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}