#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld; 
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 3e5 + 5;
ll t;
ll n, m;
ll a[NN];
ll f[NN];
ll b[NN];
vector<ll> v[NN];
void dfs(ll pos)
{
    if(b[pos])return ;
    b[pos] = 1;
    for(auto nx : v[pos])
        dfs(nx);
}
ll cek(ll x)
{
    // cout << x << "  \n";
    ll sel = 0;
    ll z = x;
    for(ll i = 1; i <= n; i++)
    {
        b[i] = 0;
        v[i].clear();
    }
    for(ll i = 1; i <= n; i++)
    {
        // if(a[i] != z)
            // sel++;
        v[a[i]].pb(z);
        z++;
        if(z > n)
            z -= n;
    }
    ll CC = 0;
    for(ll i = 1; i <= n; i++)
    {
        if(!b[i])
        {
            dfs(i);
            CC++;
        }
    }
    ll ubh = n - CC;
    // cout << x << "   " << ubh << "\n";
    return (ubh <= m);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(ll i = 1; i <= n; i++)
            f[i - 1] = 0;
        for(ll i = 1; i <= n; i++)
        {
            cin >> a[i];
            f[(a[i] - i + n) % n]++;
        }
        vector<ll> jaw;
        for(ll i = 0; i < n; i++)
        {
            // cout << i << "  " << f[i] << "_\n";
            if(f[i] * 6 >= n && cek(i + 1))
                jaw.pb((n - i) % n);
        }
        sort(jaw.begin(), jaw.end());
        cout << jaw.size();
        for(ll i = 0; i < jaw.size(); i++)
            cout << " " << jaw[i];
        cout << "\n";
    }
}