#include <iostream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <cassert>
#include <bitset>
#include <string.h>


using namespace std;


int n, m;
int a[1000];
int x[1000], y[1000];
double p[1000][1000];


int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for(int i = 0; i < m; i++) {
    scanf("%d %d", &x[i], &y[i]);
    x[i]--;
    y[i]--;
    if (x[i] > y[i]) {
      swap(x[i], y[i]);
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      p[i][j] = (a[i] < a[j]) ? 1: 0;
    }
  }
  double ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      if(a[i] > a[j]) {
        ans++;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    for(int j = x[i] + 1; j < y[i]; j++) {
      ans += p[x[i]][j] - 0.5;
    }
    for(int j = x[i] + 1; j < y[i]; j++) {
      ans += p[j][y[i]] - 0.5;
    }
    ans += p[x[i]][y[i]] - 0.5;
    for(int j = 0; j < n; j++) {
      if (j == x[i] || j == y[i]) {
        continue;
      }
      double T0 = (p[x[i]][j] + p[y[i]][j]) / 2;
      double T1 = (p[j][x[i]] + p[j][y[i]]) / 2;
      p[x[i]][j] = p[y[i]][j] = T0;
      p[j][x[i]] = p[j][y[i]] = T1;
    }
    p[x[i]][y[i]] = p[y[i]][x[i]] = 0.5;
  }
  printf("%0.8lf\n", ans);
  return 0;
}