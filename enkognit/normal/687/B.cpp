#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>

using namespace std;

ll n, m, k, q, ans, l, r, i, j;
vector <ll> c[100008], v, p;
ll t[1000001], z[1000001], u[1000001];

int main()
{
    //freopen("redistricting.in","r",stdin);
    //freopen("redistricting.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    cin >> n >> m;
    ll o=2, k=m;
    while (o<=k)
    {
        while (k%o==0)
        {
            k/=o;
            t[o]++;
        }
        o++;
    }
    if (k>1) t[k]++;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        ll o=2, k=__gcd(x,m), p=sqrt(k);if (u[k]) continue; else u[k]=1;
        while (o<=p)
        {
            ll l=0;
            while (k%o==0)
            {
                k/=o;
                l++;
            }
            z[o]=max(z[o],l);
            o++;
        }
        if (k>1) z[k]=max(z[k],1ll);
    }
    for (int i = 2; i <=1e6; i++)if (t[i]>z[i]) {cout << "No\n";exit(0);}
    cout << "Yes\n";
    return 0;
}