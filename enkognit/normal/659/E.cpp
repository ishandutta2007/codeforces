#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define pll pair<ll,ll>
#define pii pair<int,int>
#define y1 Enkognit
#define fi first
#define se second
#define pld pair<ld,ld>

using namespace std;

const ll MOD=1000000007;

ll l, r, n, m, k, s, ans, ln, w, h, T, TT, x[1000001], y[1000001];
bool tt[1000001], ttt;
vector <ll> c[200001];

template<typename BRUH>
inline BRUH sqr(BRUH x)
{
    return x*x;
}

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

void dfs(int h)
{
    T++;
    tt[h]=1;
    TT+=c[h].size();
    for (int i = 0; i < c[h].size(); i++)
        if (!tt[c[h][i]])
    {
        dfs(c[h][i]);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif // LOCAL
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    ll ans=0;
    for (int i = 1; i <= n; i++)
        if (!tt[i])
    {
        T=0;
        TT=0;
        dfs(i);
        ans+=max(T-TT/2,0ll);
    }
    cout << ans;
    return 0;
}
/*
3 3 0
1 a
2 b
3 a
4 b
2 a
*/