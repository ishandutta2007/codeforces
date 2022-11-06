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
ll ada[5];
ll jen(ll X, ll Y)
{
    X %= 2LL;
    Y %= 2LL;
    return X * 2 + Y;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        map<ll, map<ll, ll>> me;
        ll n;
        cin >> n;
        ll ya = 0;
        for(ll i = 0; i < 4; i++)
            ada[i] = 0;
        ll z = 6;
        for(ll i = 1; i <= 3; i++)
        {
            ll x, y;
            cin >> x >> y;
            me[x][y] = 1;
            z -= jen(x, y);
        }
        ll X, Y;
        cin >> X >> Y;
        if(me[1][1] && me[1][2] && me[2][1])
        {
            if(X == 1 || Y == 1)
                ya = 1;
        }
        else
        if(me[1][n] && me[1][n - 1] && me[2][n])
        {
            if(X == 1 || Y == n)
                ya = 1;
        }
        else
        if(me[n][1] && me[n - 1][1] && me[n][2])
        {
            if(X == n || Y == 1)
                ya = 1;
        }
        else
        if(me[n][n] && me[n - 1][n] && me[n][n - 1])
        {
            if(X == n || Y == n)
                ya = 1;
        }
        else
        {
            // cout << z << " " << jen(X, Y) << "@\n";
            if(z != jen(X, Y))
                ya = 1;
        }

        if(ya)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}