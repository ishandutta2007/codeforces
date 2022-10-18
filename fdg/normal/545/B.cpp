#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

char s1[100005], s2[100005];

int main() {
  gets(s1);
  gets(s2);
  int n = strlen(s1), cnt = 0, need = 0;
  for (int i = 0; i < n; ++i) {
    if (s1[i] != s2[i]) {
      ++cnt;
      if (need) s1[i] = s2[i];
      need ^= 1;
    }
  }
  if (cnt & 1) puts("impossible");
  else puts(s1);
  return 0;
}