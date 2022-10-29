#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>

using namespace std;

const ll MOD=1e9+7;

ll n, m, k, l, r, a[1000001];
pll b[100001];
string s, d;
vector <ll> v;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        if (__gcd(x,y)==1) cout << "Finite"; else cout << "Infinite";
            cout << "\n";
    }
    return 0;
}