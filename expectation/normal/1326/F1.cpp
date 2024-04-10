#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <cmath>
#include <list>
#include <iomanip>
#include <set>
#include <map>
#include <sstream>
#include <fstream>
#include <iterator>

using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b)-1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))

#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair
#define x first
#define y second

typedef unsigned long long LL;
typedef vector<int> VI;
typedef pair<LL, LL> PII;
typedef pair<double, double> PDD;

const double PI = acos(-1.0);
const int MOD = 998244353;
const LL LINF = MOD * (LL)MOD;

int n;
string s[20];
vector<LL> bp[1<<15][15];
int l[1<<15];

int main() {
  cin >> n;
  FOR (i,0,1<<n) {
    int x = i;
    while (x) {
      l[i] += x&1;
      x /= 2;
    }
  }

  FOR (i,0,n) cin >> s[i];

  FOR (maks,0,1<<n)
  FOR (last,0,n)
    if (((1 << last)&maks) != 0)
      FOR (i,0,1<<(l[maks]-1))
          bp[maks][last].PB(0);
  FOR (i,0,n) bp[1 << i][i][0] = 1;
  FOR (m,0,1<<n)
    FOR (last,0,n)
    if (((1 << last)&m) != 0)
      FOR (next,0,n)
      if (((1 << next)&m) == 0)
      {
        if (s[last][next] == '0') FOR (z,0,bp[m][last].size())
            bp[m|(1<<next)][next][z] += bp[m][last][z];
        if (s[last][next] == '1') FOR (z,0,bp[m][last].size())
            bp[m|(1<<next)][next][z+bp[m][last].size()] += bp[m][last][z];
      }
  vector<LL> ans (1<<(n-1));
      FOR (j,0,n)
      FOR (z,0,bp[(1<<n)-1][j].size())
      ans[z] += bp[(1<<n)-1][j][z];
  FOR (i,0,ans.size()) cout << ans[i]<<" ";
  return 0;
}