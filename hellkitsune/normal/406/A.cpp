#include <string>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

int n, a[1000][1000], x, y, ans = 0, q;
string ANS;

int main() {
  scanf("%d", &n);
  REP(i, n)
    REP(j, n)
      scanf("%d", a[i] + j);
  REP(i, n)
    REP(j, n)
      ans ^= a[i][j] & a[j][i];
  scanf("%d", &q);
  REP(i, q) {
    scanf("%d", &x);
    if (x < 3) {
      scanf("%d", &y);
      ans ^= 1;
    } else {
      if (ans == 0)
        ANS.append("0");
      else
        ANS.append("1");
    }
  }
  cout << ANS << endl;
  return 0;
}