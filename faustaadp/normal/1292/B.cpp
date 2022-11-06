#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll NN = 1e5 + 5;
ll X0, Y0, ax, ay, bx, by;
ll xs, ys, t;
ll n;
ll has = 0;
ll x[9999];
ll y[9999];
ll jar(ll XX, ll YY, ll X2, ll Y2)
{
    return abs(X2 - XX) + abs(Y2 - YY);
}
ll cek(ll i, ll j, ll k)
{
    ll H1 = jar(xs, ys, x[k], y[k]) + jar(x[k], y[k], x[i], y[i]) + jar(x[i], y[i], x[j], y[j]);
    ll H2 = jar(xs, ys, x[k], y[k]) + jar(x[k], y[k], x[j], y[j]) + jar(x[i], y[i], x[j], y[j]);
    return min(H1, H2);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> X0 >> Y0 >> ax >> ay >> bx >> by;
    cin >> xs >> ys >> t;
    ll bts = 4e16;
    while(1)
    {
        if(X0 > bts || Y0 > bts)
            break;
        n++;
        x[n] = X0;
        y[n] = Y0;
        // cout << n << " " << x[n] << " " << y[n] << "\n";
        X0 = X0 * ax + bx;
        Y0 = Y0 * ay + by;
    }
    for(ll i = 1; i <= n; i++)
        for(ll j = i; j <= n ; j++)
            for(ll k = i; k <= j; k++)
            {
                if(cek(i, j ,k) <= t)
                    has = max(has, j - i + 1LL);
            }
    cout << has << "\n";
}