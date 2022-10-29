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

using namespace std;

ll n, m, k, i, j, h;
string s;
vector <pll> v;

ld rast(ld x,ld y,ld u,ld f)
{
    return sqrt(sqr(x-u)+sqr(y-f));
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output1.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        v.pb(mp(x,y));
    }
    if (n%2) {cout << "NO\n";exit(0);}
    for (int i = 0; i < n/2; i+=2)
    {
        ll j=i+n/2;
        if (abs(rast(v[i].fi,v[i].se,v[i+1].fi,v[i+1].se)-rast(v[j].fi,v[j].se,v[(j+1)%n].fi,v[(j+1)%n].se))>1e-12) {cout << "NO\n";exit(0);}
        if ((v[i].se==v[i+1].se && v[j].se==v[(j+1)%n].se)) continue;
        ld p1=(ld)(v[i].fi-v[i+1].fi)/(ld)(v[i].se-v[i+1].se);
        ld p2=(ld)(v[j].fi-v[(j+1)%n].fi)/(ld)(v[j].se-v[(j+1)%n].se);
        //cout << i << " " << j << " " << p1 << " " << p2 << "\n";
        if (abs(p1-p2)>1e-12) {cout << "NO\n";exit(0);}
    }
    cout << "YES\n";
    return 0;
}
/*
*/