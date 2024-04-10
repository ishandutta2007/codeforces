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

ll n, m, i, j, y, kol=1,  b[200001];

struct matrix
{
    ll c[11][11];
};

matrix z, x;

ll mlp(ll x, ll y)
{
    if (y==0) return 0;
    if (x <= m / y) return x*y; else return m;
}

matrix mltp(matrix a,matrix b)
{
    matrix c;
    //cout << 1 << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c.c[i][j]=0;
            for (int u = 0; u < n; u++)
            {
                c.c[i][j]+=mlp(a.c[i][u], b.c[u][j]);
                c.c[i][j]=min(c.c[i][j],m);
            }
            //cout << c.c[i][j] << " ";
        }
        //cout << "\n";
    }
    //cout << "\n";
    //cout << c.c[0][9] << "\n";
    return c;
}

matrix binpow(matrix a, ll h)
{
    matrix ans;
    ll l=h, u=0, tt=0;
    while (l)
    {
        if (l%2)
        {
            if (tt)
            ans=mltp(ans, a); else ans=a,tt=1;
        }
        a=mltp(a, a);
        l/=2;
    }
    //cout << u << "\n";
    return ans;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    ll ans=0;
    for (int i = 0; i < n; i++) {cin >> b[i];ans=max(ans,b[i]);}
    reverse(b,b+n);
    while (b[n-1]==0) n--;
    reverse(b,b+n);
    //cout << n << "\n";
    if (m<=ans) {cout << 0;exit(0);}
    if (n>10)
    {
        ll t=0;
        while (true)
        {
            t++;
            //for (int i = 0; i < n; i++) c[i]=b[i];
            for (int i = 0; i < n; i++)
            {
                if (i>0)
                b[i]+=b[i-1];
                if (b[i]>=m) {cout << t;exit(0);}
            }
        }
    }
    for (int i = 0; i < n; i++) x.c[0][i]=b[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) if (i<=j) z.c[i][j]=1;
    ll l=1, r=m;
    //cout << mltp(x, binpow(z, 10369)).c[0][n-1] << "\n";
    while (l<r)
    {
        ll w=(l+r)/2;
        ll u=mltp(x, binpow(z,w)).c[0][n-1];
        //cout << u << " " << w << "\n";
        if (u<m) l=w+1; else r=w;
    }
    cout << l;
    return 0;
}