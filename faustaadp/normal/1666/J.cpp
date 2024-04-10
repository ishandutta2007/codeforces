#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 5e5 + 5;
const ll mo = 998244353;
ll n, c[220][220], p[220][220], d[220][220];
ll prt[220];
ll P(ll X1, ll X2, ll Y1, ll Y2)
{
    // cout << X1 << " " << Y1 << " " << X2 << " " << Y2 << " == " << p[X2][Y2] - p[X1 - 1][Y2] - p[X2][Y1 - 1] + p[X1 - 1][Y1 - 1] << "\n";
    return p[X2][Y2] - p[X1 - 1][Y2] - p[X2][Y1 - 1] + p[X1 - 1][Y1 - 1];
}
ll depe(ll L, ll R)
{
    if(L > R)
        return 0;
    ll &ret = d[L][R];
    if(ret == -1)
    {
        ret = 1e18;
        for(ll i = L; i <= R; i++)
        {
            // if(L == 1 && R == 3 && i == 2)
                // cout << P(L, i - 1, i + 1, R) * 2 << " dan " << P(i, i, L, R) << "\n";
            ret = min(ret, P(L, i - 1, 1, L - 1) + P(L, i - 1, i, n) + P(i + 1, R, 1, i) + P(i + 1, R, R + 1, n) + depe(L, i - 1) + depe(i + 1, R));
        }
    }
    return ret;
}
void bt(ll L, ll R, ll par)
{
    if(L > R)
        return ;
    for(ll i = L; i <= R; i++)
    {
        if(depe(L, R) == P(L, i - 1, 1, L - 1) + P(L, i - 1, i, n) + P(i + 1, R, 1, i) + P(i + 1, R, R + 1, n) + depe(L, i - 1) + depe(i + 1, R))
        {
            // cout << i << " " << par << "\n";
            prt[i] = par;
            bt(L, i - 1, i);
            bt(i + 1, R, i);
            return ;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; i++)
        for(ll j = 1; j <= n; j++)
            cin >> c[i][j];
    for(ll i = 1; i <= n; i++)
        for(ll j = 1; j <= n; j++)
            p[i][j] = -p[i - 1][j - 1] + p[i][j - 1] + p[i - 1][j] + c[i][j]; 
    // for(ll i = 1; i <= n; i++)
    // {
    //     for(ll j = 1; j <= n; j++)
    //         cout << p[i][j] << " ";
    //     cout << "\n";
    // }
    memset(d, -1, sizeof(d));
    bt(1, n, 0);
    for(ll i = 1; i <= n; i++)
    {
        cout << prt[i];
        if(i < n)
            cout << " ";
        else
            cout << "\n";
    }
    // cout << depe(1, n) << "\n";
}