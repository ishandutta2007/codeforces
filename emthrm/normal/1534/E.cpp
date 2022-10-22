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

ll query(vector<int> &x) {
  cout << '?';
  for (int xi : x) cout << ' ' << xi + 1;
  cout << endl;
  ll res; cin >> res;
  return res;
}

int main() {
  constexpr int Q = 500;
  int n, k; cin >> n >> k;
  vector<int> dist(n + 1, INF);
  dist[0] = 0;
  vector<int> prev(n + 1, -1);
  queue<int> que({0});
  while (!que.empty()) {
    int ver = que.front(); que.pop();
    for (int i = 0; i <= k; ++i) {
      if (i <= n - ver && k - i <= ver && dist[ver + i - (k - i)] == INF) {
        dist[ver + i - (k - i)] = dist[ver] + 1;
        prev[ver + i - (k - i)] = i;
        que.emplace(ver + i - (k - i));
      }
    }
  }
  if (dist[n] > Q) {
    cout << "-1" << endl;
  } else {
    int pos = n;
    vector<int> v;
    while (pos > 0) {
      v.emplace_back(prev[pos]);
      pos = pos - prev[pos] + (k - prev[pos]);
    }
    reverse(ALL(v));
    vector<int> off(n), on(n);
    iota(ALL(off), 0);
    ll ans = 0;
    for (int vi : v) {
      vector<int> x, nx_off, nx_on;
      REP(_, vi) {
        x.emplace_back(off.back());
        nx_on.emplace_back(off.back());
        off.pop_back();
      }
      REP(_, k - vi) {
        x.emplace_back(on.back());
        nx_off.emplace_back(on.back());
        on.pop_back();
      }
      ans ^= query(x);
      copy(ALL(nx_off), back_inserter(off));
      copy(ALL(nx_on), back_inserter(on));
    }
    cout << "! " << ans << endl;
  }
  return 0;
}