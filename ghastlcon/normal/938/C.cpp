#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define int long long
#define N 100020
#pragma GCC optimize("O3")
using namespace std;

int a[N];

bool OK(int x)
{
    int s;

    s = sqrt(x);

    return s * s == x;
}

int BSFind(int n, int x)
{
    int l, m, r;

    for(l = 0, r = n;l + 1 < r;)
    {
        m = (l + r) / 2;
        //printf("when m = %d, need %d\n", m, (n - m + 1) / m + (bool)((n - m + 1) % m));
        if((n - m + 1) / m + (bool)((n - m + 1) % m) <= x)
            r = m;
        else
            l = m;
    }

    return (n - r + 1) / r + (bool)((n - r + 1) % r) == x ? r : -1;
}

void Solve(void)
{
    int x;
    int i, j;

    cin >> x;
    for(i = 1;i <= 1000000;i ++)
        if(i * i > x && OK(i * i - x))
        {
            //cout<<"I"<<i<<endl;
            j = BSFind(i, (int)sqrt(i * i - x));
            if(j != -1)
            {
                cout << i << ' ' << j << endl;
                return;
            }
        }
    puts("-1");

    return;
}

signed main()
{
    int t;
    int i;

    cin >> t;
    while(t --)
        Solve();
    /*for(i = 1;i <= 1000000;i ++)
        if(i * i > x && OK(i * i - x))
        {
            cout << i << endl;
            break;
        }*/

    return 0;
}