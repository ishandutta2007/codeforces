/* Written by Filip Hlasek 2014 */
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
  int T;
  scanf("%d", &T);
  while (T--) {
    long long a, b, ans = 0;
    cin >> a >> b;
    bool ones = false;
    FORD(i, 61, 0) {
      if (ones) { ans += (1LL << i); }
      else {
        if ((a & (1LL << i)) == (b & (1LL << i))) {
          ans += (a & (1LL << i));
        }
        else {
          if ((b + 1) == (ans + (1LL << (i + 1)))) {
            ans = b;
            break;
          }
          ones = true;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}