#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define y1 Enkognit
#define fi first
#define se second

using namespace std;

const ll MOD=1000000007;

ll l, r, n, m, k, a[1000001], b[1000001];

vector <ll> an;

ll binpow(ll h,ll r)
{
    ll l=1;
    while (r)
    {
        if (r&1) l*=h,l%=MOD;
        h*=h;
        h%=MOD;
        r/=2;
    }
    return l;
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    ll x=n;
    vector<ll> v;
    while (x)
    {
        v.pb(x%2);
        x/=2;
    }
    for (int i = v.size()-1; i > -1; i--)
        if (v[i]==1)cout << i+1 << " ";
    return 0;
}