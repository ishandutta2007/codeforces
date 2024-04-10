#include <cstdio>
#include <cstring>

using namespace std;

const int N = 300010;

int n;
char x[N];

int main() {
  long long ans = 0;
  scanf("%s", x + 1);
  n = strlen(x + 1);
  int l = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = l + 1; j < i; ++j)
      if ((i - j) % 2 == 0 && x[i] == x[j] && x[i] == x[(i + j) >> 1])
        l = j;
    ans += l;
  }
  printf("%lld\n", ans);
  return 0;
}