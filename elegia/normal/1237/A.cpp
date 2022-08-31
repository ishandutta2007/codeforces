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
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);
  int cnt = 0;
  for (int i = 0; i < n; ++i)
    cnt += a[i] & 1;
  cnt /= 2;
  for (int i = 0; i < n; ++i)
    if (a[i] & 1) {
      if (cnt) {
        --cnt;
        --a[i];
      } else
        ++a[i];
    }
  for (int x : a)
    printf("%d\n", x / 2);

  return 0;
}