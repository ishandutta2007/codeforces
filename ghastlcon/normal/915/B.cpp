#include <iostream>
#include <algorithm>
#include <cstdio>
#define int long long
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    int n, p, l, r;

    cin >> n >> p >> l >> r;
    if(l == 1 && r == n)
    {
        cout << 0 << endl;
        return 0;
    }
    if(p >= l && p <= r)
    {
        if(l == 1)
            cout << r - p + 1 << endl;
        else if(r == n)
            cout << p - l + 1 << endl;
        else
            cout << min(p - l, r - p) + r - l + 2 << endl;
    }
    else if(p < l)
    {
        if(r == n)
            cout << l - p + 1 << endl;
        else
            cout << l - p + 1 + (r - l + 1) << endl;
    }
    else
    {
        if(l == 1)
            cout << p - r + 1 << endl;
        else
            cout << p - r + 1 + (r - l + 1) << endl;
    }

    return 0;
}