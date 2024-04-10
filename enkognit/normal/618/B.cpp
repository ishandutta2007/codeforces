#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define y1 Enkognit
#define fi first
#define se second

using namespace std;

const ll MOD=1000000007;

ll l, r, n, m, k, a[101][101], b[1000001];
bool tt[100001];
vector <ll> an;

ll binpow(ll h,ll r)
{
    ll l=1;
    while (r)
    {
        if (r&1) l*=h,l%=MOD;
        h*=h;
        h%=MOD;
        r/=2;
    }
    return l;
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    for (int i = 1; i < n; i++)
    {
        ll ps=0;
        for (int j = 1; j <= n; j++)
        {
            bool t=1;
            ll l=j, o=0;
            for (int u = 1; u <= n; u++)
            {
                if (a[j][u]!=0) t=min((a[j][u]==i),t), o++;
                if (a[u][j]!=0) t=min((a[u][j]==i),t), o++;
            }
            if (!t || !o) continue;
            ps=j;
            for (int u = 1; u <= n; u++) a[ps][u]=0,a[u][ps]=0;
            break;
        }
        b[ps]=i;
    }
    for (int i = 1; i <= n; i++) if (b[i]==0) cout << n << " "; else cout << b[i] << " ";
    return 0;
}