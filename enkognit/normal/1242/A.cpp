#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pb push_back


using namespace std;

const ll MOD=1e9+7;

int n, m, k, l, r, i, j, a[1000001];
vector <int> c[200001];
bool tt[200001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    ll ans=n, p=sqrt(n);
    for (ll i = 2; i <= p; i++)
        if (n%i==0)
    {
        ans=__gcd(ans,i);
        ans=__gcd(ans,n/i);
    }
    cout << ans;
}