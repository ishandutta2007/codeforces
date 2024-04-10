#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--)
    {
        ll n, x, t;
        cin >> n >> x >> t;
        ll cnt = t/x, ans = 0;
        if (n - 1 <= cnt) // nikdy neuvidim vsetkych
        {
            ans = (n - 1) * n / 2;
            //cout << "small n" << endl;
        }
        else
        {
            ans = cnt * n - cnt * (cnt + 1) / 2;
        } 
        cout << ans << "\n";
    }
    return 0;
}