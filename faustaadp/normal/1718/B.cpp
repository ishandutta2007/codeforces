#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
const ll mo = 1e9 + 7;
const ll inf = 1e18;
ll f[NN], t, n, a[NN], s[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    f[1] = 1;
    f[2] = 1;
    s[1] = 1;
    s[2] = 2;
    for(ll i = 3; i <= 80; i++)
    {
        f[i] = f[i - 2] + f[i - 1];
        s[i] = s[i - 1] + f[i];
        // cout << i << " " << s[i] << "_\n";
    }
    cin >> t;
    while(t--)
    {
        cin >> n;
        ll sum = 0;
        for(ll i = 1; i <= n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        ll sz = -1;
        for(ll i = 1; i <= 80; i++)
        {
            if(sum == s[i])
            {
                sz = i;
                break;
            }
        }
        if(sz == -1)
        {
            cout << "NO\n";
            continue;
        }
        ll gagal = 0;
        ll lst = -1;
        while(sz)
        {
            ll idx = -1;
            for(ll i = 1; i <= n; i++)
            {
                if(lst == i)
                    continue;
                if(idx == -1 || a[idx] < a[i])
                    idx = i;
            }
            if(idx == -1 || a[idx] < f[sz])
            {
                gagal = 1;
                break;
            }
            a[idx] -= f[sz];
            lst = idx;
            sz--;
        }
        if(gagal)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}