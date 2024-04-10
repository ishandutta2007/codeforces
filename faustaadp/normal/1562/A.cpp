#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 4e6 + 5;
const ll mo = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        ll x, y;
        cin >> x >> y;
        ll z = max(y / 2 + 1, x);
        cout << y % z << "\n";
    }
}