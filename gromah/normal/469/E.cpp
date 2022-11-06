#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

LL a, ans = 1, x = 1000000000;

int main()
{
    cin >> a;
    x *= x;
    LL t = x % a, u = 81;
    while (u)
    {
        if (u & 1) ans = (ans + t) % a;
        t = t * 2 % a, u >>= 1;
    }
    LL delta = ans == 0 ? 0 : a - ans;
    cout << 1 + delta << ' ' << x + delta << endl;
    return 0;
}