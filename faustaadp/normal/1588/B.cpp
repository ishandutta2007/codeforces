#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 4e5 + 5;
const ll mo = 1e9 + 7;
const ll inf = (ll)1e18 + 1;
ll n;
ll tanya(ll X, ll Y)
{
    cout << "? " << X << " " << Y << endl;
    ll ret;
    cin >> ret;
    return ret;
}
int main()
{
    // ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ll L = 1, R = n;
        ll semua = tanya(1, n);
        ll K = -1;
        while(L <= R)
        {
            ll C = (L + R) / 2;
            if(tanya(1, C) == semua)
            {
                K = C;
                R = C - 1;
            }
            else
                L = C + 1;
        }
        ll rg = tanya(1, K) - tanya(1, K - 1);
        ll J = K - rg;
        ll rg2 = tanya(1, J - 1) - tanya(1, J - 2);
        ll I = J - rg2 - 1;
        cout << "! " << I << " " << J << " " << K << endl;
    }
}