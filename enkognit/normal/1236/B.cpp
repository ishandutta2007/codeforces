#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>

using namespace std;

ll MOD=1e9+7;

ll n, m, k, l, r, i, j, a[1000001];
vector <ll> v, z;
string s, d;

ll binpow(ll k,ll h)
{
    ll l=1, r=h, x=k;
    while (r)
    {
        if (r%2) l*=x, l%=MOD;
        x*=x;
        x%=MOD;
        r/=2;
    }
    return l;
}

int main()
{
    cin >> n >> m;
    cout << binpow((binpow(2,m)-1),n);
    return 0;
}