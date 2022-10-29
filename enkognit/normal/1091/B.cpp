#include <bits/stdc++.h>
#define ll long long
#define fr front()
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define pu push
#define pll pair<ll,ll>


using namespace std;

ll n, m, k;
pll a[1001],b[1001];
string s;
map<pll,ll> t;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i].fi >> a[i].se;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i].fi >> b[i].se;
        t[mp(b[i].fi,b[i].se)]++;
    }
    for (int i = 0; i < n; i++)
    {
        ll x=a[0].fi+b[i].fi, y=a[0].se+b[i].se;
        map<pll,ll> z=t;
        z[mp(b[i].fi,b[i].se)]--;
        ll p=0;
        for (int j = 1; j < n; j++)
        {
            if (z[mp(x-a[j].fi,y-a[j].se)]) z[mp(x-a[j].fi,y-a[j].se)]--;else break;
            p++;
        }
        if (p==n-1) {cout << x <<" "<< y;exit(0);}
    }
    return 0;
}