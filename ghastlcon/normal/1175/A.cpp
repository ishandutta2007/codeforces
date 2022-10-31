#include <iostream>
#include <algorithm>
#include <cstdio>
#pragma GCC optimize("O3")
using namespace std;

int main(void)
{
    int t;
    long long n, k, o;

    cin >> t;
    while(t --)
    {
        cin >> n >> k;
        for(o = 0; n; )
        {
            if(n % k)
            {
                o += n % k;
                n -= n % k;
            }
            else
            {
                o ++;
                n /= k;
            }
        }
        cout << o << endl;
    }

    return 0;
}