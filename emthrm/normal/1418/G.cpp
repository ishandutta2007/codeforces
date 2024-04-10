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

int compress(vector<int> &a) {
  vector<int> b(a);
  sort(ALL(b));
  b.erase(unique(ALL(b)), b.end());
  for (int &e : a) e = lower_bound(ALL(b), e) - b.begin();
  return b.size();
}

ll solve(int n, int m, const vector<int> &a) {
  mt19937_64 rng(time(nullptr));
  vector<unsigned ll> v(m);
  REP(i, m) v[i] = rng();
  vector<int> cnt(m, 0);
  vector<unsigned ll> hash(n + 1, 0);
  int pos = 0;
  vector<queue<int>> que(m);
  map<unsigned ll, int> mp;
  mp[0] = 1;
  ll ans = 0;
  FOR(i, 1, n + 1) {
    hash[i] = hash[i - 1] - v[a[i]] * cnt[a[i]];
    (cnt[a[i]] += 1) %= 3;
    hash[i] += v[a[i]] * cnt[a[i]];
    if (que[a[i]].size() == 3) {
      int r = que[a[i]].front(); que[a[i]].pop();
      while (pos < r) --mp[hash[pos++]];
    }
    que[a[i]].emplace(i);
    ans += mp[hash[i]];
    ++mp[hash[i]];
  }
  return ans;
}

int main() {
  int n; cin >> n;
  vector<int> a(n + 1); FOR(i, 1, n + 1) cin >> a[i];
  a[0] = a[1];
  int m = compress(a);
  a[0] = -1;
  vector<ll> ans(6);
  REP(i, 6) ans[i] = solve(n, m, a);
  cout << *min_element(ALL(ans)) << '\n';
  return 0;
}