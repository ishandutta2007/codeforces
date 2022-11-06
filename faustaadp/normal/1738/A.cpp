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
ll a[NN], b[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        vector<ll> x;
        vector<ll> y;
        ll n;
        cin >> n;
        for(ll i = 1; i <= n; i++)
            cin >> a[i];
        for(ll i = 1; i <= n; i++)
            cin >> b[i];
        ll has = 0;
        for(ll i = 1; i <= n; i++)
        {
            has += b[i];
            if(a[i] == 0)
                x.pb(b[i]);
            else
                y.pb(b[i]);
        }
        sort(x.begin(), x.end());
        reverse(x.begin(), x.end());
        sort(y.begin(), y.end());
        reverse(y.begin(), y.end());
        ll X = x.size();
        ll Y = y.size();
        if(X < Y)
        {
            for(ll i = 0; i < X; i++)
                has += x[i];
            for(ll i = 0; i < X; i++)
                has += y[i];
        }
        else
        if(X > Y)
        {
            for(ll i = 0; i < Y; i++)
                has += y[i];
            for(ll i = 0; i < Y; i++)
                has += x[i];
        }
        else
        {
            for(ll i = 0; i < X; i++)
                has += x[i];
            for(ll i = 0; i < Y; i++)
                has += y[i];
            has -= min(x[X - 1], y[Y - 1]);
        }
        cout << has << "\n";
    }
}