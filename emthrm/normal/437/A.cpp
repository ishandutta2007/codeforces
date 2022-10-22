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
  vector<string> choice(4);
  REP(i, 4) {
    cin >> choice[i];
    choice[i] = choice[i].substr(2);
  }
  set<char> st;
  REP(i, 4) {
    bool ok = true;
    REP(j, 4) {
      if (i == j) continue;
      ok &= choice[i].length() * 2 <= choice[j].length();
    }
    if (ok) {
      st.emplace('A' + i);
      continue;
    }
    ok = true;
    REP(j, 4) {
      if (i == j) continue;
      ok &= choice[i].length() >= choice[j].length() * 2;
    }
    if (ok) {
      st.emplace('A' + i);
      continue;
    }
  }
  if (st.size() == 1) {
    cout << *st.begin() << '\n';
  } else {
    cout << "C\n";
  }
  return 0;
}