/* Written by Filip Hlasek 2017 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>

#define FOR(i, a, b)   for (int i = (a); i <= (b); i++)
#define FORD(i, a, b)  for (int i = (a); i >= (b); i--)
#define REP(i, b)      for (int i =  0 ; i <  (b); i++)

using namespace std;

#define MAXN 222222
int N, P[MAXN];
vector<int> f[MAXN];

int getValue(int x, int y) {
  int ans = 0;
  while (x) {
    int l = 0, r = f[x].size();
    if (y == N) l = r;
    while (l < r) {
      int m = (l + r) / 2;
      if (f[x][m] <= y) l = m + 1;
      else r = m;
    }
    ans += l;
    if (x == N) x = 0;
    x -= (x & (-x));
  }
  return ans;
}

int main(int argc, char *argv[]) {
  int Q;
  scanf("%d%d", &N, &Q);
  REP(i, N) scanf("%d", P + i);

  FOR(i, 1, N) {
    int end = i;
    int start = end - (end & (-end)) + 1;
    // printf("i: %d start: %d end: %d\n", i, start, end);
    if (i == N) start = 1;
    FOR(j, start, end) f[i].push_back(P[j - 1]);
    sort(f[i].begin(), f[i].end());
  }

  /*
  FOR(i, 0, N) FOR(j, 0, N) printf("getValue(%d, %d) = %d\n", i, j, getValue(i, j));
  return 0;
  */

  while (Q--) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

    long long i = N;
    long long h = getValue(N, y2);
    long long g = getValue(N, y1 - 1);

    long long f = getValue(x2, N);
    long long e = getValue(x2, y2);
    long long d = getValue(x2, y1 - 1);

    long long c = getValue(x1 - 1, N);
    long long b = getValue(x1 - 1, y2);
    long long a = getValue(x1 - 1, y1 - 1);

    i = i - f - h + e;
    h = h - e - g + d;
    g = g - d;

    f = f - c - e + b;
    e = e - d - b + a;
    d = d - a;

    c = c - b;
    b = b - a;

    long long ans = 0;
    ans += a * (e + f + h + i);
    ans += b * (d + e + f + g + h + i);
    ans += c * (d + e + g + h);
    ans += d * (b + c + e + f + h + i);
    ans += e * (N - 1);
    ans += f * (a + b + d + e + g + h);
    ans += g * (b + c + e + f);
    ans += h * (a + b + c + d + e + f);
    ans += i * (a + b + d + e);
    ans /= 2;
    cout << ans << endl;
  }
  return 0;
}