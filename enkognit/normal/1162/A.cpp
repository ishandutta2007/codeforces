#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define fr front()
#define sqr(a) ((a)*(a))
#define y1 Enkognit

using namespace std;

const ll MOD=1000000007;

ll n, m, l, r, x, h, y, ans, z, a[200001];
string s, d;

int main()
{
    //freopen("divisors.in","r",stdin);
    //freopen("divisors.out","w",stdout);
    cin >> n >> h >> m;
    for (int i = 1; i<= n; i++) a[i]=h;
    for (int i = 0; i < m; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        for (int i = x; i<= y; i++) a[i]=min(a[i],z);
    }
    ll ans=0;
    for (int i = 1; i<= n; i++)
        ans+=a[i]*a[i];
    cout << ans;
    return 0;
}
/*
5
2 3 4 5 6
6
1 2 4
1 2 3
0 1 1
0 4 7
1 1 3
1 1 4

*/