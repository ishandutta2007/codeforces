
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

const int MOD = 1000000007;

long long powMod(long long x, int y)
{
    int ret = 1;
    for (; y; y >>= 1)
    {
        if (y & 1) ret = ret * x % MOD;
        x = x * x % MOD;
    }

    return ret;
}

long long C2(int n)
{
    return n * (long long) (n-1) / 2 % MOD;
}

int gcd(int a, int b)
{
if (!b) return a;
return gcd(b, a%b);
}

struct pt
{
    int a, b, c, d;
    pt(int ta, int tb, int tc, int td):
        a(ta), b(tb), c(tc), d(td)
    {
    }

    pt() {}
    bool operator < (const pt &x) const
    {
        if (a != x.a) return a < x.a;
        if (b != x.b) return b < x.b;
        if (c != x.c) return c < x.c;
        return d < x.d;
    }
};

int main()
{
    int h, w;
    cin >> h >> w;
    ++h, ++w;
    int ways = 0;

    map<pt, int> m;
    for (int i = 1; i <= h; ++i)
        for (int j = 1; j <= w; ++j)
        {
            int xodd = (i - 1 + 1) / 2 + (h - i + 1) / 2,
                xeven = h - xodd;
            int yodd = (j - 1 + 1) / 2 + (w - j + 1) / 2,
                yeven = w - yodd;

            ++m[pt(xodd, xeven, yodd, yeven)];
        }

    TR(it, m)
    {
            int x[2] = {it->first.b, it->first.a},
                y[2] = {it->first.d, it->first.c};

            int all = it->second;

            REP(a, 2) REP(b, 2) REP(c, 2) REP(d, 2)
                if ( (a*d-b*c) % 2 == 0 )
                {
                    int plan1 = x[a]*y[b],
                        plan2 = x[c]*y[d];
                    if (a == b && a == 0) --plan1;
                    if (c == d && c == 0) --plan2;
                    ways = (ways + plan1 * (long long)plan2 % MOD * all) % MOD;

                    if (a == c && b == d)
                    {
                        ways = (ways - plan1 % MOD * (long long)all) % MOD;
                        if (ways < 0) ways += MOD;
                    }
                }
    }

    for (int dx = 0; dx < h; ++dx)
        for (int dy = 0; dy < w; ++dy)
        {
            if (!dx && !dy) continue;
            int num = gcd(dx, dy);
            if (1 == num) continue;

            --num;

            ways = (ways - num * (h - dx) % MOD * (long long)(w - dy) % MOD * 6) % MOD;
            if (dx != 0 && dy != 0)
                ways = (ways - num * (h - dx) % MOD * (long long)(w - dy) % MOD * 6) % MOD;
        }
    cout << (ways + MOD) % MOD << endl;
	return 0;
}