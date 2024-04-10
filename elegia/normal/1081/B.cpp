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

const int N = 100010;

int n, cc;
int a[N], cnt[N], b[N], cur[N];

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    ++cnt[n - a[i]];
  }
  for (int i = 1; i <= n; ++i) {
    if (cnt[i] % i) {
      puts("Impossible");
      return 0;
    }
  }
  for (int i = 1; i <= n; ++i) {
    int my = n - a[i];
    if (!cur[my]) {
      cur[my] = ++cc;
    }
    b[i] = cur[my];
    if (--cnt[my] % my == 0)
      cur[my] = 0;
  }
  puts("Possible");
  for (int i = 1; i <= n; ++i)
    printf("%d ", b[i]);
  
#ifdef LBT
  LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}