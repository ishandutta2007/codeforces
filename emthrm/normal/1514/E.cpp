#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

int q1 = 0, q2 = 0;

bool query1(int a, int b) {
  cout << "1 " << a << ' ' << b << endl;
  int res; cin >> res;
  return res == 1;
}

bool query2(int x, const vector<int> &s) {
  int k = s.size();
  cout << "2 " << x << ' ' << k << ' ';
  REP(i, k) {
    cout << s[i];
    if (i + 1 == k) {
      cout << endl;
    } else {
      cout << ' ';
    }
  }
  int res; cin >> res;
  return res == 1;
}

void solve() {
  int n; cin >> n;
  q1 = q2 = 0;
  auto f = [&](auto &&f, int l, int r) -> vector<int> {
    if (r - l <= 1) return {l};
    int m = (l + r) / 2;
    vector<int> path(r - l), path_l = f(f, l, m), path_r = f(f, m, r);
    merge(ALL(path_l), ALL(path_r), path.begin(),
          [&](int a, int b) -> bool { return query1(a, b); });
    return path;
  };
  vector<int> path = f(f, 0, n);
  assert(q1 <= n * 9);
  // REP(i, n - 1) assert(query1(path[i], path[i + 1]));
  // REP(i, n) cout << path[i] << " \n"[i + 1 == n];
  vector<vector<int>> graph(n);
  FOR(i, 1, n) graph[path[i - 1]].emplace_back(path[i]);
  int ptr = n - 1;
  for (int i = n - 1; i >= 0; --i) {
    chmin(ptr, i);
    while (ptr > 0 && query2(path[i], vector<int>(path.begin(), path.begin() + ptr))) --ptr;
    graph[path[i]].emplace_back(path[ptr]);
  }
  assert(q2 <= n * 2);
  vector ans(n, vector(n, false));
  REP(i, n) {
    ans[i][i] = true;
    queue<int> que({i});
    while (!que.empty()) {
      int node = que.front(); que.pop();
      for (int e : graph[node]) {
        if (!ans[i][e]) {
          ans[i][e] = true;
          que.emplace(e);
        }
      }
    }
  }
  cout << "3\n";
  REP(i, n) {
    REP(j, n) cout << ans[i][j];
    if (i + 1 == n) {
      cout << endl;
    } else {
      cout << '\n';
    }
  }
  int res; cin >> res;
  assert(res == 1);
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}