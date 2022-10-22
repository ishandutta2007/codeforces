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
  int n, q; cin >> n >> q;
  vector<vector<bool> > lava(2, vector<bool>(n, false));
  set<pair<int, int> > st;
  while (q--) {
    int r, c; cin >> r >> c; --r; --c;
    int pos = r * n + c;
    if (r == 0) {
      if (lava[r][c]) {
        if (c - 1 >= 0 && lava[1][c - 1]) st.erase(make_pair(pos, n + c - 1));
        if (lava[1][c]) st.erase(make_pair(pos, n + c));
        if (c + 1 < n && lava[1][c + 1]) st.erase(make_pair(pos, n + c + 1));
      } else {
        if (c - 1 >= 0 && lava[1][c - 1]) st.insert(make_pair(pos, n + c - 1));
        if (lava[1][c]) st.insert(make_pair(pos, n + c));
        if (c + 1 < n && lava[1][c + 1]) st.insert(make_pair(pos, n + c + 1));
      }
    } else {
      if (lava[r][c]) {
        if (c - 1 >= 0 && lava[0][c - 1]) st.erase(make_pair(c - 1, pos));
        if (lava[0][c]) st.erase(make_pair(c, pos));
        if (c + 1 < n && lava[0][c + 1]) st.erase(make_pair(c + 1, pos));
      } else {
        if (c - 1 >= 0 && lava[0][c - 1]) st.insert(make_pair(c - 1, pos));
        if (lava[0][c]) st.insert(make_pair(c, pos));
        if (c + 1 < n && lava[0][c + 1]) st.insert(make_pair(c + 1, pos));
      }
    }
    lava[r][c] = !lava[r][c];
    cout << (st.empty() ? "Yes\n" : "No\n");
  }
  return 0;
}