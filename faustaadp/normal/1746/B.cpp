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
ll n, a[NN], p[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(ll i = 1; i <= n; i++)
            cin >> a[i];
        for(ll i = 1; i <= n; i++)
            p[i] = p[i - 1] + a[i];
        ll has = 1e18;
        for(ll i = 0; i <= n; i++)
        {
            ll kir = p[i];
            ll kan = (n - i) - (p[n] - p[i]);
            has = min(has, max(kir, kan));
        }
        cout << has << "\n";
    }
}