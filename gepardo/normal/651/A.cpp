#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    int t = 0;
    while (n > 0 && m > 0)
    {
        if (n < m)
        {
            n++;
            m -= 2;
        }
        else
        {
            m++;
            n -= 2;
        }
        n = min(n, 100);
        m = min(m, 100);
        t++;
    }
    if (n < 0 || m < 0) t--;
    cout << t;
}