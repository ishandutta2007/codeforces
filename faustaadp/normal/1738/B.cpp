#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
const ll mo = 1e9 + 7;
ll p[NN], a[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        ll n, k;
        cin >> n >> k;
        for(ll i = n - k + 1; i <= n; i++)
            cin >> p[i];
        for(ll i = n - k + 2; i <= n; i++)
            a[i] = p[i] - p[i - 1];
        ll gagal = 0;
        for(ll i = n - k + 3; i <= n; i++)
            if(a[i - 1] > a[i])
            {
                gagal = 1;
                break;
            }
        if(!gagal)
        {
            if(k > 1)
            {
                // cout << p[n - k + 1] << " " << n - k + 1 << " " << sisa << "\n";
                ll sisa = a[n - k + 2] * (n - k + 1);
                // cout << sisa << "\n";
                if(sisa < p[n - k + 1])
                    gagal = 1;
            }
        }
        if(gagal)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
}