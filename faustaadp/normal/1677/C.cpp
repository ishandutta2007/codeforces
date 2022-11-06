#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 1e6 + 5;
const ll mo = 998244353;
const ll inf = (ll)1e18;
ll n, a[NN], b[NN], nx[NN], c[NN];
ll hai(ll A, ll B)
{
    return (A + B) * (B - A + 1LL);
}
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
            cin >> b[i];
        for(ll i = 1; i <= n; i++)
            nx[a[i]] = b[i];
        for(ll i = 1; i <= n; i++)
            c[i] = 0;
        ll kac = 0;
        for(ll i = 1; i <= n; i++)
            if(c[i] == 0)
            {
                ll now = i;
                c[now] = 1;
                ll pr = 1;
                while(nx[now] != i)
                {
                    now = nx[now];
                    c[now] = 1;
                    pr = 1 - pr;
                }
                kac += pr;
                // cout << i << " " << pr << "\n";
            }
        ll bener = n;
        ll jum = (bener - kac);
        jum /= 2LL;
        // cout << n - jum + 1 << " " << n << "   " << hai(n - jum + 1, n) << "\n";
        // cout << 1 << " " << jum << "   " << hai(1, jum) << "\n";
        // cout << hai(n - jum + 1, n) << " " <<  hai(1, jum) << "\n";
        cout << hai(n - jum + 1, n) - hai(1, jum) << "\n";
    }
}