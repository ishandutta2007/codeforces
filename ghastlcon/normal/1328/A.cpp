#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
 
int main(void)
{
    int t, a, b;

    cin >> t;
    while(t --)
    {
        cin >> a >> b;
        if(!(a % b))
            cout << 0 << endl;
        else
            cout << (a / b + 1) * b - a << endl;
    }

    return 0;
}