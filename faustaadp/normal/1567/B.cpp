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
ll x[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(ll i = 1; i <= 400000; i++)
        x[i] = x[i - 1] ^ i;
    ll t;
    cin >> t;
    while(t--)
    {
        ll a, b;
        cin >> a >> b;
        ll z = x[a - 1];
        if(z == b)
            cout << a << "\n";
        else
        if((z ^ b) == a)
            cout << a + 2LL << "\n";
        else
            cout << a + 1LL << "\n";
    }
}