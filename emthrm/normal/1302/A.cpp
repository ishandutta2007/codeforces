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
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
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
  int t; cin >> t;
  while (t--) {
    int n; string s; cin >> n >> s;
    while (!s.empty() && (s.back() - '0') % 2 == 0) s.pop_back();
    if (s.empty()) {
      cout << "-1\n";
      continue;
    }
    int sum = 0;
    for (char c : s) sum += c - '0';
    if (sum % 2 == 0) {
      cout << s << '\n';
      continue;
    }
    REP(i, s.length()) {
      if (s[i] == '0') {
        s.erase(s.begin() + i);
        --i;
      }
    }
    bool ok = false;
    REP(i, s.length() - 1) {
      if ((s[i] - '0') & 1) {
        s.erase(s.begin() + i);
        cout << s << '\n';
        ok = true;
        break;
      }
    }
    if (!ok) cout << "-1\n";
  }
  return 0;
}