#include <bits/stdc++.h>
using namespace std;

int x, h, m, rj = 0;

int main()
{
    cin >> x >> h >> m;
    while (h % 10 != 7 && h / 10 != 7 && m % 10 != 7 && m / 10 != 7)
    {
        rj++;
        m -= x;
        if (m < 0)
        {
            h--;
            m += 60;
        }
        if (h < 0)
        {
            h = 23;
        }
    }
    cout << rj;
    return 0;
}