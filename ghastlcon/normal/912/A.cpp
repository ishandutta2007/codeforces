#include <iostream>
#include <algorithm>
#include <cstdio>
#define int long long
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    int a, b, x, y, z;
    int o;

    cin >> a >> b >> x >> y >> z;
    a -= x * 2;
    a -= y;
    b -= y;
    b -= z * 3;

    o = 0;
    if(a < 0)
        o += -a;
    if(b < 0)
        o += -b;
    cout << o << endl;

    return 0;
}