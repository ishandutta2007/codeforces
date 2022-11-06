#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
ll n, a[90][90], q;
vector<pair<ll, ll> > v[NN];
int main()
{
    // ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; i++)
        for(ll j = 1; j <= n; j++)
            v[i + j].pb(mp(i, j));
    ll du = 1;
    for(ll i = 3; i <= n + n; i++)
    {
        for(ll j = 0; j < v[i].size(); j++)
        {
            if(((v[i][j].fi) % 2) == 1)
                a[v[i][j].fi][v[i][j].se] = 0;
            else
                a[v[i][j].fi][v[i][j].se] = du;
        }
        // cout << du << "\n";
        du *= 2;
    }
    for(ll i = 1; i <= n; i++)
    {
        for(ll j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cin >> q;
    while(q--)
    {
        ll z;
        ll X = 1, Y = 1;
        cin >> z;
        cout << X << " " << Y << endl;
        for(ll i = 0; i < n * 2 - 2; i++)
        {
            if(X == n)
                Y++;
            else
            if(Y == n)
                X++;
            else
            if((z & (1LL << i)) == (a[X + 1][Y] & (1LL << i)))
                X++;
            else
                Y++;
            cout << X << " " << Y << endl;
        }
    }
}