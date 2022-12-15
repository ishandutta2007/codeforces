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

int n, k;
LL ans = 0;
LL ans2 = 1;
int x[300000];
int a;

int main()
{
  cin >> n >> k;
  FOR (i,0,n) { scanf("%d", &a); if (n-a < k) x[i] = 1, ans += a; else x[i] = 0; }
  cout << ans<<" ";
  bool e = false; int num = 0;
  FOR (i,0,n) {
    if (x[i] == 0) num++;
    else {
      if (!e) e = true;
      else ans2 = (ans2*(num+1))%MOD;
      num = 0;
    }
  }
  cout << ans2;
  return 0;
}