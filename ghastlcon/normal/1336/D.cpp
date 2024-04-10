#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <utility>
#define N 120
using namespace std;

int a[N], b[N], o[N];

int main(void)
{
    int n;
    int i;

    cin >> n;
    cin >> a[n] >> b[n];
    for(i = n - 1; i > -1; i --)
    {
        cout << "+ " << (i > 2 ? i : i % 2 + 1) << endl;
        cout.flush();
        cin >> a[i] >> b[i];
    }
    for(i = 0; i < n; i ++)
    {
        a[i] -= a[i + 1];
        b[i] -= b[i + 1];
    }

    for(i = 1; i * (i - 1) / 2 != a[0]; i ++)
        ;
    o[1] = i - 1;
    o[3] = b[0] - b[2] - 1;
    o[2] = b[2] / (o[3] + 1);
    o[4] = (b[1] - (o[1] + 1) * (o[3] + 1)) / (o[3] + 1) - 1;
    for(i = 5; i <= n; i ++)
        o[i] = (b[i - 2] - o[i - 3] * o[i - 4] - o[i - 3] * (o[i - 1] + 1)) / (o[i - 1] + 1) - 1;
    o[n] ++;

    cout << "! ";
    for(i = 1; i <= n; i ++)
        cout << o[i] << " \n"[i == n];
    
    return 0;
}