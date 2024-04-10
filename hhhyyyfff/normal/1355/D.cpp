#include <cstdio>

using namespace std;

int N, S;

int main() {
  scanf("%d%d", &N, &S);
  if (N == 1) {
    if (S == 1) puts("NO"); else {
    puts("YES");
    printf("%d\n%d\n", S, 1);
    }
  } else if (S / 2 - 1 >= N - 1) {
    puts("YES");
    for (int i = 1; i < N - 1; ++i) printf("1 ");
    printf("%d ", S / 2 - 1 - (N - 2));
    printf("%d\n%d\n", (S - 1) / 2 + 2, S / 2);
  } else puts("NO");
  return 0;
}