#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
ll t;
ll n, k, z, a[NN];
ll cek(ll kir)
{
    ll m = k + 1 - kir * 2;
    if(m < 1)
        return 0;
    ll H = 0;
    for(ll i = 1; i <= m; i++)
        H += a[i];
    ll hz = 0;
    for(ll i = 1; i <= m; i++)
    {
        if(i < n)
            hz = max(hz, a[i] + a[i + 1]);
    }
    return H + hz * kir;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    cin >> t;
    while(t--)
    {
        cin >> n >> k >> z;
        for(ll i = 1; i <= n; i++)
            cin >> a[i];
        ll has = 0;
        for(ll i = 0; i <= z; i++)
            has = max(has, cek(i));
        cout << has << "\n";
    }
}