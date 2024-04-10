#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
const ll mo = 1e9 + 7;
const ll inf = 1e18;
ll t, n, p[NN], a[NN], nx[NN], d[NN];
ll depe(ll pos)
{
    ll &ret = d[pos];
    if(pos > n)
        return 0;
    if(ret == -1)
    {
        ret = depe(pos + 1) + (a[pos] > 0);
        if(nx[pos] != -1)
            ret = min(ret, depe(nx[pos] + 1) + nx[pos] - pos);
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(ll i = 1; i <= n; i++)
        {
            cin >> a[i];
            p[i] = p[i - 1] ^ a[i];
            // cout << i << " " << p[i] << "@\n";
        }
        ll has = 0;
        map<ll, ll> me;
        for(ll i = n; i >= 0; i--)
        {
            nx[i] = -1;
            if(me[p[i - 1]] != 0)
                nx[i] = me[p[i - 1]];
            me[p[i]] = i;
        }
        for(ll i = 1; i <= n; i++)
        {
            d[i] = -1;
            // cout << i << " " << nx[i] << "_\n";
            // if(a[i] > 0)
            // {
            //     if(nx[i] == -1)
            //         has++;
            //     else
            //     {
            //         has += nx[i] - i;
            //         i = nx[i];
            //     }
            // }
        }
        cout << depe(1) << "\n";
    }
}