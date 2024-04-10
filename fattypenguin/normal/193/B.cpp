#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;

const double eps = 1e-8;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long ll;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

int n, m, r;
int a[33], b[33], k[33], p[33];
long long ans;
int t[33][33];

void go(int day, bool gao)
{
    if ((m-day)%2==0)
    {
        long long tmp = 0;
        REP(i, n) tmp += a[i]*1ll*k[i];
        ans = max(ans, tmp);
        if (day == m) return;
    }
    REP(i, n) t[day][i] = a[i];
    REP(i, n) a[i] = t[day][p[i]]+r;
    go(day+1, false);
    if (gao)
    {
        REP(i, n) a[i] = t[day][i];
        return;
    }
    REP(i, n) a[i] = t[day][i]^b[i];
    go(day+1, true);
    REP(i, n) a[i] = t[day][i];
}

int main()
{
    cin >> n >> m >> r;
    REP(i, n) cin >> a[i];
    REP(i, n) cin >> b[i];
    REP(i, n) cin >> k[i];
    REP(i, n) cin >> p[i];
    REP(i, n) --p[i];

    ans = -0x7f7f7f7f7f7f7f7fll;

    go(0, 0);

    cout << ans << endl;
    return 0;
}