#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll f(ll x)
{
    return x * (x + 1) / 2;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        ll x, sol = 0;
        cin >> x;
        while (f((1 << (sol + 1)) - 1) <= x)
        {
            sol++;
            x -= f((1 << sol) - 1);
        }
        cout << sol << "\n";
    }

}