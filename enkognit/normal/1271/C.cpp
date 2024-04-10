#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define fi first
#define se second
#define pld pair<ld,ld>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define y1 Enkognit

using namespace std;

ll md1=1e9+7, md2=998244357, p1=31, p2=127;

ll n, m, k, a, b, c, e, f, l, r, i, j, x[300001], y[300001];
string s, d;
vector <ll> v1, v2, v3, v4;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    cin >> n >> x[0] >> y[0];
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
        if (x[i]>x[0] && y[i]>y[0]) v1.pb(i), v2.pb(i); else
        if (x[i]>x[0] && y[i]<y[0]) v3.pb(i), v2.pb(i); else
        if (x[i]<x[0] && y[i]>y[0]) v1.pb(i), v4.pb(i); else
        if (x[i]<x[0] && y[i]<y[0]) v3.pb(i), v4.pb(i);else
        if (x[i]==x[0])
        {
            if (y[i]>y[0]) v1.pb(i); else v3.pb(i);
        }
        if (y[i]==y[0])
        {
            if (x[i]>x[0]) v2.pb(i); else v4.pb(i);
        }
    }
    vector <pll> p;
    p.pb(mp(v1.size(),1));
    p.pb(mp(v2.size(),2));
    p.pb(mp(v3.size(),3));
    p.pb(mp(v4.size(),4));
    sort(p.begin(),p.end());
    reverse(p.begin(),p.end());
    ll o=p[0].se;
    if (o==1) cout << v1.size() << "\n" << x[0] << " " << y[0]+1 << "\n"; else
    if (o==3) cout << v3.size() << "\n" << x[0] << " " << y[0]-1 << "\n"; else
    if (o==2) cout << v2.size() << "\n" << x[0]+1 << " " << y[0] << "\n"; else
    if (o==4) cout << v4.size() << "\n" << x[0]-1 << " " << y[0] << "\n";
    return 0;
}
/*
6 5 2
5 1 3 6 2 4
1 3
1 6
3 5
4 5
2 2

3 3 5
1 12 6
1 3
2 3
1 2

7 6 1
1 8 9 3 12 5 2
3 5
4 6
1 3
2 2
2 6
3 5
*/