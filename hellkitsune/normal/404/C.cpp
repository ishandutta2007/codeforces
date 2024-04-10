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

using namespace std;

int n, k;
pair<int, int> d[100000];
int ex[100000], ey[100000];

int main()
{
  scanf("%d%d", &n, &k);
  REP(i, n) scanf("%d", &d[i].first);
  REP(i, n) d[i].second = i + 1;
  sort(d, d + n);
  if ((d[0].first != 0) || ((n > 1) && (d[1].first == 0)) || ((k == 1) && (n > 2))) {
    cout << -1 << endl;
    return 0;
  }
  int ps = -1;
  int pf = -1;
  int pc = 0, pk = 0;
  for (int i = 1; i < n; ++i) {
    if (d[i].first > d[i - 1].first + 1) {
      cout << -1 << endl;
      return 0;
    }
    if (d[i].first > d[i - 1].first) {
      pc = ps = pf + 1;
      pf = i - 1;
      ex[i - 1] = d[pc].second;
      ey[i - 1] = d[i].second;
      if (ps == 0)
        pk = 1;
      else
        pk = 2;
      if (pk == k) {
        pk = 0;
        ++pc;
      }
    } else {
      if (pc > pf) {
        cout << -1 << endl;
        return 0;
      }
      ex[i - 1] = d[pc].second;
      ey[i - 1] = d[i].second;
      if (++pk == k) {
        pk = 1;
        ++pc;
      }
    }
  }
  printf("%d\n", n - 1);
  REP(i, n - 1) printf("%d %d\n", ex[i], ey[i]);
  return 0;
}