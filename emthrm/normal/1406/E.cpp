#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

std::vector<bool> sieve_of_eratosthenes(int val) {
  std::vector<bool> res(val + 1, true);
  res[0] = false;
  if (val >= 1) res[1] = false;
  for (int i = 2; i * i <= val; ++i) {
    if (res[i]) {
      for (int j = i * i; j <= val; j += i) res[j] = false;
    }
  }
  return res;
}

int n;
// set<int> st;

int query(char c, int a) {
  cout << c << ' ' << a << endl;
  int multiples; cin >> multiples;
  return multiples;
  // int multiples = 0;
  // for (int i = a; i <= n; i += a) {
  //   multiples += st.count(i);
  //   if (c == 'B' && i != 99991) st.erase(i);
  // }
  // return multiples;
}

constexpr int MAX = 9999;

int main() {
  cin >> n;
  // FOR(i, 1, n + 1) st.emplace(i);
  vector<bool> sieve = sieve_of_eratosthenes(n);
  vector<int> ps;
  for (int i = n; i >= 2; --i) {
    if (sieve[i]) ps.emplace_back(i);
  }
  int q = 0, ans = 1;
  while (!ps.empty()) {
    int p = ps.back();
    if (p * p > n) break;
    ps.pop_back();
    q += 2;
    query('B', p);
    if (query('A', p) == 1) {
      int mul = p;
      while (1LL * mul * p * ans <= n) {
        ++q;
        if (query('A', mul * p) == 0) break;
        mul *= p;
      }
      ans *= mul;
    }
  }
  ++q;
  int cur = query('A', 1);
  reverse(ALL(ps));
  while (!ps.empty() && 1LL * ans * ps.back() > n) ps.pop_back();
  int x = ps.size();
  FOR(block, 1, x + 1) {
    if (x + (x + block - 1) / block + block + q <= MAX) {
      for (int i = 0; i < x; i += block) {
        int mul = -1;
        for (int j = i; j < i + block && j < x; ++j) {
          if (query('B', ps[j]) == 2) mul = ps[j];
          --cur;
        }
        if (mul != -1) {
          ans *= mul;
          break;
        }
        if (query('A', 1) > cur) {
          for (int j = i; j < i + block && j < x; ++j) {
            if (query('A', ps[j]) == 1) {
              ans *= ps[j];
              break;
            }
          }
          break;
        }
      }
      break;
    }
  }
  cout << "C " << ans << endl;
  return 0;
}