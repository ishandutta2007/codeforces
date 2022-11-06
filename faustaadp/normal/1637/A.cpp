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
ll a[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        for(ll i = 1; i <= n; i++)
            cin >> a[i];
        ll ya = 0;
        for(ll i = 2; i <= n; i++)
            if(a[i] < a[i - 1])
                ya = 1;
        if(ya)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}