#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>
#include <cmath>

using namespace std;

char str1[200002];
char str2[200002];

int res[200005];

int main() {
  gets(str1);
  int l1 = strlen(str1);
  reverse(str1, str1 + l1);
  gets(str2);
  int l2 = strlen(str2);
  reverse(str2, str2 + l2);

  for (int i = 0; i < l1; ++i)
    res[i] += str1[i] - '0';
  for (int i = 0; i < l2; ++i) {
    res[i] -= str2[i] - '0';
  }

  int l = max(l1, l2);
  for (int i = l - 1; i >= 2; --i) {
    if (res[i] > 50) {
      puts(">");
      return 0;
    }
    if (res[i] < -50) {
      puts("<");
      return 0;
    }
    if (res[i] != 0) {
      res[i - 1] += res[i];
      res[i - 2] += res[i];
      res[i] = 0;
    }
  }
  int q1 = res[1], q0 = res[0];
  if (q1 == 0 && q0 == 0) {
    puts("=");
  } else {
    double val = q1 * (1 + sqrt(5.0)) / 2 + q0;
    if (val > 0) puts(">");
    else puts("<");
  }
  return 0;
}