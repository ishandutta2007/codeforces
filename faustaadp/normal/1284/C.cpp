#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll NN = 3e5 + 5;
ll a[NN];
ll x[NN];
ll F[NN];
ll cek(ll aa)
{
    ll H = 0, k = 0;
    for(ll i = 1; i <= aa; i++)
        a[i] = i;
    do
    {
        k++;
        H = 0;
        for(ll i = 1; i <= aa; i++)
        {
            ll mi = 1e18;
            ll ma = -1e18;
            for(ll j = i; j <= aa; j++)
            {
                mi = min(mi, a[j]);
                ma = max(ma, a[j]);
                if((ma - mi) == (j - i))
                    x[j - i + 1]++;
            }
        }
        // x[H]++;
        // cout << H << "\n";
    }
    while(next_permutation(a + 1, a + 1 + aa));
    for(ll i = 1; i <= 150; i++)
        if(x[i])
           cout << i << " " << x[i] << "\n";
    return H;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // ll n = 4;
    ll n, m, has = 0;
    cin >> n >> m;
    F[0] = 1;
    for(ll i = 1; i <= n; i++)
        F[i] = (F[i - 1] * i) % m;
    for(ll i = 1; i <= n; i++)
    {
        ll hz = ((n - i + 1) * F[i]) % m;
        hz = (hz * F[n - i + 1]) % m;
        has = (has + hz) % m;
    }
    cout << has << "\n";
        // cout << i << " " << cek(i) << "\n";
}