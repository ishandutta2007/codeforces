#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    
    long long x = 0, y = 0, a, d, n;
    double aa, dd;
    cin >> aa >> dd >> n;
    a = int(aa * 10000 + 0.5);
    d = int(dd * 10000 + 0.5);
    d %= (a * 4); 
    long long tmp = d;
    
    for (int i = 1, z = 0; i <= n; i++)
    {
        d = tmp;
        while (d)
        {
            if (!z)
            {
                int run = min(a - x, d);
                x += run;
                d -= run;
                if (x == a) z = 1;
            }
            else if (z == 1)
            {
                int run = min(a - y, d);
                y += run;
                d -= run;
                if (y == a) z = 2;
            }
            else if (z == 2)
            {
                int run = min(x, d);
                x -= run;
                d -= run;
                if (!x) z = 3;
            }
            else
            {
                int run = min(y, d);
                y -= run;
                d -= run;
                if (!y) z = 0;
            }
        }
        
        printf("%.6lf %.6lf\n", x / 10000.0, y / 10000.0);
    }
}