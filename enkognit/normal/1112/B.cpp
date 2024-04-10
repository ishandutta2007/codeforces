#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>

using namespace std;

ll n, m, k, l, r, a[1000001];
string s, d;
bool t[1000001], tt[1000001];
pll b[1000001];

template<typename T>
T sqr(T x)
{
    return x*x;
}

ll pr(ll x,ll y)
{
    ld p=(ld)(100*x)/(ld)y;
    if ((ll)((p-(ll)p)*10)>=5) p++;
    return (ll)p;
}

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    k=min(k,n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll r=k-1;
    ll u=0, z=0;
    for (int i = 0; i < k; i++)
    {
        b[i]=mp(1,i);
    }
    //cout << 1;
    ll ans=0;
    while (z<n)
    {
        ll u=round((ld)100*z/(ld)n);
        for (int i = 0; i < k; i++)
        {
            if (b[i].fi<=a[b[i].se] && !tt[i])if (b[i].fi==u) {t[b[i].se]=1;ans++;}
        }
        for (int i = 0; i < k; i++)
            if (!tt[i])
        {
            if (b[i].fi<a[b[i].se])
            {
                b[i].fi++;
            } else
            if (r<n-1)
            {
                z++;
                r++;
                b[i]=mp(1,r);
            }else {if (!tt[i]) z++;tt[i]=1;}
            //cout << b[i].fi << " " << b[i].se << "\n";
        }
        //cout << ans << "\n";
        //cout << round(100*z/n) << "\n";
        //cout << r << "-" << z <<"\n";
        //system("pause");
    }
    ans=0;
    for (int i = 0; i < n; i++) ans+=t[i];
    cout << ans;
    return 0;
}