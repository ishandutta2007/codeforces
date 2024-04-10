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
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
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

template <typename Abelian>
struct BIT0based {
  BIT0based(int n, const Abelian UNITY = 0) : n(n), UNITY(UNITY), dat(n, UNITY) {}

  void add(int idx, Abelian val) {
    while (idx < n) {
      dat[idx] += val;
      idx |= idx + 1;
    }
  }

  Abelian sum(int idx) {
    Abelian res = UNITY;
    --idx;
    while (idx >= 0) {
      res += dat[idx];
      idx = (idx & (idx + 1)) - 1;
    }
    return res;
  }

  Abelian sum(int left, int right) {
    if (right <= left) return UNITY;
    return sum(right) - sum(left);
  }

  Abelian operator[](const int idx) { return sum(idx, idx + 1); }

  int lower_bound(Abelian val) {
    if (val <= UNITY) return 0;
    int res = 0, exponent = 1;
    while (exponent <= n) exponent <<= 1;
    for (int mask = exponent >> 1; mask > 0; mask >>= 1) {
      if (res + mask - 1 < n && dat[res + mask - 1] < val) {
        val -= dat[res + mask - 1];
        res += mask;
      }
    }
    return res;
  }

private:
  int n;
  const Abelian UNITY;
  vector<Abelian> dat;
};

void solve() {
  int n, d; cin >> n >> d;
  int sum = (n - 1) * n / 2;
  if (sum < d) {
    cout << "NO\n";
    return;
  }
  vector<int> p(n, -1);
  FOR(i, 1, n) p[i] = i - 1;
  vector<int> child(n, 1);
  child[n - 1] = 0;
  vector<vector<int> > depth(n);
  REP(i, n) depth[i].emplace_back(i);
  int now = 0, idx = 0;
  for (int i = n - 1; sum > d && i >= max(now, 1); --i) {
    if (child[i] > 0) continue;
    --child[p[i]];
    if (sum - d >= i - now - 1) {
      sum -= i - now - 1;
      p[i] = depth[now][idx];
      depth[i].erase(lower_bound(ALL(depth[i]), i));
      depth[now + 1].emplace_back(i);
      ++child[p[i]];
      if (child[p[i]] == 2) {
        ++idx;
        if (idx >= depth[now].size()) {
          ++now;
          idx = 0;
        }
      }
    } else {
      int pos = i - 1 - (sum - d);
      sum = d;
      p[i] = depth[pos][0];
      break;
    }
    // REP(i, n) {
    //   cout << i << ": ";
    //   for (int e : depth[i]) cout << e << ' ';
    //   cout << '\n';
    // }
    // cout << '\n';
    // FOR(i, 1, n) cout << p[i] + 1 << " \n"[i + 1 == n];
  }
  if (sum > d) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  FOR(i, 1, n) cout << p[i] + 1 << " \n"[i + 1 == n];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}