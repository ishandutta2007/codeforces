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

struct Xor128 {
  int rand() {
    unsigned t = x ^ (x << 11);
    x = y; y = z; z = w; w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
    return static_cast<int>(w);
  }
  int rand(int ub) {
    int res = rand() % ub;
    return res < 0 ? res + ub : res;
  }
  int rand(int lb, int ub) { return lb + rand(ub - lb); }
  ll randll() {
    unsigned long long res = static_cast<unsigned long long>(rand()) << 32;
    return static_cast<ll>(res | rand());
  }
  ll randll(ll ub) {
    ll res = randll() % ub;
    return res < 0 ? res + ub : res;
  }
  ll randll(ll lb, ll ub) { return lb + randll(ub - lb); }
private:
  unsigned x = 123456789, y = 362436069, z = 521288629, w = static_cast<unsigned>(time(nullptr));
} xor128;

struct Timer {
  Timer() { reset(); }
  void reset() { beg = chrono::high_resolution_clock::now(); }
  ll elapsed() {
    chrono::high_resolution_clock::time_point en = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::milliseconds>(en - beg).count();
  }
private:
  chrono::high_resolution_clock::time_point beg;
} timer;

template <typename T>
vector<pair<T, int> > prime_factorization(T val) {
  vector<pair<T, int> > res;
  for (T i = 2; i * i <= val; ++i) {
    if (val % i != 0) continue;
    int exponent = 0;
    while (val % i == 0) {
      ++exponent;
      val /= i;
    }
    res.emplace_back(i, exponent);
  }
  if (val != 1) res.emplace_back(val, 1);
  return res;
}

int main() {
  int n; cin >> n;
  int ans = 0;
  vector<ll> a(n);
  REP(i, n) {
    cin >> a[i];
    ans += a[i] & 1;
  }
  vector<bool> visited(n, false);
  set<ll> st;
  while (timer.elapsed() < 2000) {
    int idx = xor128.rand(n);
    if (visited[idx]) continue;
    visited[idx] = true;
    vector<ll> cand;
    {
      auto p = prime_factorization(a[idx]);
      for (auto pr : p) {
        if (st.count(pr.first) == 0) {
          cand.emplace_back(pr.first);
          st.emplace(pr.first);
        }
      }
    }
    if (a[idx] > 1) {
      auto p = prime_factorization(a[idx] - 1);
      for (auto pr : p) {
        if (st.count(pr.first) == 0) {
          cand.emplace_back(pr.first);
          st.emplace(pr.first);
        }
      }
    }
    {
      auto p = prime_factorization(a[idx] + 1);
      for (auto pr : p) {
        if (st.count(pr.first) == 0) {
          cand.emplace_back(pr.first);
          st.emplace(pr.first);
        }
      }
    }
    for (ll now : cand) {
      if (timer.elapsed() >= 2450) break;
      ll cnt = 0;
      for (ll e : a) {
        if (cnt >= ans) break;
        ll tmp = e / now * now;
        cnt += tmp == 0 ? now - e : min(e - tmp, tmp + now - e);
      }
      chmin(ans, cnt);
    }
  }
  cout << ans << '\n';
  return 0;
}