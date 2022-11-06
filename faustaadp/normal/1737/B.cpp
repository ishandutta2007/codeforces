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
ll cnt[999];
ll cek(ll X)
{
    if(X <= 4)
        return X;
    ll ak = sqrt(X);
    ll awal = ak * 3LL - 2LL;
    ll nx = ak + 1;
    // cout << nx * nx - 1 << "@-\n";
    // cout << nx * nx - nx << "@-\n";
    if(nx * nx - 1 <= X)
        awal++;
    if(nx * nx - nx <= X)
        awal++;
    return awal;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // for(ll i = 0; i <= 300; i++)
    // {
    //     ll x = sqrt(i);
    //     if(i % x == 0)
    //         cout << i << "\n";
    // }
    ll t;
    cin >> t;
    while(t--)
    {
        ll L, R;
        cin >> L >> R;
        // cout << R << " " << cek(R) << "\n";
        // cout << L - 1 << " " << cek(L - 1) << "\n";
        ll has = cek(R) - cek(L - 1);
        cout << has << "\n";
    }
}