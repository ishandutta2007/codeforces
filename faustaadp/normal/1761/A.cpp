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
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        ll n, a, b;
        cin >> n >> a >> b;
        ll ya = 0;
        if(a == n && b == n)
            ya = 1;
        else
        if(a + b <= n - 2)
            ya = 1;
        if(ya)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}