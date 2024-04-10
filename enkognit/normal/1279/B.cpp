#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ld long double
#define pll pair<ll,ll>
#define pld pair<ld,ld>

using namespace std;

ll n, m, k, l, r, ttt, x, y, i, T, t, j, kol, q;
ll a[1000001], pr[1000001];
string s, d;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while (q--)
    {
        ll n, m;
        cin >> n >> m;
        ll sum=0;
        for (int i = 1; i <= n; i++) {cin >> a[i];sum+=a[i];pr[i]=pr[i-1]+a[i];}
        if (sum<=m) {cout << "0\n";continue;}
        ll p=0, ans=0, w=1;
        for (int i = 1; i <= n; i++)
        {
            ll l=i, r=n;
            p+=a[i];
            while (l<r)
            {
                ll w=(l+r+1)/2;
                if (pr[w]-a[i]<=m) l=w; else r=w-1;
            }
            if (l>ans) ans=l, w=i;
            if (pr[i]>m) break;
        }
        cout << w << "\n";
    }
    return 0;
}
/*
4
2
3
8
5
10
1
11
15
*/