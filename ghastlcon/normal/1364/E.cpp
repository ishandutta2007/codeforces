#pragma GCC optimize("O3,inline,unroll-loops")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#define N 2048
using namespace std;

int a[N];

int Query(int x, int y)
{
    int o;

    cout << "? " << x << ' ' << y << endl;
    cout.flush();
    cin >> o;

    return o;
}

int main(void)
{
    int n;
    int i, x, y, z, p, q;

    srand(19260817);
    ios::sync_with_stdio(false);
    
    cin >> n;
    for(i = 1; i <= n; i ++)
        a[i] = i;
    random_shuffle(a + 1, a + n + 1);
    x = a[1];
    y = a[2];
    p = Query(x, y);
    for(i = 3; i <= n; i ++)
    {
        z = a[i];
        q = Query(x, z);
        if(q < p)
        {
            y = z;
            p = q;
        }
        else if(q == p)
        {
            x = z;
            p = Query(x, y);
        }
    }

    while(true)
    {
        do
            z = a[rand() % n + 1];
        while(z == x || z == y);
        p = Query(x, z);
        q = Query(y, z);
        if(p < q)
            break;
        else if(p > q)
        {
            x = y;
            break;
        }
    }

    for(i = 1; i <= n; i ++)
        if(i != x)
            a[i] = Query(i, x);
    cout << '!';
    for(i = 1; i <= n; i ++)
        cout << ' ' << (i == x ? 0 : a[i]);
    cout << endl;

    return 0;
}