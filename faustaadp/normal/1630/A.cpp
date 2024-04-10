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
void solve(ll n, ll k)
{
    vector<ll> v1;
    vector<ll> v2;
    if(k + 1 < n)
    {
        for(ll i = 0; i < n / 2; i++)
            if(i != 0 && i != k && i != n - k - 1)
                v1.pb(i);
        for(ll i = n - 1; i >= n / 2; i--)
            if(i != n - 1 && i != k && i != n - k - 1)
                v2.pb(i);
        v1.pb(0);v2.pb(n - k - 1);
        v1.pb(n - 1);v2.pb(k);
    }
    else
    if(n > 4)
    {
        for(ll i = 3; i < n / 2; i++)
            v1.pb(i);
        for(ll i = n - 4; i >= n / 2; i--)
            v2.pb(i);
        v1.pb(0);v2.pb(2);
        v1.pb(1);v2.pb(n - 3);
        v1.pb(n - 1);v2.pb(n - 2);
    }
    else
    {
        cout << -1 << "\n";
        return ;
    }
    ll z = 0;
    for(ll i = 0; i < n / 2; i++)
    {
        z += (v1[i] & v2[i]);
        cout << v1[i] << " " << v2[i] << "\n";
    }
    // cerr << z << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        ll n, k;
        cin >> n >> k;
        solve(n, k);
    }

}