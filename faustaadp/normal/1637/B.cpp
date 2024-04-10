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
ll n, a[NN], d[110][110];
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
        memset(d, -1, sizeof(d));
        ll sum = 0;
        for(ll i = 1; i <= n; i++)
        {
            ll tam = 0;
            for(ll j = i; j <= n; j++)
            {
                tam++;
                if(a[j] == 0)
                    tam++;
                sum += tam;
            }
        }
        cout << sum << "\n";
    }
}