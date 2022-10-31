#include <iostream>
#include <algorithm>
#include <cstdio>
#define int long long
using namespace std;

signed main(void)
{
    int q, l, r;

    cin >> q;
    while(q --)
    {
        cin >> l >> r;
        if(l % 2)
            cout << (l + 1 + (r % 2 ? r - 1 : r)) * ((r - l + 1) / 2) / 2 - (l + (r % 2 ? r : r - 1)) * ((r - l + 2) / 2) / 2 << endl;
        else
            cout << (l + (r % 2 ? r - 1 : r)) * ((r - l + 2) / 2) / 2 - (l + 1 + (r % 2 ? r : r - 1)) * ((r - l + 1) / 2) / 2 << endl;
    }

    return 0;
}