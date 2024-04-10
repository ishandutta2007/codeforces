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
  char str[102] = {0};
  cin >> n >> str;
  for (int s = 0; s < n; ++s) {
    for (int st = 1; s + 4 * st < n; ++st) {
      if (str[s] == '*' && str[s + st] == '*' && str[s + 2 * st] == '*' && str[s + 3 * st] == '*' && str[s + 4 * st] == '*') {
        puts("yes");
        return 0;
      } 
    }
  }
  puts("no");
  return 0;
}