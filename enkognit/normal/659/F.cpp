#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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

ll mx, l, r, n, m, k, s, ans, ln, kol, w, h, T, TT, mxm, a[1003][1003];
ll tt[1003][1003];
vector<pii> v;

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

void dfs(short x,short y)
{
    if (kol==TT) return;
    tt[x][y]=T;
    kol++;
    if (kol==TT) return;
    if (a[x+1][y]>=mxm && !tt[x+1][y]) dfs(x+1,y);
    if (kol==TT) return;
    if (a[x-1][y]>=mxm && !tt[x-1][y]) dfs(x-1,y);
    if (kol==TT) return;
    if (a[x][y+1]>=mxm && !tt[x][y+1]) dfs(x,y+1);
    if (kol==TT) return;
    if (a[x][y-1]>=mxm && !tt[x][y-1]) dfs(x,y-1);
    if (kol==TT) return;
}

void trying(ll kl,ll mx)
{
    //cout << kl << "-" << mx << "\n";
    v.clear();
    ll kll=0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            tt[i][j]=0;
            if (a[i][j]==mx) v.pb(mp(i,j));
            if (a[i][j]>=mx) kll++;
            //cout << b[i][j] << " ";
        }
        //cout << "\n";
    }
    TT=kl;
    mxm=mx;
    if (kll<kl) return;
    for (int i = 0; i < v.size(); i++)
        if (!tt[v[i].fi][v[i].se])
    {
        T=i+1;
        kol=0;
        dfs(v[i].fi,v[i].se);
        if (kol==TT)
        {
            cout << "YES\n";
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                    if (tt[i][j]==T) cout << mx << " "; else cout << "0 ";
                    cout << "\n";
            }
            exit(0);
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif // LOCAL
    ll mx=0;
    cin >> n >> m >> k;
    ll S=n*m;
    vector<ll> v;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            mx=max(a[i][j],mx);
            v.pb(a[i][j]);
        }
    sort(v.begin(),v.end());
    ll p=min((ll)sqrt(k),S);
    ll u=0, it=0;
    for (int i = 0; i < v.size(); i++)
        if (k%v[i]==0 && (i==0 || v[i]!=v[i-1]))
    {
        //cout << it << " " << k/it << "\n";
        it=v[i];
        u=k/it;
        if (u<=S) trying(u,it);
    }
    //cout << y << "\n";
    cout << "NO\n";
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