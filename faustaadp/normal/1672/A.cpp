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
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll sum = 0;
        while(n--)
        {
            ll ta;
            cin >> ta;
            ta--;
            sum += ta;
        }
        if(sum % 2 == 1)
            cout << "errorgorn\n";
        else
            cout << "maomao90\n";
    }
}