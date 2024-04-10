#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    
    cin >> a >> b;
    for (int x = 1; x < a; x++)
    {
        int y = int(sqrt(a * a - x * x));
        if (x * x + y * y != a * a) continue;
        for (int xx = -b + 1; xx < 0; xx++)
        {
            int yy = int(sqrt(b * b - xx * xx));
            if (xx * xx + yy * yy != b * b) continue;
            
            if (y == yy) continue;
            if (x * xx + y * yy == 0)
            {
                cout << "YES" << endl;
                cout << 0 << ' ' << 0 << endl;
                cout << x << ' ' << y << endl;
                cout << xx << ' ' << yy << endl;
                return 0;
            }
        }
    }
    
    cout << "NO" << endl;
}