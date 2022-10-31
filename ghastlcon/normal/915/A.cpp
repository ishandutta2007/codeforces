#include <iostream>
#include <algorithm>
#include <cstdio>
#define int long long
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    int n, k, x;
    int i, o;

    cin >> n >> k;
    for(i = 0, o = k;i < n;i ++)
    {
        cin >> x;
        if(!(k % x))
            o = min(o, k / x);
    }
    cout << o << endl;

    return 0;
}