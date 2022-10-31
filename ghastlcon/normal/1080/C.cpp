#include <iostream>
#include <algorithm>
#include <cstdio>
#define int long long
using namespace std;

signed main(void)
{
    int t, n, m;
    int x1, y1, x2, y2;
    int x3, y3, x4, y4;
    int a, b;

    cin >> t;
    while(t --)
    {
        cin >> n >> m >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        a = b = n * m / 2;
        a += (n * m) % 2;

        a += (x2 - x1 + 1) * (y2 - y1 + 1) / 2;
        b -= (x2 - x1 + 1) * (y2 - y1 + 1) / 2;
        if((x1 + y1) % 2 && (x2 - x1 + 1) * (y2 - y1 + 1) % 2)
        {
            a ++;
            b --;
        }
        // cout << a << ' ' << b << endl;

        a -= (x4 - x3 + 1) * (y4 - y3 + 1) / 2;
        b += (x4 - x3 + 1) * (y4 - y3 + 1) / 2;
        if(!((x3 + y3) % 2) && (x4 - x3 + 1) * (y4 - y3 + 1) % 2)
        {
            a --;
            b ++;
        }
        // cout << a << ' ' << b << endl;

        x1 = max(x1, x3);
        x2 = min(x2, x4);
        y1 = max(y1, y3);
        y2 = min(y2, y4);
        if(x1 <= x2 && y1 <= y2)
        {
            a -= (x2 - x1 + 1) * (y2 - y1 + 1) / 2;
            b += (x2 - x1 + 1) * (y2 - y1 + 1) / 2;
            if((x1 + y1) % 2 && (x2 - x1 + 1) * (y2 - y1 + 1) % 2)
            {
                a --;
                b ++;
            }
        }

        cout << a << ' ' << b << endl;
    }

    return 0;
}