#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>

using namespace std;

const int maxN = 999999;
int n, m;
int ss[maxN], ff[maxN], dd[maxN], x[maxN], last[maxN], pred[maxN], good[maxN], deg[maxN], used[maxN];


int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d %d", &ss[i], &ff[i], &dd[i]);
    ss[i + m] = ff[i];
    ff[i + m] = ss[i];
    dd[i + m] = dd[i];
  }
  for (int i = 1; i <= n; i++) {
    last[i] = 0;
  }
  for (int i = 1; i <= m + m; i++) {
    good[i] = 0;
    pred[i] = last[ss[i]];
    last[ss[i]] = i;
  }
  for (int i = 1; i <= n; i++)  {
    deg[i] = 0;
  }
  for (int i = 1; i <= m + m; i++) {
    deg[ss[i]] += dd[i];
  }
  for (int i = 1; i <= n; i++) {
    deg[i] /= 2;
  }
  for (int i = 1; i <= n; i++) {
    used[i] = 0;
  }
  deg[1] = deg[n] = 0;
  int l = 1;
  int e = 1;
  x[1] = 1;
  while (l <= e) {
    int j = last[x[l]];
    while (j > 0) {
      if (ff[j] == n) {
        good[j] = 1;
      }
      if (used[ff[j]] < deg[ff[j]]) {
        good[j] = 1;
        used[ff[j]] += dd[j];
        if (used[ff[j]] == deg[ff[j]]) {
          e++;
          x[e] = ff[j];
        }
      }
      j = pred[j];
    }
    l++;
  }
  for (int i = 1; i <= m; i++) {
    printf("%d\n", 1 - good[i]);
  }
  return 0;
}