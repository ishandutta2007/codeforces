#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
ll t, n, m;
ll a[NN];
ll x[21][NN];
ll gcd(ll A, ll B)
{
    if(B == 0)
        return A;
    else
        return gcd(B, A % B);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(ll i = 1; i <= n; i++)
            cin >> a[i];
        for(ll i = 1; i < n; i++)
            x[0][i] = abs(a[i + 1] - a[i]);
        for(ll i = 1; i <= 20; i++)
            for(ll j = 1; j < n; j++)
            {
                if((j + (1 << i) - 1) >= n)break;
                x[i][j] = gcd(x[i - 1][j], x[i - 1][j + (1 << (i - 1))]);
                // cout << i << " " << j << " " << x[i][j] << "_\n";
            }
        ll has = 1;
        for(ll i = 1; i < n; i++)
        {
            ll now = 0;
            ll pos = i;
            for(ll j = 20; j >= 0; j--)
            {
                if((pos + (1 << j) - 1) >= n)continue;
                if(gcd(x[j][pos], now) > 1)
                {
                    // cout << i << " " << j << " " << x[j][pos] << "\n";
                    now = gcd(now, x[j][pos]);
                    pos += (1 << j);
                }
            }
            // cout << i << " " << pos << "\n";
            has = max(has, pos - i + 1);
        }
        cout << has << "\n";
    }
}