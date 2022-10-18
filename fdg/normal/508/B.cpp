#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

char str[100002];

int main() {
  gets(str);
  int n = strlen(str), pos = -1;
  for (int i = 0; i < n; ++i) {
    if ((str[i] - '0') % 2 == 0) {
      if (pos == -1 || str[pos] > str[n - 1] || str[pos] == str[n - 1] && str[n - 1] > str[i] || 
          str[pos] == str[n - 1] && str[n - 1] == str[i] && str[i] > str[pos]) {
        pos = i;
      }
    }
  }
  if (pos == -1) printf("-1\n");
  else {
    swap(str[pos], str[n - 1]);
    puts(str);
  }
  return 0;
}