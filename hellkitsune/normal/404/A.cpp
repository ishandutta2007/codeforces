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

int n;
string s[500];

int main()
{
  cin >> n;
  REP(i, n) cin >> s[i];
  if (s[0][0] == s[0][1]) {
    cout << "NO" << endl;
    return 0;
  }
  REP(i, n)
    if ((s[i][i] != s[0][0]) || (s[i][n - i - 1] != s[0][0])) {
      cout << "NO" << endl;
      return 0;
    }
  REP(i, n)
    REP(j, n)
      if ((i != j) && (i != n - j - 1) && (s[i][j] != s[0][1])) {
        cout << "NO" << endl;
        return 0;
      }
  cout << "YES" << endl;
  return 0;
}