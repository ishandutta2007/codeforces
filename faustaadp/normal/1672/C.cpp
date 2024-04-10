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
const ll inf = (ll)1e18;
ll a[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;cin >> n;
        ll L = -1, R = -1;
        for(ll i = 1; i <= n; i++)
            cin >> a[i];
        for(ll i = 1; i < n; i++)
            if(a[i] == a[i + 1])
                R = i;
        for(ll i = n; i > 1; i--)
            if(a[i] == a[i - 1])
                L = i;
        if(L == -1 || L > R)
            cout << 0 << "\n";
        else
            cout << max(1LL, R - L) << "\n";
    }
}