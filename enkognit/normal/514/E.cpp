#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define ld long double
#define pld pair<ld,ld>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 1e9+7;
const ll INF=1e18;
const ld E=1e-8;
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 29, p3 = 7, p4=rnd()%100+1, md1 = MOD, md2 = 998244353, md3=998244357, md4=rnd()%1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, h, T, q, a[1000001];

ll binpow(ll h, ll r, ll md = MOD)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h, l %= md;
        h *= h;
        h %= md;
        r /= 2;
    }
    return l;
}

ll gcd(ll x, ll y)
{
    if (x < y) swap(x, y);
    while (x && y)
    {
        x %= y;
        swap(x, y);
    }
    return x + y;
}

struct matrix
{
    ll b[110][110];

    matrix(){for (int i = 1; i <= 102; i++) for (int j = 1; j <= 102; j++) b[i][j]=0;};
};

matrix mult(matrix x,matrix y)
{
    matrix w=matrix();
    for (int i = 1; i <= 102; i++)
        for (int j = 1; j <= 102; j++)
        {
            ll q=0;
            for (int u = 1; u <= 102; u++)
            {
                q=(q+x.b[i][u]*y.b[u][j]%MOD)%MOD;
                if (q<0) q+=MOD;
            }
            w.b[i][j]=q;
        }
    return w;
}

matrix bnpow(matrix h,ll r)
{
    matrix l=h;
    r--;
    while (r)
    {
        if (r&1) l=mult(l,h);
        h=mult(h,h);
        r/=2;
    }
    return l;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    if (m==0)
    {
        cout << "1\n";
        exit(0);
    }
    matrix w = matrix(), q = matrix();
    for (int i = 2; i <= 105; i++) w.b[i-1][i]=1;
    w.b[1][1]=1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        w.b[a[i]][1]++;
        w.b[a[i]+1][1]--;
    }
    q.b[1][1]=1;
    w=bnpow(w,m);

    q=mult(q,w);
    cout << q.b[1][1] << "\n";
    return 0;
}

/*
7 6
2 1 1
3 1 2
1 4 0
4 5 1
5 6 3
5 7 4
1 3
4 1
2 4
2 5
3 5
3 7
*/