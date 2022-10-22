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

template <typename T>
vector<T> divisor(T val) {
  vector<T> res;
  for (T i = 1; i * i <= val; ++i) {
    if (val % i == 0) {
      res.emplace_back(i);
      if (i * i != val) res.emplace_back(val / i);
    }
  }
  sort(ALL(res));
  return res;
}

template <typename T = char, typename U = string>
vector<pair<T, int> > rle(const U &s) {
  int n = s.size();
  vector<pair<T, int> > res;
  T now = s[0];
  int cnt = 1;
  FOR(i, 1, n) {
    if (s[i] != now) {
      res.emplace_back(now, cnt);
      cnt = 0;
    }
    now = s[i];
    ++cnt;
  }
  res.emplace_back(now, cnt);
  return res;
}

int main() {
  int n, m, k; cin >> n >> m >> k;
  vector<int> ds = divisor(k);
  vector<int> a(n), b(m);
  REP(i, n) cin >> a[i];
  auto A = rle<int>(a);
  vector<int> len;
  for (auto pr : A) {
    if (pr.first == 1) len.emplace_back(pr.second);
  }
  sort(ALL(len));
  int sum = accumulate(ALL(len), 0);
  REP(i, m) cin >> b[i];
  auto B = rle<int>(b);
  ll ans = 0;
  for (auto pr : B) {
    if (pr.first == 1) {
      int width = pr.second, idx = 0;
      for (int i = ds.size() - 1; i >= 0; --i) {
        if (ds[i] > width) continue;
        int h = k / ds[i];
        while (idx < len.size() && len[idx] < h) sum -= len[idx++];
        ans += 1LL * (width - ds[i] + 1) * (sum - 1LL * (h - 1) * (len.size() - idx));
      }
      sum = accumulate(ALL(len), 0);
    }
  }
  cout << ans << '\n';
  return 0;
}