#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>
#include <ctime>

using namespace std;

int what[128], cnt = 0, n;
char inv[128];

int f[62][62][62][62];
int deg_in[62][62], deg_out[62][62];

char str[200005];

int p[63], IT;

clock_t start;

// void go(int left, int a, int b, int c) {
//   str[n + 1 - left] = inv[c];
//   IT = (IT + 1) & 2047;
//   if ((IT & 2047) == 0 && (clock() - start) >= 1.8 * CLOCKS_PER_SEC) {
//     puts("NO");
//     exit(0);
//   }
//   if (left == 0) {
//     puts("YES");
//     puts(str);
//     exit(0);
//   }
//   int it = 0;
//   for (int dd = 0; dd < 62 && it < 1; ++dd) {
//     int d = p[dd];
//     if (f[b][c][d]) {
//       ++it;
//       --f[b][c][d];
//       go(left - 1, b, c, d);
//       ++f[b][c][d];
//     }
//   }
// }

vector<pair<int, int>> order;

void dfs(int i, int j) {
  for (int ii = 0; ii < 62; ++ii)
    if (f[i][j][j][ii] > 0) {
      f[i][j][j][ii]--;
      dfs(j, ii);
    }
  order.push_back({i, j});
}

int main() {
  start = clock();

  for (char a = '0'; a <= '9'; ++a) {
    inv[cnt] = a;
    what[a] = cnt++;
  }
  for (char a = 'a'; a <= 'z'; ++a) {
    inv[cnt] = a;
    what[a] = cnt++;
  }
  for (char a = 'A'; a <= 'Z'; ++a) {
    inv[cnt] = a;
    what[a] = cnt++;
  }

  scanf("%d\n", &n);
  for (int i = 0; i < n; ++i) {
    char s[4];
    scanf("%s\n", s);
    f[what[s[0]]][what[s[1]]][what[s[1]]][what[s[2]]]++;
    deg_out[what[s[0]]][what[s[1]]]++;
    deg_in[what[s[1]]][what[s[2]]]++;
  }
  bool was = false;
  for (int i = 0; i < 62 && !was; ++i) {
    for (int j = 0; j < 62 && !was; ++j) {
      if (deg_out[i][j] > deg_in[i][j]) {
        dfs(i, j);
        was = true;
      }
    }
  }
  for (int i = 0; i < 62 && !was; ++i) {
    for (int j = 0; j < 62 && !was; ++j) {
      if (deg_out[i][j] > 0) {
        dfs(i, j);
        was = true;
      }
    }
  }
  // for (int i = 0; i < 62; ++i)
  //   for (int j = 0; j < 62; ++j)
  //     if (deg_in[i][j] || deg_out[i][j]) was = false;
  // cout << order.size() << endl;
  // for (auto p : order)
  //   cout << p.first << "  " << p.second << endl;
  int n2 = 0;
  for (int i = 0; i < 62; ++i)
    for (int j = 0; j < 62; ++j)
      if (deg_in[i][j] != deg_out[i][j]) ++n2;
  if (n2 > 2 || order.size() != n + 1) {
    puts("NO");
    return 0;
  }
  printf("YES\n");
  reverse(order.begin(), order.end());
  printf("%c%c", inv[order[0].first], inv[order[0].second]);
  for (int i = 1; i < order.size(); ++i)
    printf("%c", inv[order[i].second]);
  printf("\n");
  // srand(time(NULL));
  // for (int i = 0; i < 62; ++i)
  //   p[i] = i;
  // random_shuffle(p, p + 62);
  // for (int a = 0; a < 62; ++a)
  //   for (int b = 0; b < 62; ++b)
  //     for (int c = 0; c < 62; ++c) {
  //       if (f[a][b][c] == 0) continue;
  //       --f[a][b][c];
  //       str[0] = inv[a];
  //       str[1] = inv[b];
  //       go(n - 1, a, b, c);
  //       ++f[a][b][c];
  //     }
  return 0;
}