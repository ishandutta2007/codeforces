#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const int NN = 3e5 + 5;
ll n, a[NN], b[NN];
vector<vector<ll> > jaw;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; i++)
        cin >> a[i];
    ll ki = 0;
    ll ka = 0;
    // cout << n << "\n";
    for(ll i = 1; i <= n; i++)
    {
        for(ll j = 1; j <= n; j++)
            b[j] = 0;
        if(i > 1 && a[1] == 1)
        {
            b[ki + 1] = 1;
            for(ll j = n; j > (n - ka); j--)
                b[j] = 1;
        }
        else
        if(i > 1)
        {
            for(ll j = 1; j <= ka; j++)
                b[j + 1] = 1;
            for(ll j = 1; j <= n; j++)
                if(a[j] == 1)
                    b[j] = 1;
        }
        ll tj;
        ll dx = 0;
        ll dy = 0;
        b[1] = 1;
        if(n % 2 == 1)
        {
            if(i % 2 == 1)
            {
                dx++;
                tj = i / 2 + 1;
            }
            else
            {
                dy++;
                tj = n - i / 2 + 1;
            }
        }
        else
        {
            if(i % 2 == 1)
            {
                dy++;
                tj = n - i / 2;
            }
            else
            {
                dx++;
                tj = i / 2;
            }
        }
        for(ll j = 1; j <= n; j++)
            if(a[j] == tj)
                b[j] = 1;
        // cout << i << " " << tj << "\n";
        // for(ll j = 1; j <= n; j++)
            // cout << b[j] << " ";
        // cout << "\n";
        // continue;
        ki += dx;
        ka += dy;
        vector<ll> tm;
        vector<ll> tm2;
        for(ll j = n; j >= 1; j--)
        {
            if(b[j])
            {
                ll h = 0;
                for(ll k = j; k <= n; k++)
                {
                    if(b[k] && k != j)
                        break;
                    h++;
                    tm.pb(a[k]);
                }
                tm2.pb(h);
            }   
        }
        reverse(tm2.begin(), tm2.end());
        if(tm2.size() == 1)
            continue;
        jaw.pb(tm2);
        // cout << tm2.size();
        // for(ll j = 0; j < tm2.size(); j++)
            // cout << " " << tm2[j];
        // cout << "\n";
        // cout << tm.size() << "\n";
        for(ll j = 0; j < n; j++)
        {
            // cout << j + 1 << " " << tm[j] << "\n";
            a[j + 1] = tm[j];
        }
        // for(ll j = 1; j <= n; j++)
            // cout << a[j] << " ";
        // cout << "\n\n";
        // cout << ki << " " << ka << "\n";
    }
    cout << jaw.size() << "\n";
    for(ll i = 0; i < jaw.size(); i++)
    {
        cout << jaw[i].size();
        for(ll j = 0; j < jaw[i].size(); j++)
            cout << " " << jaw[i][j];
        cout << "\n";
        // cout << a[i] << " ";
    }
}