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
ll a[NN], BIT[NN], pos[NN], n;
pll A[NN];
void upd(ll z)
{
    for(ll i = z; i <= n; i += (i & -i))
        BIT[i]++;
}
ll que(ll z)
{
    ll ret = 0;
    for(ll i = z; i > 0; i -= (i & -i))
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
        ll ta;
        cin >> ta;
        cin >> n;
        for(ll i = 1; i <= n; i++)
            BIT[i] = 0;
        for(ll i = 1; i <= n; i++)
        {
            ll ta;
            cin >> ta;
            A[i] = mp(ta, -i);
        }
        sort(A + 1, A + 1 + n);
        for(ll i = 1; i <= n; i++)
            pos[-A[i].se] = i;
        ll has = 0;
        for(ll i = 1; i <= n; i++)
        {
            // cout << pos[i] << ")\n";
            has += que(pos[i]);
            upd(pos[i]);
        }
        cout << has << "\n";
    }
}