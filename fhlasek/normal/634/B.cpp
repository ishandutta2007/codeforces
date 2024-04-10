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

int main(int argc, char *argv[]) {
  long long s, x;
  long long ans = 1;
  cin >> s >> x;
  int rem = 0;
  FORD(d, 50, 0) {
    bool S = (s & (1LL << d));
    bool X = (x & (1LL << d));
    // printf("d: %d S: %d X: %d\n", d, (int)S, (int)X);
    if (!S && !X) rem = 0;
    else if (S && X) {
      if (rem) ans = 0;
      ans *= 2;
      rem = 0;
    }
    else if (S && !X) rem = 1;
    else {
      if (!rem) ans = 0;
      ans *= 2;
      rem = 1;
    }
  }
  if (s == x) ans -= 2;
  if (rem) ans = 0;
  cout << ans << endl;
  return 0;
}