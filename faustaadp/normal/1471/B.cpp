#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const int NN = 4e5 + 5;
ll t, a[NN], z[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        ll n, x;
        ll has = 0, mi = 1e18, idx;
        cin >> n >> x;
        for(ll i = 1; i <= n; i++)
        {
            z[i] = 0;
            cin >> a[i];
            ll tmp = a[i];
            has += a[i];
            while(tmp % x == 0)
            {
                z[i]++;
                tmp /= x;
            }
            if(mi > z[i])
                idx = i;
            mi = min(mi, z[i]);
        }
        for(ll i = 1; i <= n; i++)
            if(i < idx)
                has += a[i] * min(mi + 1, z[i]);
            else
                has += a[i] * mi;
        cout << has << "\n";
    }
}