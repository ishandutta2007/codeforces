#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

ll abs(ll x) {
    return x > 0 ? x : -x;
}

ll a,b,k;

int main()
{
    cin >> k >> a >> b;
    ll ans = 0;
    if (b == 0) ++ans, --b;
    if (b < 0) {
        ll c = b;
        b = -a;
        a = -c;
    }
    ans += b / k;
    if (a <= 0) ++ans;
    if (a < 0) ans += -a / k;
    else if (a > 0) ans -= (a-1) / k;
    cout << ans;

    return 0;
}