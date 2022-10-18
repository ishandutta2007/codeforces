/* Written by Filip Hlasek 2016 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

int getNum(long long n) {
  for (long long i = 0; i * (i - 1) / 2 <= n; ++i) {
    if (i * (i - 1) / 2 == n) return i;
  }
  return -1;
}

string solve(long long a00, long long a01, long long a10, long long a11) {
  int c0 = getNum(a00);
  int c1 = getNum(a11);
  if (c0 == 0 && (a01 || a10)) c0++;
  if (c1 == 0 && (a01 || a10)) c1++;

  if (c0 < 0 || c1 < 0) return "Impossible";
  if (a00 == 0 && a01 == 0 && a10 == 0 && a11 == 0) return "0";

  int n = getNum(a00 + a01 + a10 + a11);
  if (n != c0 + c1) return "Impossible";

  int b = 0, aa = a10;
  while (aa > 0 && aa >= c0) {
    b++;
    aa -= c0;
  }
  // if (b > c1) return "Impossible";

  string ans = "";
  REP(i, b) ans.push_back('1');
  REP(i, c0) {
    if (c0 - i == aa) ans.push_back('1');
    ans.push_back('0');
  }
  REP(i, c1 - b - (aa > 0)) ans.push_back('1');
  return ans;
}

int main(int argc, char *argv[]) {
  int a00, a01, a10, a11;
  scanf("%d%d%d%d", &a00, &a01, &a10, &a11);
  string ans = solve(a00, a01, a10, a11);
  printf("%s\n", ans.c_str());
  return 0;
}