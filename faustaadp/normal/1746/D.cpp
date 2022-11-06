#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
const ll mo = 1e9 + 7;
ll n, k, x[NN], a[NN], has, d[NN][2];
vector<ll> v[NN];
void dfs(ll pos, ll z)
{
    has += a[pos] * z;
    // cout << pos << " " << v[pos].size() << "_\n";
    ll anak = v[pos].size();
    if(anak == 0)
        return ;
    x[pos] = z % anak;
    // cout << pos << " " << x[pos] << "_\n";
    for(auto nx : v[pos])
        dfs(nx, z / anak);
}
ll depe(ll pos, ll sisa)
{
    if(v[pos].empty())
        return sisa * a[pos];
    ll &ret = d[pos][sisa];
    if(ret == -1)
    {
        ll jum = x[pos] + sisa;
        ret = a[pos] * sisa;
        vector<ll> zz;
        ll anak = v[pos].size();
        for(auto nx : v[pos])
        {
            ret += depe(nx, 0);
            zz.pb(depe(nx, 1) - depe(nx, 0));
        }
        sort(zz.begin(), zz.end());
        reverse(zz.begin(), zz.end());
        // cout << pos << " " << sisa << " " << ret << "  " << jum % anak << "_\n";
        for(ll i = 0; i < jum; i++)
        {
            // cout << zz[i] << "@@@\n";
            ret += zz[i];
        }
        // cout << pos << " " << sisa << " " << ret << "_\n\n";
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        has = 0;
        cin >> n >> k;
        for(ll i = 1; i <= n; i++)
        {
            d[i][0] = -1;
            d[i][1] = -1;
            v[i].clear();
            x[i] = 0;
        }
        for(ll i = 2; i <= n; i++)
        {
            ll ta;
            cin >> ta;
            v[ta].pb(i);
            // cout << ta << "->" << i << "\n";
        }
        for(ll i = 1; i <= n; i++)
            cin >> a[i];
        dfs(1, k);
        // cout << has << "\n";
        has += depe(1, 0);
        cout << has << "\n";
    }
}