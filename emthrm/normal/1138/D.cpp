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
int popcount(int val) { return __builtin_popcount(val); }
int popcountll(ll val) { return __builtin_popcountll(val); }
template <typename T> void unique(vector<T> &a) { a.erase(unique(ALL(a)), a.end()); }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

struct MP {
  vector<int> border;

  MP(const string &s) : str(s) {
    int n = str.length();
    border.assign(1, -1);
    REP(i, n) solve(i);
  }

  void add(char c) {
    int idx = str.length();
    str += c;
    solve(idx);
  }

  vector<int> match(const string &t) {
    int n = str.length(), m = t.length();
    vector<int> res;
    int k = 0;
    REP(i, m) {
      while (k >= 0 && t[i] != str[k]) k = border[k];
      if (++k == n) res.emplace_back(i - n + 1);
    }
    return res;
  }

  int period(int idx) { return idx - border[idx]; }

private:
  int j = -1;
  string str;

  void solve(int idx) {
    while (j >= 0 && str[idx] != str[j]) j = border[j];
    border.emplace_back(++j);
  }
};

int main() {
  string s, t; cin >> s >> t;
  int zero = count(ALL(s), '0'), one = count(ALL(s), '1');
  MP mp(t);
  string ans = "";
  int period = mp.period(t.length()), pos = 0;
  while (true) {
    if (t[pos] == '0') {
      if (zero == 0) break;
      ans += '0';
      --zero;
    } else {
      if (one == 0) break;
      ans += '1';
      --one;
    }
    pos = (pos + 1) % period;
  }
  REP(_, zero) ans += '0';
  REP(_, one) ans += '1';
  cout << ans << '\n';
  return 0;
}