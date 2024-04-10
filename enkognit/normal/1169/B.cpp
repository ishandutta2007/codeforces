#include <bits/stdc++.h>
#define ll long long
#define fr front()
#define fi first
#define mp make_pair
#define se second
#define pb push_back
#define pll pair<ll,ll>

using namespace std;

//ll n, m, i, j, k, l, r, ans, T, Q, K, a[300001], b[100001];
//string s, d;
//vector <ll> c[300001], v;

bool t[1000001], p[10001];
pll a[400001];
ll n, m ,i, j;

int main()
{
    //ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i].fi >> a[i].se;
        if (a[i].fi>a[i].se) swap(a[i].fi,a[i].se);
    }
    //sort(a,a+m);
    ll o=0;
    vector <pll> v, p;
    //cout << "\n";
    for (int i = 1; i < m; i++)
    {
        if (a[i].fi!=a[0].fi && a[i].se!=a[0].fi) v.pb(a[i]);
        if (a[i].fi!=a[0].se && a[i].se!=a[0].se) p.pb(a[i]);
    }
    bool tv1=1, tv2=1;
    //cout << v[0].fi << " " << v[0].se << "\n";
    for (int i = 1; i < v.size(); i++)
    {
       // cout << v[i].fi << " " << v[i].se << "\n";
        if (v[0].fi!=v[i].fi && v[0].fi!=v[i].se) tv1=0;
        if (v[0].se!=v[i].fi && v[0].se!=v[i].se) tv2=0;
    }
    //cout << "\n";
    bool tp1=1, tp2=1;
    //cout << p[0].fi << " " << p[0].se << "\n";
    for (int i = 1; i < p.size(); i++)
    {
        //cout << p[i].fi << " " << p[i].se << "\n";
        if (p[0].fi!=p[i].fi && p[0].fi!=p[i].se) tp1=0;
        if (p[0].se!=p[i].fi && p[0].se!=p[i].se) tp2=0;
    }
    if ((tv1||tv2)||(tp1||tp2))cout << "YES\n"; else cout << "NO\n";
    return 0;
}
/*
10000 10000 2
1 4232
3 1 10000 4231 10000
*/