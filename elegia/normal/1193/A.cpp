#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>

#include <algorithm>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef unsigned long long ll;

// mt199315 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 21, P = 998244353;

int n;
int adj[N];
int f[1 << N][N + 1];

int norm(int x) { return x >= P ? x - P : x; }

void add(int& x, int y) {
  if ((x += y) >= P)
    x -= P;
}

void sub(int& x, int y) {
  if ((x -= y) < 0)
    x += P;
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  int m;
  scanf("%d%d", &n, &m);
  for (int rep = 0; rep < m; ++rep) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u; --v;
    adj[u] |= 1 << v;
    adj[v] |= 1 << u;
  }
  for (int s = 0; s < 1 << n; ++s) {
    f[s][__builtin_popcount(s)] = 1;
    for (int i = 0; i < n; ++i)
      if ((s >> i & 1) && (s & adj[i])) {
        f[s][__builtin_popcount(s)] = 0;
        break;
      }
  }
  for (int i = 0; i < n; ++i)
    for (int s = 0; s < 1 << n; ++s)
      if (s >> i & 1) {
        for (int j = 0; j <= n; ++j)
          add(f[s][j], f[s ^ 1 << i][j]);
      }
  int ans = 0;
  for (int s = 0; s < 1 << n; ++s) {
    static int tmp[N + 1];
    tmp[0] = 1;
    for (int i = 1; i <= n; ++i) {
      tmp[i] = 0;
      for (int j = 1; j <= i; ++j)
        sub(tmp[i], tmp[i - j] * (ll)f[s][j] % P);
    }
    if (__builtin_parity(s))
      sub(ans, tmp[n]);
    else
      add(ans, tmp[n]);
  }
  ans = ans * (ll)m % P * (P + 1) / 2 % P;
  printf("%d\n", ans);

#ifdef LBT
  LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}