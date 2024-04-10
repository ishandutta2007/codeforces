#include <iostream>
#include <algorithm>
#include <cstdio>
#define int long long
#pragma GCC optimize("O3")
using namespace std;

bool Lucky(int h, int m)
{
    return h / 10 == 7 || h % 10 == 7 || m / 10 == 7 || m % 10 == 7;
}

void Prev(int &h, int &m, int x)
{
    m -= x;
    if(m < 0)
    {
        m += 60;
        h --;
        if(h < 0)
            h += 24;
    }

    return;
}

signed main()
{
    int x, h, m;
    int i;

    cin >> x >> h >> m;
    for(i = 0;!Lucky(h, m);Prev(h, m, x), i ++)
        ;
    cout << i << endl;

    return 0;
}