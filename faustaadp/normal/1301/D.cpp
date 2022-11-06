#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll NN = 1e5 + 5;
ll t, n, m, k;
vector<string> isi;
vector<string> tmp;
vector<pair<ll, string> > jaw;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    cin >> n >> m >> k;
    ll bts = 4 * n * m - 2 * n - 2 * m;
    if(k > bts)
    {
        cout << "NO\n";
        return 0;
    }
    for(ll i = 1;i < n; i++)
    {
        for(ll j = 1; j < m; j++)
            isi.pb("RDU");
        for(ll j = 1; j < m; j++)
            isi.pb("L");
        isi.pb("D");
    }
    for(ll j = 1; j < m; j++)
        isi.pb("R");
    for(ll j = 1; j < m; j++)
        isi.pb("L");
    for(ll j = 1; j < n; j++)
        isi.pb("U");
    for(ll i = 0; i < isi.size(); i++)
    {
        if(k == 0)
            break;
        if(k < isi[i].length())
        {
            tmp.pb(isi[i].substr(0, k));
            break;
        }
        else
        {
            tmp.pb(isi[i]);
            k -= isi[i].length();
        }
    }
    ll sz = tmp.size(), hz = 0;
    for(ll i = 0; i < sz; i++)
    {
        hz++;
        if(((i + 1) == sz) || (tmp[i] != tmp[i + 1]))
        {
            jaw.pb(mp(hz, tmp[i]));
            hz = 0;
        }
    }
    cout << "YES\n";
    cout << jaw.size() << "\n";
    for(ll i = 0; i < jaw.size(); i++)
        cout << jaw[i].fi << " " << jaw[i].se << "\n";
}