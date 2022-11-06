#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
const ll mo = 1e9 + 7;
const ld eps = 1e-9;
ll a[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ld sum = 0;
        for(ll i = 1; i <= n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        sort(a + 1, a + 1 + n);
        ld has = -1e18;
        ld sum2 = 0;
        for(ll i = 1; i < n; i++)
        {
            sum -= a[i];
            sum2 += a[i];
            has = max(has, sum / (ld)(n - i) + sum2 / (ld)i);
        }
        cout << fixed << setprecision(9) << has << "\n";

    }
}