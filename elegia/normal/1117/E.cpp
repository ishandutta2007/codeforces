#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

const int N = 10010;

char t[N], test[3][N], dest[3][N], ans[N];

int main() {
  int n;
  scanf("%s", t + 1);
  n = strlen(t + 1);
  for (int i = 1; i <= n; ++i) {
    int x = i - 1;
    for (int j = 0; j < 3; ++j) {
      test[j][i] = (x % 26) + 'a';
      x /= 26;
    }
  }
  for (int j = 0; j < 3; ++j) {
    printf("? %s\n", test[j] + 1);
    fflush(stdout);
    scanf("%s", dest[j] + 1);
  }
  for (int i = 1; i <= n; ++i) {
    int real = 0;
    for (int j = 2; j >= 0; --j) {
      real = real * 26 + (dest[j][i] - 'a');
    }
    ans[real + 1] = t[i];
  }
  printf("! %s\n", ans + 1);
  return 0;
}