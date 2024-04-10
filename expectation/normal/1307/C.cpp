#include <iostream>
#include <algorithm>
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

typedef long long LL;
typedef vector<int> VI;
typedef pair<LL, LL> PII;
typedef pair<double, double> PDD;

const double PI = acos(-1.0);
const int MOD = 1000*1000*1000 + 7;
const LL LINF = MOD * (LL)MOD;

int n, t, d;
LL ans[41][41];
string s;

int main()
{
    // freopen("houses.in", "r", stdin);
    // freopen("houses.out", "w", stdout);

  cin >> s;
  FOR (i,0,s.size())
  {
    FOR (j,0,'z'-'a'+1)
      ans[j][s[i]-'a'] += ans[j][40];
    ans[s[i]-'a'][40]++;
  }
  LL res = 0;
  FOR (i,0,41) FOR (j,0,41) res = max(ans[i][j],res);
  cout << res;
}