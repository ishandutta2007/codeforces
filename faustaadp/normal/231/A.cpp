#include<bits/stdc++.h>
typedef long long ll;
#define pb push_bacl
#define mp make_pair
#define fi first
#define se second
using namespace std;
int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    ll n, has = 0;
    cin >> n;
    for(ll i = 1; i <= n; i++)
    {
        ll ta, tb, tc;
        cin >> ta >> tb >> tc;
        ll z = (ta + tb + tc);
        has += (z >= 2);
    }
    cout << has << "\n";
}