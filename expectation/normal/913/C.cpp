#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define SZ(a) a.size()
#define LL long long

LL n, l;
LL a[50];
LL s2[50];

int main()
{
    cin >> n >> l;
    s2[0] = 1;
    FOR (i,1,n) s2[i] = s2[i-1]*2;
    FOR (i,0,n) cin >> a[i];
    FOR (i,1,n)
    if (a[i] > 2*a[i-1])
        a[i] = 2*a[i-1];
    LL price = 1e18;
    LL cur = 0;
    for (LL i = n-1; i>=0; i--)
    {
        LL tm = l/s2[i];
        l -= s2[i]*tm;
        cur += a[i]*tm;
        if (!l)
        {
            price = min(price,cur);
        }
        else
        {
            price = min(price,cur + a[i]);
        }
    }
    cout << price;
}