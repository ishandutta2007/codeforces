#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

char str[500005];

int sum[500005];

int get(int l, int r) {
  return sum[r] - (l > 0 ? sum[l - 1] : 0);
}

int main() {
  gets(str);
  int n = strlen(str);
  for (int i = 0; i < n; ++i) {
    if (str[i] == 'I' || str[i] == 'E' || str[i] == 'A' || str[i] == 'O' || str[i] == 'U' || str[i] == 'Y')
      sum[i] = 1;
    if (i) sum[i] += sum[i - 1];
  }
  int mid = (n + 1) / 2;
  double ans = 0;
  long long sum = 0;
  for (int l = 1; l <= mid; ++l) {
    sum += 1LL * l * (get(l - 1, l - 1) + get(n - l, n - l));
    ans += 1.0 * (sum + 1LL * l * get(l, n - l - 1)) / l;
    if (l != mid || n % 2 == 0)
      ans += 1.0 * (sum + 1LL * l * get(l, n - l - 1)) / (n + 1 - l);

    // cout << l << "  " << (sum + 1LL * l * get(l, n - l - 1)) << endl;
    // cout << ans << endl;
  }
  printf("%.9lf\n", ans);
  return 0;
}