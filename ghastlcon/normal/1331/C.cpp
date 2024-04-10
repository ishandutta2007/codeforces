#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int f[6] = {4, 1, 3, 2, 0, 5};

int main(void)
{
    int n;
    int i, o;

    cin >> n;
    for(i = o = 0; i < 6; i ++)
        if(n & (1 << i))
            o |= 1 << f[i];
    cout << o << endl;

    return 0;
}