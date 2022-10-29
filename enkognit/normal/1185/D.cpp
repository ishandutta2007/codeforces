#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define fr front()
#define sqr(a) ((a)*(a))
#define y1 Enkognit

using namespace std;

const ll MOD=1000000007;

ll n, m, W, l, r, ans, T, t, k;
pll a[500001];

int main()
{
    //freopen("divisors.in","r",stdin);
    //freopen("divisors.out","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    cin >> n;
    if (n<4) {cout << 1;exit(0);}
    for (int i = 0; i < n; i++) {cin >> a[i].fi;a[i].se=i+1;}
    sort(a,a+n);
    ll l=1, r=1;
    for (int i = 1; i < n-1; i++)
    {
        if (a[i+1].fi-a[i].fi==a[1].fi-a[0].fi) l++;
    }

    for (int i = 0; i < n-2; i++)
    {
        if (a[i+1].fi-a[i].fi==a[n-1].fi-a[n-2].fi) r++;
    }
    if (l==n-1 && r==n-1) {cout << a[0].se;exit(0);}
    //cout << l << " " << r << "\n";
    if (l==n-2)
    {
        if ((a[n-2].fi-a[0].fi)%(n-2)==0 && (a[n-2].fi-a[0].fi)/(n-2)==a[1].fi-a[0].fi) {cout << a[n-1].se;exit(0);} else
        {
            if (a[1].fi-a[0].fi!=0)
            for (int i = 0; i < n-1; i++)
                if (a[i+1].fi-a[i].fi==0) {cout << a[i].se;exit(0);}
        }
        cout << -1;
        exit(0);
    }
    if (r==n-2)
    {
        if ((a[n-1].fi-a[1].fi)%(n-2)==0 && (a[n-1].fi-a[1].fi)/(n-2)==a[n-1].fi-a[n-2].fi) {cout << a[0].se;exit(0);} else
        {
            if (a[1].fi-a[0].fi!=0)
            for (int i = 0; i < n-1; i++)
                if (a[i+1].fi-a[i].fi==0) {cout << a[i].se;exit(0);}
        }cout << -1;
        exit(0);
    }
    if (l==n-3 && ((a[n-1].fi-a[0].fi)%(n-2)==0 && (a[n-1].fi-a[0].fi)/(n-2)==a[1].fi-a[0].fi))
    {
        for (int i = 1; i < n-1; i++)
            if (a[i+1].fi-a[i].fi!=a[1].fi-a[0].fi && a[i+2].fi-a[i].fi==a[1].fi-a[0].fi) {cout << a[i+1].se;exit(0);}
    }
    if (r==n-3 && ((a[n-1].fi-a[0].fi)%(n-2)==0 && (a[n-1].fi-a[0].fi)/(n-2)==a[n-1].fi-a[n-2].fi))
    {
        for (int i = 0; i < n-2; i++)
            if (a[i+1].fi-a[i].fi!=a[n-1].fi-a[n-2].fi && a[i+2].fi-a[i].fi==a[n-1].fi-a[n-2].fi) {cout << a[i+1].se;exit(0);}
    }
    {cout << -1;exit(0);}
    return 0;
}