#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <numeric>

using namespace std;

typedef long long lint;

int main() {
  char s[2][128];
  for (int j = 0; j < 2; j++) {
    scanf("%s", s[j]);
    for (int i = 0; s[j][i]; i++)
      s[j][i] = tolower(s[j][i]);
  }

  int r = strcmp(s[0], s[1]);
  int ret;

  if (r < 0) ret = -1;
  else if (r > 0) ret = 1;
  else ret = 0;

  printf("%d\n", ret);

  return 0;
}