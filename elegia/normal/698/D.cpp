#include <bits/stdc++.h>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Vec {
  int x, y;
  Vec(int x = 0, int y = 0) : x(x), y(y) {}
  Vec operator+(const Vec& rhs) const { return Vec(x + rhs.x, y + rhs.y); }
  Vec operator-() const { return Vec(-x, -y); }
  Vec operator-(const Vec& rhs) const { return *this + (-rhs); }
  ll operator^(const Vec& rhs) const { return x * (ll)rhs.x + y * (ll)rhs.y; }
  ll operator*(const Vec& rhs) const { return x * (ll)rhs.y - rhs.x * (ll)y; }
};

const int N = 1010, K = 10;

int k, n, cnt;
Vec a[K], m[N];
vector<int> block[N][K];
int tmp[K * 2];
int t[N], vis[N];
bool use[K];

bool dfs(int j) {
  if (j > cnt) return true;
  for (int i = 1; i <= k; ++i) {
    if (use[i]) continue;
    for (int y = j; y <= cnt; ++y) {
      swap(tmp[j], tmp[y]);
      int o = cnt;
      int brkx = 0;
      for (int x : block[tmp[j]][i]) {
        if (t[x]) {
          brkx = x;
          break;
        }
        if (vis[x]++ == 0)
          tmp[++cnt] = x;
        if (cnt > k) {
          brkx = x;
          break;
        }
      }
      if (!brkx) {
        use[i] = true;
        t[tmp[j]] = j;
        if (dfs(j + 1))
          return true;
        t[tmp[j]] = 0;
        use[i] = false;
      }
      for (int x : block[tmp[j]][i]) {
        if (t[x]) break;
        --vis[x];
        if (brkx == x) break;
      }
      cnt = o;
//      if (!brkx) break;
    }
    for (int y = cnt; y > j; --y) swap(tmp[y], tmp[j]);
  }
  return false;
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> k >> n;
  for (int i = 1; i <= k; ++i) cin >> a[i].x >> a[i].y;
  for (int i = 1; i <= n; ++i) cin >> m[i].x >> m[i].y;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= k; ++j)
      for (int l = 1; l <= n; ++l)
        if (((m[i] - m[l]) ^ (a[j] - m[l])) < 0 && ((m[l] - a[j]) * (m[i] - a[j])) == 0) {
          block[i][j].push_back(l);
          if (block[i][j].size() > k) break;
        }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    tmp[++cnt] = i;
    vis[i] = 1;
    ans += dfs(1);
    memset(t, 0, sizeof(t));
    memset(vis, 0, sizeof(vis));
    memset(tmp, 0, sizeof(tmp));
    memset(use, 0, sizeof(use));
    cnt = 0;
  }
  cout << ans;

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
      -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}