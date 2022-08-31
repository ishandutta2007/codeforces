#include <bits/stdc++.h>

using namespace std;

int main()
{
  char c;
  int d;
  scanf("%c%d", &c, &d);
  c -= 'a' - 1;

  int ret = 0;
  for(int i = -1; i <= 1; i++) {
    for(int j = -1; j <= 1; j++) {
      if(i == 0 && j == 0) continue;
      int ny = c + i, nx = d + j;
      if(ny <= 0 || nx <= 0 || ny > 8 || nx > 8) continue;
      ++ret;
    }
  }

  printf("%d\n", ret);
}