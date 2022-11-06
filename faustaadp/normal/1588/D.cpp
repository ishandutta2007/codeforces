#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 4e5 + 5;
const ll mo = 1e9 + 7;
const ll inf = (ll)1e18 + 1;
ll t, n;
vector<ll> v[11][55];
ll piv[11];
vector<pll> adj[1055][55];
ll ada[1055][55];
ll d[1055][55];
string HUR = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
ll con(char c)
{
    if(c >= 'a')
        return c - 'a';
    else
        return c - 'A' + 26;
}
ll depe(ll mask, ll hur)
{
    ll &ret = d[mask][hur];
    if(ret == -1)
    {
        ret = 1;
        for(auto z : adj[mask][hur])
            ret = max(ret, depe(z.fi, z.se) + 1);
    }
    return ret;
}
void bt(ll mask, ll hur)
{
    cout << HUR[hur];
    if(depe(mask, hur) > 1)
        for(auto z : adj[mask][hur])
            if(depe(mask, hur) == depe(z.fi, z.se) + 1)
            {
                bt(z.fi, z.se);
                return ;
            }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        memset(ada, 0, sizeof(ada));
        cin >> n;
        for(ll i = 1; i <= n; i++)
        {
            string s;
            cin >> s;
            ll sz = s.length();
            for(ll j = 0; j < sz; j++)
                v[i][con(s[j])].pb(j);
        }
        for(ll mask = 0; mask < (1 << n); mask++)
        {
            for(ll hur = 0; hur < 52; hur++)
            {
                ll gagal = 0;
                for(ll i = 1; i <= n; i++)
                    if(v[i][hur].empty() || ((mask & (1 << (i - 1))) && (v[i][hur].size() == 1)))
                    {
                        gagal = 1;
                        break;
                    }
                    else
                    {
                        piv[i] = v[i][hur][((mask & (1 << (i - 1))) > 0)];
                    }
                if(gagal)
                    continue;
                // cout << "hai\n";
                // for(ll i = 1; i <= n; i++)
                    // cout << i << " " << piv[i] << "_\n";
                ada[mask][hur] = 1;
                for(ll hur2 = 0; hur2 < 52; hur2++)
                {
                    ll gagal2 = 0, mask2 = 0;
                    for(ll i = 1; i <= n; i++)
                    {
                        ll z = -1;
                        for(ll j = 0; j < v[i][hur2].size(); j++)
                            if(v[i][hur2][j] > piv[i])
                            {
                                z = j;
                                break;
                            }
                        if(z == -1)
                        {
                            gagal2 = 1;
                            break;
                        }
                        mask2 += (1 << (i - 1)) * z;
                    }
                    if(gagal2)
                        continue;
                     // cout << mask << " " << hur << "   " << mask2 << " " << hur2 << "_\n";
                    adj[mask][hur].pb(mp(mask2, hur2));
                }
            }
        }
        memset(d, -1, sizeof(d));
        ll has = 0;
        for(ll i = 0; i < (1 << n); i++)    
            for(ll hur = 0; hur < 52; hur++)
                if(ada[i][hur])
                    has = max(has, depe(i, hur));
        cout << has << "\n";
        ll udh = 0;
        for(ll i = 0; i < (1 << n); i++)    
            for(ll hur = 0; hur < 52; hur++)
            {
                if(udh)
                    break;
                if(ada[i][hur] && has == depe(i, hur))
                {
                    bt(i, hur);
                    udh = 1;
                }
            }
        cout << "\n";
        for(ll i = 0; i < (1 << n); i++)
            for(ll j = 0; j < 52; j++)
                adj[i][j].clear();
        for(ll i = 1; i <= n; i++)
            for(ll j = 0; j < 52; j++)
                v[i][j].clear();
    }
}