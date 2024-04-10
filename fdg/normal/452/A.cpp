#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

char w[10][22] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

int main() {
  int n;
  char str[22] = {0};
  scanf("%d\n%s\n", &n, str);
  for (int i = 0; i < 8; ++i) {
    if (strlen(w[i]) == n) {
      bool ok = true;
      for (int j = 0; j < n; ++j) {
        if (str[j] != '.' && w[i][j] != str[j]) {
          ok = false;
        }
      }
      if (ok) {
        puts(w[i]);
        return 0;
      }
    }
  }
  return 0;
}