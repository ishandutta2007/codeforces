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
#include <cstring>
#include <iostream>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

long long c(long long x) { return x * x * x; }

#define MAXN 19
long long m[MAXN + 1];

int main(int argc, char *argv[]) {
  long long M;
  cin >> M;
  long long cur = 1;
  long long i = 0;
  while (m[i] <= M && i < 19) {
    while (m[i] + c(cur) >= c(cur + 1)) cur++;
    m[i + 1] = m[i] + c(cur);
    i++;
  }
  --i;
  long long ans1 = i;
  cur = 100000;
  long long ans2 = 0;
  while (cur && i) {
    long long cc = c(cur);
    if (cc > M) { --cur; continue; }
    if (M - cc >= m[i - 1]) { ans2 += cc; M -= cc; --i; }
    else { M = cc - 1; --cur; }
  }
  cout << ans1 << " " << ans2 << endl;
  return 0;
}