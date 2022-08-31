#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <numeric>
#include <functional>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int N = 100010, K = N * 11, P = 1000000007;

int n, m, c;
vector<pair<int, int>> ed[K];
vector<int> sv[10];
int hsh[K];
int que[K];
bool ch[K];

void adde(int u, int v, int w) {
  static int dig[10];
  int cnt = 0;
  while (w) {
    dig[++cnt] = w % 10;
    w /= 10;
  }
  int cur = u;
  for (int i = cnt; i > 1; --i) {
    ed[cur].emplace_back(++c, dig[i]);
    cur = c;
  }
  ed[cur].emplace_back(v, dig[1]);
}

int main() {
//  freopen("test.in", "r", stdin);
//  freopen("test.out", "w", stdout);
  
  scanf("%d%d", &n, &m);
  c = n;
  for (int i = 1; i <= m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    adde(x, y, i);
    adde(y, x, i);
  }
  memset(hsh, -1, sizeof(hsh));
  hsh[1] = 0;
  int ql = 0, qr = 0;
  que[qr++] = 1;
  ch[0] = true;
  while (ql < qr) {
    bool fl = ch[ql];
    int u = que[ql++];
    for (const auto& pr : ed[u])
      sv[pr.second].push_back(pr.first);
    if (!fl) continue;
    for (int d = 0; d < 10; ++d) {
      bool fg = false;
      for (int v : sv[d]) {
        if (hsh[v] != -1) continue;
        que[qr++] = v;
        fg = true;
        hsh[v] = (hsh[u] * 10LL + d) % P;
      }
      sv[d].clear();
      if (fg) ch[qr - 1] = true;
    }
  }
  for (int i = 2; i <= n; ++i)
    printf("%d\n", hsh[i]);
  
  return 0;
}