#include <cstdio>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

int n, a[1005];
const LL mod = 1e9 + 7;
LL len[1005];

int main() {
  cin >> n;
  REP(i, n) {
    cin >> a[i + 1];
  }
  len[0] = len[1] = 0;
  for (int i = 1; i <= n; ++i) {
    len[i + 1] = (2 * len[i] + 2 - len[a[i]] + mod) % mod;
  }
  cout << len[n + 1] << endl;
  return 0;
}