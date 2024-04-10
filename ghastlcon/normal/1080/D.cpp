#include <iostream>
#include <algorithm>
#include <cstdio>
#define int long long
using namespace std;

signed main(void)
{
    int t, n, k;
    int i, s, v, c;

    cin >> t;
    while(t --)
    {
        cin >> n >> k;
        if(!k)
        {
            cout << "YES " << n << endl;
            continue;
        }

        c = 1;
        for(i = n - 1, s = v = 0; i > -1; i --)
        {
            s += (1LL << (n - i)) - 1;
            if(s > k)
            {
                cout << "NO" << endl;
                break;
            }

            if(i * 2 >= 64)
                v = 1000000000000000000LL;
            else if(v != 1000000000000000000LL)
                v += c * (((1LL << (i * 2)) - 1) / 3);
            if(s + v >= k)
            {
                cout << "YES " << i << endl;
                break;
            }
            c = c * 2 + 3;
        }

        if(i < 0)
            cout << "NO" << endl;
    }

    return 0;
}
//