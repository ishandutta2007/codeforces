#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

LL a, b, c, ans;

int main()
{
    cin >> a >> b >> c;
    if (a < b) swap(a, b);
    if (a < c) swap(a, c);
    if (a >= 2 * (b + c))
        ans = b + c;
    else ans = (a + b + c) / 3;
    cout << ans << endl;
    return 0;
}