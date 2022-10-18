#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int main() {
  int n;
  scanf("%d\n", &n);
  int ans[1002] = {0}; char str[1002];
  gets(str);
  for (int i = 0; i < n; ++i)
    ans[i] = 1;
  while (true) {
    bool fnd = false;
    for (int i = 0; i + 1 < n; ++i) {
      char val = (ans[i] > ans[i + 1] ? 'L' : (ans[i] == ans[i + 1] ? '=' : 'R'));
      if (val != str[i]) {
        fnd = true; val = str[i];
        if (val == '=') ans[i] = ans[i + 1] = max(ans[i], ans[i + 1]);
        else if (val == 'L') ans[i] = ans[i + 1] + 1;
        else ans[i + 1] = ans[i] + 1; 
      }
    }
    if (!fnd) break;
  }
  for (int i = 0; i < n; ++i)
    printf("%d ", ans[i]);
  printf("\n");
  return 0;
}