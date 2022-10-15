#include <iostream>
#include <algorithm>

typedef long long ll;
using namespace std;

ll crl(ll l)
{
    if (l <= 0) return 0;
    else return ((l + 1) / 2) * ((l + 2) / 2);
}

ll calc_part_row_len(ll f, ll l, ll mx)
{
    if (mx < f) return 0;
    if (mx > l) mx = l;
    l -= f, mx -= f, f = 0;
    ll p1 = (l + 1) / 2, p2 = l + 1 - p1;
    if (mx < p1) return ((mx + 1) * (mx + 2) / 2);
    else return (crl(l + 1) - (l - mx) * (l - mx + 1) / 2);
}

ll calc_row_len(ll f, ll l, ll mr, ll xr)
{
    return calc_part_row_len(f, l, xr) - calc_part_row_len(f, l, mr - 1);
}

ll calc1(ll a, ll b, ll c, ll l)
{
    if (l < 0) return 0;
    ll f = a + 1 - b - c;
    return calc_row_len(f, l, 0, l);
}

ll calc2(ll a, ll b, ll c, ll l)
{
    if (l < 0) return 0;
    ll f = a + 1 - b;
    return calc_row_len(f, l, 0, l);
}

ll calc_fixed(ll a, ll b, ll c, ll l)
{
    if (c > a) l -= (c - a), a = c;
    if (l < 0) return 0;
    return calc1(a, b, c, l) - calc2(a, b, c, l);
}

ll ca_1(ll a, ll b, ll c, ll l)
{
    if (b > a) l -= (b - a), a = b;
    if (l < 0) return 0;
    ll res = 0;
    while (l >= 0)
    {
        res += calc_fixed(a, b, c, l);
        c++, l--;
    }
    return res;
}

ll ca_2(ll a, ll b, ll c, ll l)
{
    ll m = max(a, b);
    l -= (2 * m - a - b);
    a = b = m;
    if (c > a) l -= 2 * (c - a), a = b = c;
    if (l < 0) return 0;
    ll res = 0;
    while (l >= 0)
    {
        res += (min(a, c + l) - c + 1);
        a++, b++, l -= 2;
    }
    return res;
}

ll ca_3(ll a, ll b, ll c, ll l)
{
    ll m = max(a, max(b, c));
    l -= (3 * m - a - b - c);
    a = b = c = m;
    if (l < 0) return 0;
    return l / 3 + 1;
}

ll get()
{
    int n; cin >> n; return n;
}

ll solve(ll a, ll b, ll c, ll l)
{
    return ca_1(a, b, c, l) + ca_1(b, c, a, l) + ca_1(c, a, b, l) -
           ca_2(a, b, c, l) - ca_2(b, c, a, l) - ca_2(c, a, b, l) +
           ca_3(a, b, c, l);
}

int main()
{
    ll a = get(), b = get(), c = get(), l = get();
    cout << solve(a, b, c, l);
}