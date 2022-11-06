#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair <int, int> Pii;
#define x first
#define y second
#define mp make_pair

LL l, r;

LL gcd(LL x, LL y)
{
    return !y ? x : gcd(y, x % y);
}

int main()
{
    cin >> l >> r;
    if (r - l < 2)
        puts("-1");
    else if (l % 2 == 0)
        cout << l << ' ' << l + 1 << ' ' << l + 2 << endl;
    else if (l % 2 == 1 && r - l >= 3)
        cout << l + 1 << ' ' << l + 2 << ' ' << l + 3 << endl;
    else
    {
        if (gcd(l, l + 2) > 1)
            cout << l << ' ' << l + 1 << ' ' << l + 2 << endl;
        else puts("-1");
    }
    return 0;
}