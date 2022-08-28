#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <numeric>
#include <limits>
#include <functional>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

struct Node {
  int u, v, w;
  
  bool operator<(const Node& rhs) const { return w < rhs.w; }
}; 

const int N = 100010;

int n, m, k, ans;
int f[N], cnt[N], x[N];
Node ed[N];

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < k; ++i) {
    int ig;
    scanf("%d", &ig);
    cnt[ig] = 1;
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d%d", &ed[i].u, &ed[i].v, &ed[i].w);
  }
  sort(ed + 1, ed + m + 1);
  iota(f + 1, f + n + 1, 1);
  for (int i = 1; i <= m; ++i) {
    int x = find(ed[i].u), y = find(ed[i].v);
    if (x != y) {
      if (cnt[y] && cnt[x])
        ans = ed[i].w;
      f[x] = y;
      cnt[y] += cnt[x];
    }
  }
  while (k--)
    printf("%d ", ans);

#ifdef LBT
  LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}