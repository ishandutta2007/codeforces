#include <iostream>

using namespace std;

const long long inf = 1.5 * 1e18;
const int maxln = 1e4;
int n;
long long c, a[maxln], b[maxln];

long long getcurc(long long x)
{
    long long curc = n;
    for (int i = 0; i < n; ++i)
    {
        if ((x != 0) && (inf / x < a[i]))
            curc += inf;
        else
            curc += (x * a[i]) / b[i];
        if (curc > c)
            break;
    }
    return curc;
}

void bs(void)
{
    long long l = 1, r = inf, x, curc, m, ll, rr;
    while (r >= l)
    {
        x = (l + r) / 2;
        curc = getcurc(x);
        if (curc > c)
            r = x - 1;
        if (curc < c)
            l = x + 1;
        if (curc == c)
            break;
    }
    if (r < l)
    {
        cout << 0 << endl;
        return;
    }
    ll = l;
    rr = x;
    while (ll < rr)
    {
        m = (ll + rr) / 2;
        curc = getcurc(m);
        if (curc < c)
            ll = m + 1;
        else
            rr = m;
    }
    l = ll;
    ll = x;
    rr = r;
    while (ll < rr)
    {
        m = (ll + rr + 1) / 2;
        curc = getcurc(m);
        if (curc > c)
            rr = m - 1;
        else
            ll = m;
    }
    r = rr;
    cout << r - l + 1 << endl;
}

int main(void)
{
    cin >> n >> c;
    bool flag = true;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i] >> b[i];
        if (a[i])
            flag = false;
    }
    if (flag)
    {
        if (n == c)
            cout << -1 << endl;
        else
            cout << 0 << endl;
        return 0;
    }
    if (n > c)
    {
        cout << 0 << endl;
        return 0;
    }
    bs();
    return 0;
}