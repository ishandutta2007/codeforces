#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>
#define y1 Enkognit

using namespace std;

const ll MOD = 998244353;

ll n, m, k, q, p, ans, l, r, i, j, x, y, kol=0, a[1000001];
vector <ll> c[300001];

int main()
{
    //freopen("redistricting.in","r",stdin);
    //freopen("redistricting.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        ll p=0;
        for (int i = 0; i < n; i++) {cin >> a[i];if (a[i]==1) p=i;}
        ll tt=2;
        ll o=p;
        do
        {
            ll z=o+1;
            if (z>=n) z%=n;
            if (a[z]-1!=a[o] && a[z]!=1) {tt--;break;}
            o++;
            if (o>=n) o%=n;
        }while (o!=p);
        o=p;
        do
        {
            ll z=o-1;
            if (z==-1) z+=n;
            if (a[z]-1!=a[o] && a[z]!=1) {tt--;break;}
            o--;
            if (o==-1) o+=n;
        }while (o!=p);
        if (tt) cout << "YES\n"; else cout << "NO\n";
    }
    return 0;
}


/*
2 4 4 2
1 2
1 4
2 3
2 1
1 3


*/