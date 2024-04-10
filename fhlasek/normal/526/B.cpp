/* Written by Filip Hlasek 2015 */
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

#define MAXN 2222222
int N;
int a[MAXN];

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(i, (1 << (N + 1)) - 2) scanf("%d", a + i + 2);
  long long ans = 0;
  FORD(i, (1 << (N + 1)) - 1, 1) {
    a[i] += max(a[2 * i], a[2 * i + 1]);
    ans += abs(a[2 * i] - a[2 * i + 1]);
  }
  cout << ans << endl;
  return 0;
}