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

ll n, m, k, p, ans, l, r, i, j, k1, k0;
pll a[200001];
vector <ll> c[300005];
bool z[55][55];
map <ll,ll> tx, ty;
vector <pll> v;
string s;

int main()
{
    //freopen("redistricting.in","r",stdin);
    //freopen("redistricting.out","w",stdout);
    cin >> n;
    ll mnx=1e18, mny=1e18, mxx=0, mxy=0;
    for (int i = 1; i <= n*4+1; i++)
    {
        cin >> a[i].fi >> a[i].se;
        z[a[i].fi][a[i].se]=1;
        tx[a[i].fi]++;
        ty[a[i].se]++;
        mnx=min(mnx,a[i].fi);
        mxx=max(mxx,a[i].fi);
        mny=min(mny,a[i].se);
        mxy=max(mxy,a[i].se);
    }
    if (tx[mnx]==1)
    {
        for (int i = 1; i <= 4*n+1; i++)
            if (a[i].fi==mnx)
            {
                cout << a[i].fi << " " << a[i].se << "\n";
                exit(0);
            }
    }
    if (tx[mxx]==1)
    {
        for (int i = 1; i <= 4*n+1; i++)
            if (a[i].fi==mxx)
            {
                cout << a[i].fi << " " << a[i].se << "\n";
                exit(0);
            }
    }
    if (ty[mny]==1)
    {
        for (int i = 1; i <= 4*n+1; i++)
            if (a[i].se==mny)
            {
                cout << a[i].fi << " " << a[i].se << "\n";
                exit(0);
            }
    }
    if (ty[mxy]==1)
    {
        for (int i = 1; i <= 4*n+1; i++)
            if (a[i].se==mxy)
            {
                cout << a[i].fi << " " << a[i].se << "\n";
                exit(0);
            }
    }
    for (int i = 1; i <= 4*n+1; i++)
    {
        if (a[i].fi!=mnx && a[i].se!=mxx && a[i].se!=mny && a[i].se!=mxy)
        {
            cout << a[i].fi << " " << a[i].se << "\n";
            exit(0);
        }
    }
    return 0;
}