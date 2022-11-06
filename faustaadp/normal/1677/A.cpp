#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 4e5 + 5;
const ll mo = 998244353;
const ll inf = (ll)1e18;
ll n, a[NN], BIT[NN], R[5050][5050];
void upd(ll pos)
{
    for(ll i = pos; i <= n; i += (i & (-i)))
        BIT[i]++;
}
ll que(ll pos)
{
    ll ret = 0;
    for(ll i = pos; i > 0; i -= (i & (-i)))
        ret += BIT[i];
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        ll has = 0;
        cin >> n;
        for(ll i = 1; i <= n; i++)
            cin >> a[i];
        for(ll i = 1; i <= n; i++)
            BIT[i] = 0;
        for(ll i = n; i >= 1; i--)
        {
            for(ll j = 1; j < i; j++)
            {
                // cout << j << " " << i << " " << que(a[j]) << "\n";
                R[i][j] = que(a[j]);
            }
            upd(a[i]);
        }
        for(ll i = 1; i <= n; i++)
            BIT[i] = 0;
        for(ll i = 1; i <= n; i++)
        {
            for(ll j = i + 1; j <= n; j++)
            {
                // if(que(a[j] * R[j][i]) > 0)
                // {
                //     cout << i << " " << j << " " << que(a[j]) << "  " << R[j][i] << "\n";
                // }
                has += que(a[j]) * R[j][i];
            }
            upd(a[i]);
        }
        cout << has << "\n";
    }
}