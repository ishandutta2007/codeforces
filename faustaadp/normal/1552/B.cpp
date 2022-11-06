#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
ll t;
ll n;
vector<pair<ll, ll> > v[6];
ll x[50505][6];
ll cek(ll pos)
{
    // return 0;
    for(ll i = 1; i <= n; i++)
    {
        if(i == pos)
            continue;
        ll jum = 0;
        for(ll j = 1; j <= 5; j++)
            jum += x[i][j] > x[pos][j];
        if(jum < 3)
            return 0;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        // for(ll i = 1; i <= 5; i++)
            // v[i].clear();
        for(ll i = 1; i <= n; i++)
        {
            for(ll j = 1; j <= 5; j++)
            {
                cin >> x[i][j];
                // v[j].pb(mp(x[i][j], i));
            }
        }
        ll cal = 1;
        for(ll k = 0; k < 5; k++)
        {
            for(ll i = 1; i <= n; i++)
            {
                ll jum = 0;
                for(ll j = 1; j <= 5; j++)
                    jum += x[i][j] < x[cal][j];
                if(jum >= 3)
                    cal = i;
            }
        }
        ll has = -1;
        // cout << cal << "\n";
        if(cek(cal))
            has = cal;
        cout << has << "\n";

    }
}