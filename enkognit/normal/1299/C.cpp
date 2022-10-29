#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define se second
#define fi first
#define ld long double
#define all(v) v.begin(),v.end()
#define sqr(a) ((a)*(a))
#define pld pair<ld,ld>
#define OO 1000000000000000000

using namespace std;

ll n, kl, m, k, i, j, h, a[1000001], b[1000001];
ld pr[1000001];
ld g[1000001];
string s;
vector <pair<pld,ld> > v;

ld get_cross_x(pld x, pld y)
{
    return (x.se-y.se)/(y.fi-x.fi);
}

void add(ld k,ld x)
{
    while (v.size()>0)
    {
        ld p=get_cross_x(mp((ld)k,(ld)x),v.back().fi);
        if (p-1e-12>v.back().se) v.pop_back();else {v.pb(mp(mp(k,x),p));break;}
    }

    if (v.size()==0)
    {
        v.pb(mp(mp(k,x),OO));
        return;
    }
}

pair<pair<ld,ll>,int> get(ld c)
{
    int l=0, r=v.size()-1;
    //if (l>r) return mp(-1,-1);
    while (l<r)
    {
        int w=(l+r+1)/2;
        //cout << l << "-" << w << "-" << r << "\n";
        if (v[w].se>=c) l=w; else r=w-1;
    }
    return mp(mp(((ld)c*(ld)v[l].fi.fi)+v[l].fi.se,-(ll)v[l].fi.fi),l);
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output1.txt","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pr[i]=pr[i-1]+a[i];
    }
    for (int i = n; i > 0; i--)
    {
        add((ld)-i,(ld)pr[i]);
    }
    //for (int i = 0; i < v.size(); i++) cout << v[i].fi.fi << " - " << v[i].fi.se << " " << v[i].se << "\n";
    ll r=v.size()-1;
    ld lr, rr, w;
    for (int i = 1; i <= n;)
    {
        while ((ll)-v[r].fi.fi<i) r--;
        //cout << r << "\n";
        while (r>0)
        {
            ld p=v[r].se;
            //cout << v[r].fi.fi << " - " << v[r].fi.se << " " << v[r].se << "\n";
            //cout << v[r].fi.fi*p+v[r].fi.se << " " << ((ld)-i+1)*p+(ld)pr[i-1] << "\n";
            if (v[r].fi.fi*p+v[r].fi.se>=-((ld)i-1)*p+(ld)pr[i-1]-1e-12) r--; else break;
        }
        //cout << v[r].fi.fi << " " << v[r].fi.se << "\n";
        ll j=(ll)-v[r].fi.fi;
        for (int u = i; u <= j; u++) g[u]=(ld)(pr[j]-pr[i-1])/(ld)(j-i+1);
        i=j+1;
    }
    cout.precision(10);
    for (int i = 1; i <= n; i++) cout <<fixed<< g[i] << "\n";
    return 0;
}