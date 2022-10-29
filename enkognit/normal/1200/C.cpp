#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
//#pragma GCC optimize("-Otime")
//#pragma GCC optimize("unr")
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

ll n, m, i, j, k, l, r, a[300001], d[1000001];
pll b[200001];
bool tt[1000001];
string s;


int main()
{
    //freopen("tickets.in","r",stdin);
    //freopen("tickets.out","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    ll n, m, q;
    cin >> n >> m >> q;
    ll o=__gcd(n,m);
    for (int i = 0; i < q; i++)
    {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll l=0, r=0;
        if (x1==1) l=(y1-1)/(n/o);
          else l=(y1-1)/(m/o);
        if (x2==1) r=(y2-1)/(n/o); else r=(y2-1)/(m/o);
        if (l==r) cout << "YES\n"; else cout << "NO\n";
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