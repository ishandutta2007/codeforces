#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 4e5 + 5;
const ll mo = 1e9 + 7;
const ll inf = (ll)1e18 + 1;
ll t;
ll a[NN], BIT[NN], p[NN], n, x;
ll que(ll pos)
{
    ll ret = 1e18;
    for(ll i = pos; i > 0; i -= (i & (-i)))
        ret = min(ret, BIT[i]);
    return ret;
}
void upd(ll pos, ll z)
{
    for(ll i = pos; i <= n + 1; i += (i & (-i)))
        BIT[i] = min(BIT[i], z);
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
        cin >> x;
        for(ll i = 1; i <= n; i++)
            a[i] = -(a[i] - x);
        ll jum = a[1], has = 0, ban = 0;
        for(ll i = 1; i <= n + 1; i++)
            BIT[i] = 1e18;
        ll lst = 0;
        for(ll i = 1; i <= n; i++)
        {
            p[i] = p[i - 1] + a[i];
            ll z = que(n - lst + 1);
            // cout << p[i] << " " << z << " " << lst << "\n";
            if(z < p[i])
            {
                // cout << i << " hai\n";
                has++;
                lst = i;
            }
            upd(n - (i - 1) + 1, p[i - 1]);
        }
        // for(ll i = 2; i <= n; i++)
        // {
        //     cout << i << " " << jum + a[i] << "\n";
        //     if(a[i] + a[i - 1] > 0 || jum + a[i] > 0)
        //     {
        //         cout << i << "\n";
        //         a[i] = -1e18;
        //         has++;
        //         jum = 0;
        //     }
        //     else
        //     {
        //         jum = max(0LL, a[i] + jum);
        //         // jum += a[i];
        //     }
        // }
        has = n - has;
        cout << has << "\n";
    }
}