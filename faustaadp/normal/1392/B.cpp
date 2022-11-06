#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
ll t, n, a[NN], k;
void balik()
{
    ll ma = -1e18;
    for(ll i = 1; i <= n; i++)
        ma = max(ma, a[i]);
    for(ll i = 1; i <= n; i++)
        a[i] = ma - a[i];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(ll i = 1; i <= n; i++)
            cin >> a[i];
        balik();
        if(k % 2 == 0)
            balik();
        for(ll i = 1; i <= n; i++)
            cout << a[i] << " ";
        cout << "\n";
    }
}