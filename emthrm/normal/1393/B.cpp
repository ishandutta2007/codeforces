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
  multiset<int> st;
  map<int, int> mp;
  while (n--) {
    int a; cin >> a;
    ++mp[a];
  }
  for (auto pr : mp) st.emplace(pr.second);
  int q; cin >> q;
  while (q--) {
    char symbol; int x; cin >> symbol >> x;
    if (mp.count(x) == 0) st.emplace(mp[x]);
    st.erase(st.lower_bound(mp[x]));
    mp[x] += symbol == '+' ? 1 : -1;
    st.emplace(mp[x]);
    if (st.size() == 1) {
      int v = *st.begin();
      cout << (v >= 8 ? "YES\n" : "NO\n");
    } else if (st.size() == 2) {
      int u = *st.begin(), v = *next(st.begin());
      if (v < 4) {
        cout << "NO\n";
        continue;
      }
      v -= 4;
      if (u >= 4 || v >= 4) {
        cout << "YES\n";
      } else {
        int two = (u >= 2) + (v >= 2);
        cout << (two >= 2 ? "YES\n" : "NO\n");
      }
    } else {
      int t = *prev(prev(prev(st.end()))), u = *prev(prev(st.end())), v = *prev(st.end());
      if (v < 4) {
        cout << "NO\n";
        continue;
      }
      v -= 4;
      if (t >= 4 || u >= 4 || v >= 4) {
        cout << "YES\n";
      } else {
        int two = (t >= 2) + (u >= 2) + (v >= 2);
        cout << (two >= 2 ? "YES\n" : "NO\n");
      }
    }
  }
  return 0;
}