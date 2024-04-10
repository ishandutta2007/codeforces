#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll r = 0, c = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > 0)
            {
                r += a[i];
            }
            if (a[i] < 0)
            {
                ll x = -a[i];
                ll t = min(r, x);
                c += x - t;
                r -= t;
            }
        }
        //c += r;
        cout << c << "\n";
    }
}