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
typedef long long LL;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

int calc(int a, int b)
{
    if (a < b) swap(a, b);
    if (!b)
    {
        return 0;
    }
    int r = a % b, s = (a - r) / b;
    return s+calc(b, r);
}

int calc1(int a, int b, int now)
{
    if (a == 1 && b == 1)
    {
        assert(1 == now);
        return 0;
    }
    if (a < b) swap(a, b);
    int r = a % b, s = (a - r) / b;
    if (b == 1)
        return s-2+calc1(1, 1, now-(s-1));
    return s-1+calc1(b, r, now-s);
}

string ans;

int make(int a, int b, int now)
{
    if (a == 1 && b == 1)
    {
        assert(1 == now);
        ans += "T";
        return 0;
    }
    if (a < b) swap(a, b);
    int r = a % b, s = (a - r) / b;
    if (b == 1)
    {
        int cur = make(1, 1, now-(s-1));
        REP(i, s-1)
            if (cur)
                ans += "T";
            else ans += "B";
            //ans += cur ? "T" : "B";
        return 1-cur;
    }
        int cur = make(b, r, now-s);
        REP(i, s)
            if (cur)
                ans += "T";
            else ans += "B";
    return 1-cur;
}

int main()
{
    int n, r;
    cin >> n >> r;
    if (1 == n && 1 == r)
    {
        cout << "0" << endl << "T" << endl;
        return 0;
    }
    int cur = 0x7f7f7f7f, pos = -1;
    for (int up = r-1; up >= r-up; --up)
        if (__gcd(up, r) == 1)
        {
            int step = calc(r, up);
      //     cout << up << " " << r-up << " " << step << endl;
            if (step == n)
            {
                int error = calc1(r, up, n);
                if (error < cur)
                {
                    cur = error;
                    pos = up;
                }
            }
        }
    if (-1 == pos)
        cout << "IMPOSSIBLE\n";
    else
    {
        cout << cur << endl;
        int rr = make(r, pos, n);

        cout << ans << endl;
     //   if (rr) ans += "T";
     //   else ans += "B";

    //    REP(i, n)
    //        cout << ans[n-1-i];
    //    cout << endl;
    }
	return 0;
}