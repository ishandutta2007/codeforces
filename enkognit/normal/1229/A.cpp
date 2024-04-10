#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pll pair<ll,ll>
#define pii pair<int,int>

using namespace std;

ll n, m, i, j, k, l, ans, r, b[500001], T, o, an=0;
pll a[200001];
vector <ll> v;
map <ll,bool> tt;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i].fi;
    for (int i = 0; i < n; i++) cin >> a[i].se;
    sort(a,a+n);
    ll l=1, r=a[0].fi, sum=a[0].se;
    a[n].fi=-1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i].fi==r)
        {
            l++;
            sum+=a[i].se;
        }else
        {
            if (l>1) tt[r]=1, ans+=sum, v.pb(r);
            l=1;sum=a[i].se;r=a[i].fi;
        }
    }
    ll mx=0;
    for (int i = 0; i < n; i++)
    {
        if (!tt[a[i].fi])
        {
            bool t=0;
            for (int j = 0; j < v.size(); j++)
            {
                if ((a[i].fi&(v[j]^a[i].fi))==0) t=1;
            }
            if (t) ans+=a[i].se;
        }
    }
    cout << ans;
    return 0;
}
/*
8 7
1 1 30 5 5 1 1 1
1 2
2 3
2 4
4 5
2 6
6 7
6 8
2
*/