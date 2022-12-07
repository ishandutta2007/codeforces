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
ll n, tme, b[NN];
vector<ll> v[NN], isi[NN];
void dfs(ll pos, ll x)
{
    if(b[pos] == tme)
        return ;
    b[pos] = tme;
    isi[x].pb(pos);
    for(auto nx : v[pos])
        dfs(nx, x);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(ll i = 1; i <= n; i++)
            for(ll j = 1; j <= n; j++)
            {
                char ct;
                cin >> ct;
                if(ct == '1')
                    v[j].pb(i);
            }
        for(ll i = 1; i <= n; i++)
        {
            tme++;
            dfs(i, i);
        }
        for(ll i = 1; i <= n; i++)
        {
            cout << isi[i].size();
            for(auto z : isi[i])
                cout << " " << z;
            cout << "\n";
        }
        for(ll i = 1; i <= n; i++)
        {
            isi[i].clear();
            v[i].clear();
        }
    }
}