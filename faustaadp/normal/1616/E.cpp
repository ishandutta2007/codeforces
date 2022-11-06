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
ll t, n, BIT[NN];
char a[NN], b[NN];
vector<ll> ha[26];
ll que(ll pos)
{
    ll ret = 0;
    for(ll i = pos; i > 0; i -= (i & (-i)))
        ret += BIT[i];
    return ret;
}
void upd(ll pos, ll tam)
{
    for(ll i = pos; i <= n; i += (i & (-i)))
        BIT[i] += tam;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(ll i = 0; i < 26; i++)
            ha[i].clear();
        for(ll i = 1; i <= n; i++)
            BIT[i] = 0;
        for(ll i = 1; i <= n; i++)
            cin >> a[i];
        for(ll i = n; i >= 1; i--)
            ha[a[i] - 'a'].pb(i);
        for(ll i = 1; i <= n; i++)
            cin >> b[i];
        ll has = 1e18;
        ll jum = 0;
        for(ll i = 1; i <= n; i++)
        {
            char hur = b[i];
            for(ll j = 0; j < hur - 'a'; j++)
            {
                if(ha[j].empty())
                    continue;
                ll idx = ha[j].back() + que(ha[j].back());
                has = min(has, jum + idx - i);
            }
            if(ha[hur - 'a'].empty())
                break;
            ll idx = ha[hur - 'a'].back() + que(ha[hur - 'a'].back());
            jum += idx - i;
            upd(1, 1);
            upd(ha[hur - 'a'].back() + 1, -1);
            ha[hur - 'a'].pop_back();
            // cout << i << " " << jum << "\n";
        }
        if(has == 1e18)
            has = -1;
        cout << has << "\n";
    }
}