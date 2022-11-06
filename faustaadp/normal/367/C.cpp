#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
ll n, m, has, k, f[1010101], g[1010101];
vector<ll> v;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    cin >> n >> m;
    for(ll i = 1; i <= 100000; i++)
    {
        if(i == 2)
        {
            f[i] = 2;
            g[i] = 1;
        }
        else
        if(i % 2 == 1)
            f[i] = 1 + (i * (i - 1)) / 2;
        else
        {
            g[i] = g[i - 2] + 4;
            f[i] = f[i - 2] + g[i];
            f[i] = 1 + (i * (i - 1)) / 2 + (i - 2) / 2;
        }
        // cout << i << " " << f[i] << "\n";
        if(f[i] <= n)
            k = i;
        else
            break;
    }
    for(ll i = 1;  i <= m; i++)
    {
        ll ta;
        cin >> ta >> ta;
        v.pb(ta);
    }
    // k = 12;
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for(ll i = 0; i < min((ll)v.size(), k); i++)
        has += v[i];
    cout << has << "\n";
}