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

std::vector<int> topological_sort(const std::vector<std::vector<int>> &graph) {
  int n = graph.size();
  std::vector<int> deg(n, 0);
  for (int i = 0; i < n; ++i) {
    for (int e : graph[i]) ++deg[e];
  }
  std::queue<int> que;
  for (int i = 0; i < n; ++i) {
    if (deg[i] == 0) que.emplace(i);
  }
  std::vector<int> res;
  while (!que.empty()) {
    int ver = que.front(); que.pop();
    res.emplace_back(ver);
    for (int e : graph[ver]) {
      if (--deg[e] == 0) que.emplace(e);
    }
  }
  return res.size() == n ? res : std::vector<int>();
}

int main() {
  int n, m, k; cin >> n >> m >> k;
  vector<string> p(n);
  map<string, int> mp;
  REP(i, n) {
    cin >> p[i];
    mp[p[i]] = i;
  }
  vector<vector<int>> graph(n);
  while (m--) {
    string s; int mt; cin >> s >> mt; --mt;
    bool match = true;
    REP(i, k) match &= p[mt][i] == '_' || p[mt][i] == s[i];
    if (!match) {
      cout << "NO\n";
      return 0;
    }
    REP(i, 1 << k) {
      string t = s;
      REP(j, k) {
        if (i >> j & 1) t[j] = '_';
      }
      if (mp.count(t) == 1 && mp[t] != mt) {
        // cout << s << " : " << mt << ' ' << mp[t] << '\n';
        graph[mt].emplace_back(mp[t]);
      }
    }
  }
  vector<int> ts = topological_sort(graph);
  if (ts.empty()) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  REP(i, n) cout << ts[i] + 1 << " \n"[i + 1 == n];
  return 0;
}