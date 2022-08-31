#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <iostream>
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

const int N = 150000;

int n;
ll a[N];
int b[N];

int prv(int x) {
  --x;
  x %= n;
  if (x == 0)
    x = n;
  return x;
}

int main() {
#ifdef CAI_WEI_HAN
	freopen("test.in", "r", stdin);
#endif

  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &b[i]);
  if (count(b + 1, b + n + 1, b[1]) == n) {
    if (b[1] == 0) {
      puts("YES");
      for (int rep = 0; rep < n; ++rep)
        printf("1 ");
    } else {
      puts("NO");
    }
    return 0;
  }
  int pos = 0, q = 0;
  for (int i = 1; i <= n; ++i)
    if (b[i] < b[i % n + 1]) {
      pos = i % n + 1;
      q = i;
      break;
    }
  a[pos] = b[pos];
  a[q] = 1000000007LL * b[pos] + b[q];
  for (int i = q; prv(i) != pos; i = prv(i))
    a[prv(i)] = a[i] + b[prv(i)];
  puts("YES");
  for (int i = 1; i <= n; ++i)
    printf("%lld ", a[i]);

  return 0;
}