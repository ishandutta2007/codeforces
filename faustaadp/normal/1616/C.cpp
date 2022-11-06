#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 4e5 + 5;
const ll mo = 1e9 + 7;
const ll inf = (ll)1e18 + 1;
ll t;
ll a[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        for(ll i = 1; i <= n; i++)
            cin >> a[i];
        ll has = 1e18;
        if(n == 1)
            has = 0;
        else
        {
            for(ll i = 1; i <= n; i++)
                for(ll j = i + 1; j <= n; j++)
                {
                    ll hz = 0;
                    pll A = mp((j - i) * a[i] - i * (a[j] - a[i]), j - i);
                    pll B = mp(a[j] - a[i], j - i);
                    // cout << A.fi << "/" << A.se << " dan " << B.fi << "/" << B.se << "\n";
                    // cout << (ld)A.fi / (ld)A.se << "  " << (ld)B.fi / (ld)B.se << "\n";
                    for(ll k = 1; k <= n; k++)
                    {
                        if(k == i || k == j)
                            continue;
                        pll C = mp(A.fi + B.fi * k, j - i);
                        if(C.fi % C.se != 0)
                            hz++;
                        else
                        {
                            ll z = C.fi / C.se;
                            if(z != a[k])
                                hz++;
                        }

                        // cout << k << "  " << (ld)C.fi / (ld)C.se << "\n";
                    }
                    has = min(has, hz);
                    // cout << "\n";
                }
        }
        cout << has << "\n";
    }
}