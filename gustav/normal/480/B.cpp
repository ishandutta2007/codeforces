#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define MAXN 100005
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)

int n, l, x, y;
int a[MAXN];

int get(int d) {
  REP(i, n) 
    if (binary_search(a, a + n, d + a[i]))
      return a[i];
  return -1;
}

int getr(int d) {
  for (int i = n - 1; i >= 0; --i)
    if (binary_search(a, a + n, d + a[i]))
      return a[i];
  return -1;
}

int exists(int d) {
  return get(d) >= 0;
}

int main(void) {
  scanf("%d%d%d%d", &n, &l, &x, &y);
  REP(i, n) scanf("%d", a + i);

  if (exists(x) && exists(y)) {
    puts("0");
    exit(0);
  }

  if (exists(x) || exists(y) || x == y) {
    puts("1");
    if (exists(x) || x == y) printf("%d\n", a[0] + y);
    if (exists(y)) printf("%d\n", a[0] + x);
    exit(0);
  }

  if (exists(x + y)) {
    puts("1");
    printf("%d\n", get(x + y) + x);
    exit(0);
  }

  if (exists(abs(x - y))) {
    int p = get(abs(x - y));
    if (p + abs(x - y) + min(x, y) <= l) {
      puts("1");
      printf("%d\n", p + abs(x - y) + min(x, y));
      exit(0);
    }
    else if (p - min(x, y) >= 0) {
      puts("1");
      printf("%d\n", p - min(x, y));
      exit(0);
    }
    p = getr(abs(x - y));
    if (p + abs(x - y) + min(x, y) <= l) {
      puts("1");
      printf("%d\n", p + abs(x - y) + min(x, y));
      exit(0);
    }
    else if (p - min(x, y) >= 0) {
      puts("1");
      printf("%d\n", p - min(x, y));
      exit(0);
    }
  }

  puts("2");
  printf("%d %d\n", a[0] + x, a[0] + y);

  return 0;
}