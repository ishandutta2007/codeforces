#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 4e5 + 5;
const ll mo = 998244353;
const ll inf = (ll)1e18 + 1;
ll tanya(ll X)
{
    cout << "? " << X << endl;
    ll ret;cin >> ret;
    return ret;
}
int main()
{
    // ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin >> n;
    ll L = n + n - 1, R = n * 2000 + n - 1;
    ll z = n;
    while(L <= R)
    {
        ll C = (L + R) / 2;
        if(tanya(C) == 1)
        {
            z = C;
            R = C - 1;
        }
        else
            L = C + 1;
    }
    ll opt = z;
    for(ll i = 2; i <= n; i++)
    {
        ll X = (opt - 1) / i;
        ll jwb = tanya(X);
        if(jwb == i)
            opt = min(opt, X * i);
    }
    cout << "! " << opt << endl;
}