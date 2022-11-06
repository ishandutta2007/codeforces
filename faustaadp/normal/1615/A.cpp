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
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        ll n, sum = 0;
        cin >> n;
        for(ll i = 1; i <= n; i++)
        {
            ll ta;
            cin >> ta;
            sum += ta;
        }
        ll has;
        if(sum % n == 0)
            has = 0;
        else
            has = 1;
        cout << has << "\n";
    }
}