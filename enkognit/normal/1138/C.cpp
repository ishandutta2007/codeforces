#include <bits/stdc++.h>
#include <cstdlib>

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

ld PI=3.14159265359, sec_clock=1e8;

ll n, m, l, r, k, h, i, j, T, a[1001][1001], b[1001][1001], c[1001][1001], c1[1001], b1[1001];
//ll a[500001], b[500001];
queue <ll> q;


int main()
{
    //freopen("sum.in","r",stdin);
    //freopen("sum.out","w",stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> a[i][j];
    for (int i = 0; i < n; i++)
    {
        vector <pll> v;
        for (int j = 0; j < m; j++) v.pb(mp(a[i][j],j));
        sort(v.begin(),v.end());
        ll k=1;
        b[i][v[0].se]=k;
        for (int j = 1; j < v.size(); j++)
        {
            if (v[j].fi!=v[j-1].fi) k++;
            b[i][v[j].se]=k;
        }
        b1[i]=k;
    }
    for (int i = 0; i < m; i++)
    {
        vector <pll> v;
        for (int j = 0; j < n; j++) v.pb(mp(a[j][i],j));
        sort(v.begin(),v.end());
        ll k=1;
        c[v[0].se][i]=k;
        for (int j = 1; j < v.size(); j++)
        {
            if (v[j].fi!=v[j-1].fi) k++;
            c[v[j].se][i]=k;
        }
        c1[i]=k;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ll p=c1[j], o=b1[i];
            if (c[i][j]<=b[i][j]) p+=b[i][j]-c[i][j];
            if (c[i][j]>=b[i][j]) o+=c[i][j]-b[i][j];
            cout << max(o,p) << " ";
            //cout << i+1 << " " << j+1 << " " << b[i][j] << " " << c[i][j] << " " << b1[i] <<  "\n";
        }
        cout << "\n";
    }
    return 0;
}