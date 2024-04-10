#include <iostream>
#include <algorithm>
#include <cstdio>
#define int long long
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    int k, n;
    int i;

    cin >> k >> n;
    if(n == 1)
        cout << k << endl;
    else
    {
        for(i = 0;k;k -= (i = k & (-k)))
            ;
        cout << i * 2 - 1 << endl;
    }

    return 0;
}