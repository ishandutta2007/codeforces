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

long long cost[100007];
long long dpx[100007][2],
          dpy[100007][2];
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    REP(i, n-1) cin >> cost[i];
    dpx[0][0] = dpx[0][1] = 0;
    for (int i = 1; i < n; ++i)
    {
        if (!cost[i-1])
        {
            dpx[i][0] = dpx[i][1] = 0;
            continue;
        }
        if (cost[i-1] & 1)
            dpx[i][0] = cost[i-1] + max(dpx[i-1][0], dpx[i-1][1]);
        else dpx[i][0] = cost[i-1] - 1 + max(dpx[i-1][0], dpx[i-1][1]);

        if (!(cost[i-1] & 1))
            dpx[i][1] = cost[i-1] + dpx[i-1][1];
        else
        {
            if (cost[i-1] == 1)
                dpx[i][1] = 0;
            else dpx[i][1] = cost[i-1] - 1 + dpx[i-1][1];
        }
    }

    dpy[n-1][0] = dpy[n-1][1] = 0;
    for (int i = n-2; i >= 0; --i)
    {
        if (!cost[i])
        {
            dpy[i][0] = dpy[i][1] = 0;
            continue;
        }

        if (cost[i] & 1)
            dpy[i][0] = cost[i] + max(dpy[i+1][0], dpy[i+1][1]);
        else dpy[i][0] = cost[i] - 1 + max(dpy[i+1][0], dpy[i+1][1]);

        if (!(cost[i] & 1))
            dpy[i][1] = cost[i] + dpy[i+1][1];
        else
        {
            if (cost[i] == 1)
                dpy[i][1] = 0;
            else dpy[i][1] = cost[i] - 1 + dpy[i+1][1];
        }
    }

    long long ans = 0;
    REP(i, n) ans = max(ans, max(dpx[i][0]+dpy[i][1], dpx[i][1] + dpy[i][0]));
    cout << ans << endl;
    return 0;
}