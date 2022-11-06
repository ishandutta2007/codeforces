#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll NN = 4e3 + 5;
ll t, n, a[NN], x[NN], has, m, k;
ll cek(ll aa)
{
    for(ll i = 1; i <= n; i++)
        if(a[i] >= aa)
            x[i] = 1;
        else
            x[i] = 0;
    ll butuh = -min(m - 1, k);
    ll jrk = n - m;
    // cout << jrk << "\n";
    ll hz = 0;
    for(ll i = 1; (i + jrk) <= n; i++)
        butuh++;
    for(ll i = 1; (i + jrk) <= n; i++)
    {
        // cout << aa << " " <<x[i] << " " << x[i + jrk] << "_\n";
        if((x[i] == 1) || (x[i + jrk] == 1))
            hz++;
        else
            hz = 0;
        if(hz >= butuh)
            return 1;
        // cout << aa << " " << i << " " << hz << "\n";
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> k;
        for(ll i = 1; i <= n; i++)
            cin >> a[i];
        ll L = 1;
        ll R = 1e9;
        while(L <= R)
        {
            ll C = (L + R) / 2;
            if(cek(C))
            {
                has = C;
                L = C + 1;
            }
            else
                R = C - 1;
        }
        cout << has << "\n";
    }
}