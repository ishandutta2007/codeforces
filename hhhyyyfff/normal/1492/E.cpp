#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> s;
int n, m, maxd, id, a[250000];

void yes() {
  puts("Yes");
  for (int i = 0; i < m; ++i) printf("%d ", a[i]);
  puts("");
  exit(0);
}

void no() {
  puts("No");
  exit(0);
}

void work() {
  maxd = 0;
  for (int i = 1; i < n; ++i) {
    int cnt = 0;
    for (int j = 0; j < m; ++j)
      if (a[j] != s[i][j])
        ++cnt;
    if (cnt > maxd) {
      maxd = cnt;
      id = i;
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  s = vector<vector<int>>(n, vector<int>(m));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      scanf("%d", &s[i][j]);
  for (int i = 0; i < m; ++i) a[i] = s[0][i];
  work();
  if (maxd <= 2) yes();
  if (maxd >= 5) no();
  if (maxd == 4) {
    int d[4], cur = 0, tmp = id;
    for (int i = 0; i < m; ++i)
      if (a[i] != s[id][i])
        d[cur++] = i;
    for (int i = 0; i < 3; ++i)
      for (int j = i + 1; j < 4; ++j) {
        a[d[i]] = s[tmp][d[i]];
        a[d[j]] = s[tmp][d[j]];
        work();
        if (maxd <= 2) yes();
        a[d[i]] = s[0][d[i]];
        a[d[j]] = s[0][d[j]];
      }
    no();
  } else {
    int d[3], cur = 0, tmp = id;
    for (int i = 0; i < m; ++i)
      if (a[i] != s[id][i])
        d[cur++] = i;
    for (int i = 0; i < 3; ++i) {
      a[d[i]] = s[tmp][d[i]];
      work();
      if (maxd <= 2) yes();
      if (maxd == 3) {
        int d1[3], cur1 = 0, tmp1 = id;
        for (int j = 0; j < m; ++j)
          if (a[j] != s[id][j])
            d1[cur1++] = j;
        for (int j = 0; j < 3; ++j) {
          a[d1[j]] = s[tmp1][d1[j]];
          work();
          if (maxd <= 2) yes();
          a[d1[j]] = s[0][d1[j]];
        }
      }
      a[d[i]] = s[0][d[i]];
    }
    no();
  }
  return 0;
}