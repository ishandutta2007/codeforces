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

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
#endif

  int n;
  scanf("%d", &n);
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    a[x - 1] = n - 1 - i;
  }
  int ans = 0, lst = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
    --b[i];
  }
  reverse(b.begin(), b.end());
  for (int i = 0; i < n; ++i) {
    if (a[b[i]] < lst)
      ++ans;
    lst = max(lst, a[b[i]]);
  }
  printf("%d\n", ans);

  return 0;
}