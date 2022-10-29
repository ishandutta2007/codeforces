#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define fr front()
#define pll pair<ll,ll>

using namespace std;

ll n, m, i, j, k, l, r, kol;
pair<pll,ll> a[100001];
map<ll,ll> t;
string s;

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)cin >> a[i].se;
    for (int i = 1; i <= n; i++){cin >> a[i].fi.fi;a[i].fi.se=i;}
    sort(a+1,a+n+1);
    for (int i = 1; i <= n; i++)
    {
        t[a[i].fi.se]=i;
        //cout << a[i].fi.se << " ";
    }
    //cout << "\n";
    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        //cout << t[x] << "\n";
        ll ans=0;
        if (y<=a[t[x]].se)
        {
            ans=y*a[t[x]].fi.fi;
            a[t[x]].se-=y;
            cout << ans << "\n";
        }
         else
        {
            ans+=a[t[x]].se*a[t[x]].fi.fi;
            y-=a[t[x]].se;
            a[t[x]].se=0;
            while(y && k<=n)
            {
                ll z=min(a[k].se,y);
                y-=z;
                a[k].se-=z;
                //cout << y << " " << k << " " << ans << "\n";
                ans+=z*a[k].fi.fi;
                if (a[k].se==0) k++;
            }
            if (y) cout << "0\n"; else cout << ans << "\n";
        }
    }
    return 0;
}
/*
7 2
1 1 1 1 1 3 3
1 2 3 3 1 1
*/