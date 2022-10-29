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

ll n, m, k, q, ans=1e18, l, r, i, j, x, y, kol=0, a[1000001];
pll b[100001];
vector <ll> c[300001];
string s;

int main()
{
    //freopen("walk.in","r",stdin);
    //freopen("walk.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll b, p, f, h, c, ans=0;
        cin >> b >> p >> f;
        cin >> h >> c;
        for (int i = 0; i <= p; i++)
        {
            ll o=min(p, b/2);
            ans=max(ans, h*o + min(f, (b-o*2)/2)*c);
        }
        for (int i = 0; i <= f; i++)
        {
            ll o=min(f, b/2);
            ans=max(ans, c*o + min(p, (b-o*2)/2)*h);
        }
        cout << ans << "\n";
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