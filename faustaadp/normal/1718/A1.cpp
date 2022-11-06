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
ll t, n, d[5050], a[5050];
ll depe(ll pos)
{
    ll &ret = d[pos];
    if(pos > n)
        return 0;
    if(ret == -1)
    {
        ret = depe(pos + 1) + (a[pos] != 0);
        ll now = 0, tam = 0;
        for(ll i = pos; i < n; i++)
        {
            tam++;
            now ^= a[i];
            if(now == a[i + 1])
                ret = min(ret, depe(i + 2) + tam);
        }
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
            cin >> a[i];
        for(ll i = 1; i <= n; i++)
            d[i] = -1;
        cout << depe(1) << "\n";
    }
}