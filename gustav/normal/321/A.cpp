#include <cstdio>
#include <cstring>

int a, b;
char s[150];
int n;

int main(void)
{
  scanf("%d%d", &a, &b);
  scanf("%s", s);

  n = strlen(s);

  int x = 0, y = 0;

  if (a == 0 && b == 0) {
    puts("Yes");
    return 0;
  }

  for (int i = 0; i < n; ++i) {
    if (s[i] == 'U') ++y;
    if (s[i] == 'D') --y;
    if (s[i] == 'R') ++x;
    if (s[i] == 'L') --x;

    if (x == a && y == b) {
      puts("Yes");
      return 0;
    }
  }

  if (x == 0 && y == 0) {
    puts("No");
    return 0;
  }

  int xx = 0, yy = 0;

  for (int i = 0; i < n; ++i) {
    if (s[i] == 'U') ++yy;
    if (s[i] == 'D') --yy;
    if (s[i] == 'R') ++xx;
    if (s[i] == 'L') --xx;

    if ((long long)(a - xx) * y == (long long)(b - yy) * x &&
	(x && (a - xx) % x == 0 || y && (b - yy) % y == 0) &&
	(long long)(a - xx) * x >= 0 &&
	(long long)(b - yy) * y >= 0) {
      puts("Yes");
      return 0;
    }
  }

  puts("No");

  return 0;
}