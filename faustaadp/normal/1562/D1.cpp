#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 3e5 + 5;
const ll mo = 1e9 + 7;
ll n, q;
ll a[NN];
ll p[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        cin >> n >> q;
        for(ll i = 1; i <= n; i++)
        {
            char ct;
            cin >> ct;
            if(ct == '+')
                a[i] = 1;
            else
                a[i] = -1;
        }
        for(ll i = 1; i <= n; i++)
        {
            if(i & 1)
                p[i] = p[i - 1] + a[i];
            else
                p[i] = p[i - 1] - a[i];
        }
        while(q--)
        {
            ll L, R;
            cin >> L >> R;
            ll hz = 0;
            ll sgn = 1;
            hz = p[R] - p[L - 1];
            hz = abs(hz);
            ll jaw = 0;
            if(hz == 0)jaw = 0;
            else if(hz % 2 == 1)jaw = 1;
            else jaw = 2;
            cout << jaw << "\n";
        }
    }
}