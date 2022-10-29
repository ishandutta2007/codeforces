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
#define pii pair<int,int>
#define y1 Enkognit

using namespace std;

const ll MOD=998244353;

ll n, m, k, q, ans=1e18, l, r, i, j, x, y, kol=0, sum, sm[310][310];

ll a[500001];
map<ll,bool> tt;
string s;

ll fact(ll h)
{
    if (h==1) return 1; else return (h*fact(h-1))%MOD;
}

int main()
{
    //freopen("walk.in","r",stdin);
    //freopen("walk.out","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ll t, x, y;
        cin >> t >> x >> y;
        if (t==1)
        {
            a[x]+=y;
            for (int j = 1; j < 301; j++) sm[j][x%j]+=y;
        }
        if (t==2)
        {
            if (x<301) cout << sm[x][y] << "\n"; else
            {
                ll p=0;
                for (int j = y; j <= 500000; j+=x) p+=a[j];
                cout << p << "\n";
            }
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