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
constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
constexpr int DY4[]{1, 0, -1, 0}, DX4[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1};
constexpr int DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U>
inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U>
inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

vector<int> generate_b(const vector<int>& a, const int k) {
  const int n = a.size();
  vector<int> b(n);
  REP(i, n) {
    const int x = a[i];
    if (x <= k) {
      b[x] = n;
      for (int j = i - 1; j >= 0; --j) {
        if (a[j] > k) {
          b[x] = a[j];
          break;
        }
      }
    } else {
      b[x] = -1;
      for (int j = i - 1; j >= 0; --j) {
        if (a[j] <= k) {
          b[x] = a[j];
          break;
        }
      }
    }
  }
  return b;
}

pair<vector<int>, int> solve(const vector<int>& b) {
  const int n = b.size();
  int lk = -1, rk = n - 1;
  REP(i, n) {
    if (b[i] == -1) {
      chmin(rk, i - 1);
    } else if (b[i] == n) {
      chmax(lk, i);
    } else if (i < b[i]) {
      chmax(lk, i);
      chmin(rk, b[i] - 1);
    } else {
      chmin(rk, i - 1);
      chmax(lk, b[i]);
    }
  }
  assert(lk == rk);  // i <=> a[i] 
  const int k = lk;
  assert(count(ALL(b), -1) == 0 || count(ALL(b), n) == 0);

  map<int, vector<int>> pos;
  REP(i, n) pos[b[i]].emplace_back(i);
  vector<int> que;
  REP(i, n) {
    if (b[i] == -1 || b[i] == n) que.emplace_back(i);
  }
  vector<int> a;
  a.reserve(n);
  while (!que.empty()) {
    for (int i = 0; i < que.size(); ++i) {
      if (pos.count(que[i])) {
        swap(que[i], que.back());
        break;
      }
    }
    vector<int> nxt;
    for (const int i : que) {
      a.emplace_back(i);
      const auto it = pos.find(i);
      if (it != pos.end()) {
        assert(nxt.empty());
        nxt = it->second;
      }
    }
    que.swap(nxt);
  }
  assert(a.size() == n);
  return {a, k};
}

void solve() {
  int n; cin >> n;
  vector<int> b(n); REP(i, n) cin >> b[i], --b[i];
  const auto [a, k] = solve(b);
  cout << k + 1 << '\n';
  REP(i, n) cout << a[i] + 1 << " \n"[i + 1 == n];
}

int main() {
  // constexpr int N = 7;
  // vector<int> a(N);
  // iota(ALL(a), 0);
  // do {
  //   FOR(k, -1, N) {
  //     const vector<int> b = generate_b(a, k);
  //     const auto [ans, ans_k] = solve(b);
  //     assert(ans_k == k);
  //     assert(b == generate_b(ans, k));
  //     // if (b != generate_b(ans, k)) {
  //     //   REP(i, N) cout << a[i] << " \n"[i + 1 == N];
  //     //   REP(i, N) cout << b[i] << " \n"[i + 1 == N];
  //     //   cout << k << '\n';
  //     //   REP(i, N) cout << ans[i] << " \n"[i + 1 == N];
  //     //   const vector<int> bad_b = generate_b(ans, k);
  //     //   REP(i, N) cout << bad_b[i] << " \n"[i + 1 == N];
  //     //   return 0;
  //     // }
  //   }
  // } while (next_permutation(ALL(a)));

  int t; cin >> t;
  while (t--) solve();
  return 0;
}