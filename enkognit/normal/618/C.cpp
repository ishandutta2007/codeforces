#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define pll pair<ll,ll>
#define y1 Enkognit
#define fi first
#define se second
#define pld pair<ld,ld>

using namespace std;

const ll MOD=1000000007;

ll l, r, n, m, k;
pair<pld, ll> a[100001];
bool tt[100001];
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
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].fi.fi >> a[i].fi.se;
        a[i].se=i;
    }
    sort(a+1,a+n+1);
    for (int i = 1; i <= n-2; i++)
    {
        if (abs(a[i].fi.fi-a[i+1].fi.fi)<1e-12 && abs(a[i].fi.fi-a[i+2].fi.fi)<1e-12) continue;
        if (abs(a[i].fi.se-a[i+1].fi.se)<1e-12 && abs(a[i].fi.se-a[i+2].fi.se)<1e-12) continue;
        if (abs((a[i].fi.se-a[i+1].fi.se)/(a[i].fi.fi-a[i+1].fi.fi)-(a[i+1].fi.se-a[i+2].fi.se)/(a[i+1].fi.fi-a[i+2].fi.fi))<1e-15)
            continue;
        cout << a[i].se << " " << a[i+1].se << " " << a[i+2].se << "\n";
        exit(0);
    }
    return 0;
}