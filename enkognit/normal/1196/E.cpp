#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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

ll n, m, k, dp[200001][4], q, p, ans, l, r, i, j, x, y;
char c[4];
string s;

int main()
{
    //freopen("redistricting.in","r",stdin);
    //freopen("redistricting.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll w, b;
        cin >> w >> b;
        bool tt=0;
        if (w<b) swap(w,b), tt=1;
        ll l1=2, r1=2, l2=2, r2=2, bb=b, ww=w;
        vector <pll> v;
        while (bb)
        {
            bb--, ww--;
            v.pb(mp(l2,r2));
            r2++;
            v.pb(mp(l2,r2));
            r2++;
        }
        r2--;
        for (int i = r1; i <= r2; i+=2)
        {
            if (ww) v.pb(mp(l1+1,i)), ww--;
            if (ww) v.pb(mp(l1-1,i)), ww--;
        }
        if (ww)
        {
            v.pb(mp(l1,r1-1));
            ww--;
        }
        if (ww || bb) cout << "NO\n"; else
        {
            cout << "YES\n";
            for (int i = 0; i < v.size(); i++) cout << v[i].fi << " " << v[i].se+tt << "\n";
        }
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