#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

ll a, ta, b, tb, x, y, ans;
char z;

int main()
{
    cin >> a >> ta >> b >> tb >> x >> z >> y;
    int st = x * 60 + y;
    for (ll i = 5 * 60; i < 24 * 60; i += b) {
        ll num = tb * st + tb * ta + ta * i;
        ll denum = ta + tb;
        if (num > i * denum && num < (i + tb) * denum)
            ++ans;
    }
    cout << ans;

    return 0;
}