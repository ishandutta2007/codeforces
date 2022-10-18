/* Written by Filip Hlasek 2018 */
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

#define MAXN 333333
int bits[MAXN], before[MAXN], odd_before[MAXN], even_before[MAXN];
int N;

#define X 64

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  long long ans = 0;
  even_before[0] = 1;
  REP(i, N) {
    long long a;
    cin >> a;
    while (a) { bits[i] += a & 1; a >>= 1; }
    before[i + 1] = (before[i] + bits[i]) & 1;
    odd_before[i + 1] = odd_before[i] + before[i + 1];
    even_before[i + 1] = even_before[i] + !before[i + 1];

    int sum = 0, m = 0;
    REP(j, X) {
      if (i - j < 0) break;
      sum += bits[i - j];
      m = max(m, bits[i - j]);
      if (sum % 2 == 0 && 2 * m <= sum) ans++;
    }

    if (i - X >= 0) {
      if (before[i + 1]) ans += odd_before[i - X];
      else               ans += even_before[i - X];
    }
  }

  cout << ans << endl;
  return 0;
}