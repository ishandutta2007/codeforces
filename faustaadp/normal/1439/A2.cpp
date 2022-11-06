#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 1e5 + 5;
ll t, n, m, a[110][110], x[110];
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
void buat(ll I, ll J)
{
    z[1] = mp(I, J);
    z[2] = mp(I, J + 1);
    z[3] = mp(I + 1, J);
    z[4] = mp(I + 1, J + 1);

    x[1] = a[I][J];
    x[2] = a[I][J + 1];
    x[3] = a[I + 1][J];
    x[4] = a[I + 1][J + 1];
    
    ll tot = x[1] + x[2] + x[3] + x[4];
    if(tot == 0)
        return ;
    if(tot == 1)
    {
        for(ll i = 1; i <= 4; i++)
            if(x[i])
            {
                // cout << z[i].fi << " " << z[i].se << " " << i << "\n";
                hai(I, J, i);
            }
    }
    else
    if(tot == 3)
    {
        vector<ll> tmp;
        for(ll j = 1; j <= 4; j++)
        {
            if(x[j] == 0)
                continue;
            a[z[j].fi][z[j].se] ^= 1;
            tmp.pb(z[j].fi);
            tmp.pb(z[j].se);
        }
        jaw.pb(tmp);
    }
    else
    if(tot == 2)
    {
        vector<ll> sat;
        vector<ll> tmp, tmp2;
        for(ll j = 1; j <= 4; j++)
            if(x[j])
                sat.pb(j);
            else
            {
                tmp.pb(z[j].fi);
                tmp.pb(z[j].se);
            }
        for(ll i = 0; i < 2; i++)
        {
            tmp2 = tmp;
            tmp2.pb(z[sat[i]].fi);
            tmp2.pb(z[sat[i]].se);
            jaw.pb(tmp2);
            a[tmp2[0]][tmp2[1]] ^= 1;
            a[tmp2[2]][tmp2[3]] ^= 1;
            a[tmp2[4]][tmp2[5]] ^= 1;
        }
    }
    else
    if(tot == 4)
    {
        // for(ll k = 1; k <= 4; k++)
        {
            for(ll i = 1; i <= 4; i++)
            {
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
        for(ll i = 1; i + 2 <= n; i++)
        {    
            for(ll j = 1; j <= m; j++)
            {
                if(a[i][j] == 0)
                    continue;
                if(j == 1)
                {
                    jaw.pb({i, j, i + 1, j, i + 1, j + 1});
                    a[i][j] ^= 1;
                    a[i + 1][j] ^= 1;
                    a[i + 1][j + 1] ^= 1;
                }
                else
                {
                    jaw.pb({i, j, i + 1, j, i + 1, j - 1});
                    a[i][j] ^= 1;
                    a[i + 1][j] ^= 1;
                    a[i + 1][j - 1] ^= 1;
                }
            }
        }
        for(ll i = n - 1; i <= n - 1; i++)
        {
            for(ll j = 1; j + 2 <= m; j++)
            {
                if(a[i][j] == 1 && a[i + 1][j] == 1)
                {
                    jaw.pb({i, j, i + 1, j, i, j + 1});
                    a[i][j] ^= 1;
                    a[i + 1][j] ^= 1;
                    a[i][j + 1] ^= 1;
                }
                else
                if(a[i][j] == 1 && a[i + 1][j] == 0)
                {
                    jaw.pb({i, j, i, j + 1, i + 1, j + 1});
                    a[i][j] ^= 1;
                    a[i][j + 1] ^= 1;
                    a[i + 1][j + 1] ^= 1;
                }
                else
                if(a[i][j] == 0 && a[i + 1][j] == 1)
                {
                    jaw.pb({i + 1, j, i, j + 1, i + 1, j + 1});
                    a[i + 1][j] ^= 1;
                    a[i][j + 1] ^= 1;
                    a[i + 1][j + 1] ^= 1;
                }
            }
        }
        buat(n - 1, m - 1);
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