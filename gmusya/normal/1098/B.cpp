#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector <int> vi;
typedef vector <char> vc;
typedef vector <vc> vvc;

pair <int, vi> solve(vvc c) {
  int n = c.size();
  int m = c[0].size();
  int ans = n * m + 1;
  vi resd;
  vc allc = {'A', 'G', 'C', 'T'};
  vi alld = {0, 0, 1, 1};
  do {
    vc a, b;
    for (int i = 0; i < 4; i++) {
      if (alld[i])
        a.push_back(allc[i]);
      else
        b.push_back(allc[i]);
    }
    int curans = 0;
    for (int i = 0; i < n; i++) {
      int ans1 = 0, ans2 = 0;
      if (i % 2 == 0) {
        for (int j = 0; j < m; j++) {
          char x, y;
          if (j % 2 == 0)
            x = a[0], y = a[1];
          else
            x = a[1], y = a[0];
          ans1 += (x != c[i][j]);
          ans2 += (y != c[i][j]);
        }
      } else {
        for (int j = 0; j < m; j++) {
          char x, y;
          if (j % 2 == 0)
            x = b[0], y = b[1];
          else
            x = b[1], y = b[0];
          ans1 += (x != c[i][j]);
          ans2 += (y != c[i][j]);
        }
      }
      curans += min(ans1, ans2);
    }
    if (curans < ans) {
      ans = curans;
      resd = alld;
    }
  } while (next_permutation(alld.begin(), alld.end()));
  return {ans, resd};
}

void write(vvc c, vi res, bool flag) {
  int n = c.size();
  int m = c[0].size();
  int ans = n * m + 1;
  vc allc = {'A', 'G', 'C', 'T'};
  vc a, b;
  for (int i = 0; i < 4; i++) {
    if (res[i])
      a.push_back(allc[i]);
    else
      b.push_back(allc[i]);
  }
  for (int i = 0; i < n; i++) {
    int ans1 = 0, ans2 = 0;
    if (i % 2 == 0) {
      for (int j = 0; j < m; j++) {
        char x, y;
        if (j % 2 == 0)
          x = a[0], y = a[1];
        else
          x = a[1], y = a[0];
        ans1 += (x != c[i][j]);
        ans2 += (y != c[i][j]);
      }
      for (int j = 0; j < m; j++) {
        char x, y;
        if (j % 2 == 0)
          x = a[0], y = a[1];
        else
          x = a[1], y = a[0];
        if (ans1 < ans2)
          c[i][j] = x;
        else
          c[i][j] = y;
      }
    } else {
      for (int j = 0; j < m; j++) {
        char x, y;
        if (j % 2 == 0)
          x = b[0], y = b[1];
        else
          x = b[1], y = b[0];
        ans1 += (x != c[i][j]);
        ans2 += (y != c[i][j]);
      }
      for (int j = 0; j < m; j++) {
        char x, y;
        if (j % 2 == 0)
          x = b[0], y = b[1];
        else
          x = b[1], y = b[0];
        if (ans1 < ans2)
          c[i][j] = x;
        else
          c[i][j] = y;
      }
    }
  }
  if (flag) {
    for (int j = 0; j < m; j++) {
      for (int i = 0; i < n; i++)
        cout << c[i][j];
      cout << '\n';
    }
  } else {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        cout << c[i][j];
      cout << '\n';
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vvc c(n, vc(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> c[i][j];
  vvc d(m, vc(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      d[j][i] = c[i][j];
  pair <int, vi> solve1 = solve(c);
  pair <int, vi> solve2 = solve(d);
  if (solve1.first < solve2.first)
    write(c, solve1.second, 0);
  else
    write(d, solve2.second, 1);
  return 0;
}