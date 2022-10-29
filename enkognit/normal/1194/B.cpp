#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>

using namespace std;

ll n, m, k, p, q, ans, l, r, i, j, x[500005], y[500005];
pll b[200005];
vector <ll> v, c[300005];
string s[50005];

int main()
{
    //freopen("redistricting.in","r",stdin);
    //freopen("redistricting.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    cin >> q;
    while (q--)
    {
        cin >> n >> m;
        for (int i = 1; i <= max(n,m); i++) x[i]=0,y[i]=0;
        for (int i = 1; i <= n; i++)
        {
            cin >> s[i];
            s[i]=' '+s[i];
            for (int j = 1; j <= m; j++)
            {
                x[i]+=(s[i][j]=='.');
            }
        }
    for (int j = 1; j <= m; j++)
        {
            for (int i = 1; i <= n; i++)
            {
                y[j]+=(s[i][j]=='.');
            }
        }
    ll ans=1e18;
    for (int i = 1; i <= n; i++)
       for (int j = 1; j <= m; j++)
    {
        ans=min(ans,x[i]+y[j]-(s[i][j]=='.'));
    }
    cout << ans << "\n";
    }
    return 0;
}