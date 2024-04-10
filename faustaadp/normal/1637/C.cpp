#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 4e5 + 5;
const ll mo = 998244353;
const ll inf = (ll)1e18 + 1;
ll n, a[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(ll i = 1; i <= n; i++)
            cin >> a[i];
        ll gagal = 0;
        if(n == 3)
        {
            if(a[2] % 2 == 1)
                gagal = 1;
        }
        else
        {
            gagal = 1;
            for(ll i = 2; i < n; i++)
                if(a[i] > 1)
                    gagal = 0;
        }
        ll sum = 0;
        for(ll i = 2; i < n; i++)
            sum += (a[i] + 1) / 2;
        if(gagal)
            sum = -1;
        cout << sum << "\n";
    }
}