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
ll a[NN], x[NN], y[NN];
void solve(ll n, ll k)
{
    for(ll i = 1; i <= n; i++)
        x[i] = a[i];
    sort(x + 1, x + 1 + n);
    ll mi = 1e18;
    ll L, R;
    ll sisa = n - (k - 1);
    ll butuh = (k - 1) + sisa / 2 + 1;
    // cout << butuh << "\n";
    for(ll i = 1; i + butuh - 1 <= n; i++)
    {
        if(mi > x[i + butuh - 1] - x[i])
        {
            mi = x[i + butuh - 1] - x[i];
            L = x[i];
            R = x[i + butuh - 1];
        }
    }
    cout << L << " " << R << "\n";
    ll byk = 0;
    ll jum = 0, lst = 0;
    for(ll i = 1; i <= n; i++)
    {
        if(byk + 1 == k)
            break;
        if(L <= a[i] && a[i] <= R)
            jum++;
        else
            jum--;
        if(jum > 0)
        {
            cout << lst + 1 << " " << i << "\n";
            byk++;
            jum = 0;
            lst = i;
        }
    }
    cout << lst + 1 << " " << n << "\n";

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
        for(ll i = 1; i <= n; i++)
            cin >> a[i];
        solve(n, k);
    }

}