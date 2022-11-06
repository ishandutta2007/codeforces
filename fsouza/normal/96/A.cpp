#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef long long lint;

int main() {
  int c;

  int last = -1, many = 0;

  bool danger = false;

  while ((c = getchar()) != -1) {
    if (c != '1' && c != '0') continue;
    if (c == last) {
      many++;
      if (many >= 7) danger = true;
    } else {
      last = c;
      many = 1;
    }
  }

  if (danger) printf("YES\n");
  else printf("NO\n");

  return 0;
}