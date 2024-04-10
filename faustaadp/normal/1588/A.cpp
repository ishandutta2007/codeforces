#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 4e5 + 5;
const ll mo = 1e9 + 7;
const ll inf = (ll)1e18 + 1;
ll n, a[NN], b[NN];
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
        for(ll i = 1; i <= n; i++)
            cin >> b[i];
        sort(a + 1, a + 1 + n);
        sort(b + 1, b + 1 + n);
        ll ya = 0;
        for(ll i = 1; i <= n; i++)
            if(a[i] + 1 == b[i] || a[i] == b[i])
                ya++;
        if(ya == n)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}