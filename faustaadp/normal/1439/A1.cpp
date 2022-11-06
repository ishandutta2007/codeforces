#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 1e5 + 5;
ll t, n, m, a[110][110];
vector<vector<ll> > jaw;
pair<ll, ll>  z[110];
void hai(ll I, ll J, ll pos)
{
    z[1] = mp(I, J);
    z[2] = mp(I, J + 1);
    z[3] = mp(I + 1, J);
    z[4] = mp(I + 1, J + 1);
    for(ll i = 1; i <= 4; i++)
    {
        if(i == pos)
            continue;
        vector<ll> tmp;
        for(ll j = 1; j <= 4; j++)
        {
            if(j == i)
                continue;
            a[z[j].fi][z[j].se] ^= 1;
            tmp.pb(z[j].fi);
            tmp.pb(z[j].se);
        }
        jaw.pb(tmp);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(ll i = 1; i <= n; i++)
        {
            for(ll j = 1; j <= m; j++)
            {
                char ct;
                cin >> ct;
                a[i][j] = (ct == '1');
            }
        }
        for(ll i = 1; i <= n; i++)
            for(ll j = 1; j <= m; j++)
            {
                if(a[i][j] == 0)
                    continue;
                if(i < n && j < m)
                    hai(i, j, 1);
                else
                if(i < n && j == m)
                    hai(i, j - 1, 2);
                else
                if(i == n && j < m)
                    hai(i - 1, j, 3);
                else
                    hai(i - 1, j - 1, 4);
            }
        cout << jaw.size() << "\n";
        for(ll i = 0; i < jaw.size(); i++)
        {
            for(ll j = 0; j < 6; j++)
                cout << jaw[i][j] << " ";
            cout << "\n";
        }
        // for(ll i = 1; i <= n; i++)
        // {
        //     for(ll j = 1; j <= m; j++)
        //         cout << a[i][j];
        //     cout << "\n";
        // }
        jaw.clear();
    }
}