#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define pll pair<ll,ll>
#define el endl
#define pu push
#define sqr(a) ((a)*(a))
#define pld pair<long double,long double>
#define ld long double

using namespace std;

ld PI=3.14159265359;

ll n, m, l, r, k, h, i, j, T;
pll a[500001];
ll v[5002];
ll d[2][5001];

int main()
{
    //freopen("sum.in","r",stdin);
    //freopen("sum.out","w",stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll q;
    cin >> q >> n;
    for (int i = 0; i < n; i++) {cin >> a[i].fi >> a[i].se;v[a[i].fi]++;v[a[i].se+1]--;}
    for (int i = 1; i <= q; i++)
    {
        k+=v[i];
        d[0][i]=d[0][i-1]+(k==1);
        d[1][i]=d[1][i-1]+(k==2);
        l+=(k>0);
    }
    ll ans=0;
    sort(a,a+n);
    if (l>q) {cout << -1;exit(0);}
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
        {
            ll p=0;
            if (a[i].se>=a[j].se) p=d[0][a[i].se]-d[0][a[i].fi-1]+d[1][a[j].se]-d[1][a[j].fi-1]; else
            if (a[i].se>=a[j].fi) p=d[0][a[j].se]-d[0][a[i].fi-1]+d[1][a[i].se]-d[1][a[j].fi-1]; else
            p=d[0][a[j].se]-d[0][a[j].fi-1]+d[0][a[i].se]-d[0][a[i].fi-1];
            if (p<0) cout << a[i].fi << " " << a[i].se << " " << a[j].fi << " " << a[j].se << "\n";
            ans=max(ans,l-p);
        }
    cout << ans;
    return 0;
}