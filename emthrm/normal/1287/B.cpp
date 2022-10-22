#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
template <typename T> using posteriority_queue = priority_queue<T, vector<T>, greater<T> >;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
// const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
template <typename T> void unique(vector<T> &a) { a.erase(unique(ALL(a)), a.end()); }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

int main() {
  int n, k; cin >> n >> k;
  vector<string> s(n); REP(i, n) cin >> s[i];
  ll ans = 0;
  REP(i, n) {
    map<string, int> mp;
    FOR(j, i + 1, n) ++mp[s[j]];
    FOR(j, i + 1, n) {
      string card = "";
      REP(x, k) {
        char a = s[i][x], b = s[j][x];
        if (a > b) swap(a, b);
        if (a == b) {
          card += a;
        } else if (a == 'E' && b == 'S') {
          card += 'T';
        } else if (a == 'E' && b == 'T') {
          card += 'S';
        } else if (a == 'S' && b == 'T') {
          card += 'E';
        }
      }
      if (mp.count(card) == 1) ans += mp[card];
      --mp[s[j]];
      if (mp[s[j]] == 0) mp.erase(s[j]);
    }
  }
  cout << ans << '\n';
  return 0;
}