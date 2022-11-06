#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 3e5 + 5;
ll n, k, a[NN], has, d[NN];
ll cek(ll bts)
{
    ll mi = 1e18;
    d[n + 1] = 1;
    for(ll i = (n - k + 1); i >= 1; i--)
    {
        ll kanan = i + k;
        if(d[kanan])
            mi = a[kanan - 1];
        d[i] = ((mi - a[i]) <= bts);    
    }
    return d[1];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for(ll i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    ll L = 0, R = 1e9;
    while(L <= R)
    {
        ll C = (L + R) / 2;
        if(cek(C))
        {
            has = C;
            R = C - 1;
        }
        else
            L = C + 1;
    }
    cout << has << "\n";
}