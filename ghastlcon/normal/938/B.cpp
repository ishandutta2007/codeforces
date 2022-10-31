#include <iostream>
#include <algorithm>
#include <cstdio>
#define int long long
#define N 100020
#pragma GCC optimize("O3")
using namespace std;

int a[N];

signed main()
{
    int n;
    int i, o;

    cin >> n;
    for(i = o = 0;i < n;i ++)
    {
        scanf("%I64d", &a[i]);
        o = max(o, min(a[i] - 1, 1000000 - a[i]));
    }
    cout<<o<<endl;

    return 0;
}