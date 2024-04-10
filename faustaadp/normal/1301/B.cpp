#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll NN = 1e5 + 5;
ll t, n;
ll a[NN];
ll cek(ll aa)
{
    ll mi = 1e18;
    ll ma = -1e18;
    for(ll i = 1; i <= n; i++)
        if(a[i] != -1)
        {
            if((i < n) && (a[i + 1] == -1))
            {
                mi = min(mi, a[i] + aa);
                ma = max(ma, a[i] - aa);
            }
            if((i > 1) && (a[i - 1] == -1))
            {
                mi = min(mi, a[i] + aa);
                ma = max(ma, a[i] - aa);
            }
            if((i < n) && (a[i + 1] != -1)&& (abs(a[i] - a[i + 1]) > aa))
                return 0;
            if((i > 1) && (a[i -1] != -1)&& (abs(a[i] - a[i - 1]) > aa))
                return 0;
        }
    // cout << aa << " " << ma << " " << mi << "\n";
    if(ma <= mi)
        return 1;
    else
        return 0;
}
ll cak(ll aa)
{
    ll mi = 1e18;
    ll ma = -1e18;
    for(ll i = 1; i <= n; i++)
        if(a[i] != -1)
        {
            if((i < n) && (a[i + 1] == -1))
            {
                mi = min(mi, a[i] + aa);
                ma = max(ma, a[i] - aa);
            }
            if((i > 1) && (a[i - 1] == -1))
            {
                mi = min(mi, a[i] + aa);
                ma = max(ma, a[i] - aa);
            }
            if((i < n) && (a[i + 1] != -1)&& (abs(a[i] - a[i + 1]) > aa))
                return 0;
            if((i > 1) && (a[i -1] != -1)&& (abs(a[i] - a[i - 1]) > aa))
                return 0;
        }
    // cout << aa << " " << ma << " " << mi << "\n";
    if(ma <= mi)
        return max(ma, 0LL);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);  
    cin >> t;
    while(t--)
    {
        cin >> n;
        ll jw = 0;
        for(ll i = 1; i <= n; i++)
            cin >> a[i];
        ll L = 0, R = 1e9;
        ll ki, ka;
        while(L <= R)
        {
            ll C = (L + R) / 2;
            // cout << L << " "
            if(cek(C))
            {
                ki = C;
                R = C - 1;
            }
            else
                L = C + 1;

        }
        cout << ki << " " << cak(ki) << "\n";
    }     
}