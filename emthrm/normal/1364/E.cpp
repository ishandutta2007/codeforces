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

int query(int i, int j) {
  cout << "? " << i + 1 << ' ' << j + 1 << endl;
  int ans; cin >> ans;
  assert(ans != -1);
  return ans;
}

int main() {
  int n; cin >> n;
  int q = 0, idx;
  while (true) {
    int i = xor128.rand(n), j = xor128.rand(n);
    if (i == j) continue;
    ++q;
    if (q + (n - 1) * 2 + (1 << (__builtin_popcount(query(i, j)) + 1)) <= 4269) {
      idx = i;
      break;
    }
  }
  vector<int> cand(n);
  iota(ALL(cand), 0);
  cand.erase(cand.begin() + idx);
  while (!cand.empty()) {
    assert(cand.size() >= 2);
    vector<int> vals;
    map<int, vector<int>> mp;
    for (int e : cand) {
      int ans = query(idx, e);
      vals.emplace_back(ans);
      mp[ans].emplace_back(e);
    }
    cand.clear();
    sort(ALL(vals), [](int a, int b) { return __builtin_popcount(a) < __builtin_popcount(b); });
    if (__builtin_popcount(vals[0]) == 1 && __builtin_popcount(vals[1]) == 1) break;
    if (mp[vals[0]].size() == 1) {
      idx = mp[vals[0]][0];
      break;
    }
    cand = mp[vals[0]];
    swap(idx, cand[xor128.rand(cand.size())]);
  }
  vector<int> p(n, 0);
  REP(i, n) {
    if (i != idx) p[i] = query(idx, i);
  }
  cout << "! ";
  REP(i, n) {
    cout << p[i];
    if (i + 1 == n) {
      cout << endl;
    } else {
      cout << ' ';
    }
  }
  return 0;
}