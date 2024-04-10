#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define pii pair<int,int>
#define all(v) v.begin(),v.end()
#define sqr(a) ((a)*(a))
#define y1 Enkognit
#define y2 based

using namespace std;
using namespace __gnu_pbds;

mt19937_64 rnd(time(0));

const ll MOD=998244353;

ll n, m, k, sz, sf[200005], a[200005], pr[200005];
ll s[200005][2], p[200005][2];

ll binpow(ll h,ll r,ll md)
{
    ll l=1;
    while (r)
    {
        if (r&1) l*=h, l%=md;
        h*=h;
        h%=md;
        r/=2;
    }
    return l;
}

struct node
{
    node *l, *r;

};

void solve()
{
    cin >> n;
    ll sm=0, ans=0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sm+=a[i];
    }
    if (n==1)
    {
        cout << "1\n";
        return;
    }
    if (n==2)
    {
        cout << 1+(a[1]!=a[2]) << "\n";
        return;
    }
    ll prr=0;
    s[n+1][0]=0;
    s[n+1][1]=0;
    sf[n+1]=0;
    for (int i = n; i > 0; i--)
    {
        sf[i]=sf[i+1]+a[i];
        s[i][0]=s[i+1][1]+a[i];
        s[i][1]=s[i+1][0]-a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        pr[i]=pr[i-1]+a[i];
        p[i][0]=p[i-1][1]+a[i];
        p[i][1]=p[i-1][0]-a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        prr+=a[i];
        if (prr*2>sm) ans++;
    }

    //cout << ans << "\n";

    {
        for (int i = 0; i <= n; i++)
        {
            ll l=0, r=(n-i)/2;
            while (l<r)
            {
                int w=(l+r+1)/2;
                if (-pr[i]+p[i+w*2][1]-p[i][1]+sf[i+w*2+1]>0) l=w; else r=w-1;
            }
            //cout << i << " " << l << " " << -pr[i]+p[i+l*2][1]-p[i][1]+sf[i+l*2+1] << "\n";
            if (-pr[i]+p[i+l*2][1]-p[i][1]+sf[i+l*2+1]>0) ans+=l+(i>0);
        }
        //cout << ans << "\n";
    }

    {
        for (int i = 3; i < n; i++)
        {
            ll l=0, r=(n-i)/2;
            while (l<r)
            {
                int w=(l+r+1)/2;
                if (-pr[i]+a[1]*2+p[i+w*2][1]-p[i][1]+sf[i+w*2+1]>0) l=w; else r=w-1;
            }
            //cout << i << " " << l << " " << -pr[i]+p[i+l*2][1]-p[i][1]+sf[i+l*2+1] << "\n";
            if (-pr[i]+a[1]*2+p[i+l*2][1]-p[i][1]+sf[i+l*2+1]>0) ans+=l+1;
        }
        //cout << ans << "\n";
    }

    {
        for (int i = 0; i <= n-3; i++)
        {
            ll l=0, r=(n-3-i)/2;
            while (l<r)
            {
                int w=(l+r+1)/2;
                if (-pr[i]+p[i+w*2][1]-p[i][1]+sf[i+w*2+1]-a[n]*2>0) l=w; else r=w-1;
            }
            //cout << i << " " << l << " " << -pr[i]+p[i+l*2][1]-p[i][1]+sf[i+l*2+1]-a[n]*2 << "\n";
            if (-pr[i]+p[i+l*2][1]-p[i][1]+sf[i+l*2+1]-a[n]*2>0) ans+=l+(i>0);
        }
        //cout << ans << "\n";
    }

    {
        for (int i = 3; i <= n-3; i++)
        {
            ll l=0, r=(n-3-i)/2;
            while (l<r)
            {
                int w=(l+r+1)/2;
                if (-pr[i]+a[1]*2+p[i+w*2][1]-p[i][1]+sf[i+w*2+1]-a[n]*2>0) l=w; else r=w-1;
            }
            //cout << i << " " << l << " " << -pr[i]+p[i+l*2][1]-p[i][1]+sf[i+l*2+1] << "\n";
            if (-pr[i]+a[1]*2+p[i+l*2][1]-p[i][1]+sf[i+l*2+1]-a[n]*2>0) ans+=l+1;
        }
    }

    cout << ans%MOD << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin >> t;
    while (t--)
    {
        solve();
        //cout << "-\n";
    }
    return 0;
}
/*
6 6 1 12
1 2 1 1 1
2 4 1 1 1
1 3 1 1 2
3 5 1 1 2
5 4 1 1 1
5 6 1 1 1
1 5
3
5
*/