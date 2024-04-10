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
int a[100000];
int ans;

int main()
{
    // freopen("houses.in", "r", stdin);
    // freopen("houses.out", "w", stdout);

  cin >> t;
  FOR (tst,0,t) {
    cin >> n >> d;
    FOR (i,0,n) cin >> a[i];
    ans = a[0];
    FOR (i,1,n)
    {
      int add = min(d/i, a[i]);
      ans += add;
      d -= i*add;
    }
    cout << ans << "\n";
  }
}