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
ll n, k, a[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(ll i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + 1 + n);
        if(a[n] == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}