#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll NN = 2e5 + 5;
ll n, m, has, x[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    ll a[n + 1][m + 1];
    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < m; j++)
        {
            cin >> a[i][j];
            a[i][j]--;
        }
    for(ll i = 0; i < m; i++)
    {
        for(ll j = 0; j < n; j++)
            x[j] = n + j;
        for(ll j = 0; j < n; j++)
        {
            if(a[j][i] % m == i)
            {
                ll z = a[j][i] / m;
                if(z < n)
                {
                    ll y = (j + n - z) % n;
                    x[y]--;
                }
            }
        }
        ll hz = 1e18;
        for(ll j = 0; j < n; j++)
            hz = min(hz, x[j]);
        has += hz;
    }
    cout << has << "\n";
    
}