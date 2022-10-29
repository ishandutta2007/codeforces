#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define se second
#define fi first
#define ld long double

using namespace std;

ll md1=1e9+9, md2=998244357, p1=31, p2=127;

ll n, m, k, i, j, a[1000001], b[1000001];
string s, d;
vector<ll> v[101];

struct fentree
{
    ll f[1000001];

    void update(int h,int k)
    {
        for (int i = h; i > 0; i-=(i&-i)) f[i]+=k;
    }

    ll get(int h)
    {
        ll ans=0;
        for (int i = h; i <= n; i+=(i&-i)) ans+=f[i];
        return ans;
    }
};

struct bintree
{
    ll d[2000001];
    ll tt[2000001];

    void push(int h)
    {
        if (tt[h])
        {
            d[h*2]+=tt[h];
            d[h*2+1]+=tt[h];
            tt[h*2]+=tt[h];
            tt[h*2+1]+=tt[h];
            tt[h]=0;
        }
    }

    void update(int h,int l,int r,int x,int y,int k)
    {
        push(h);
        if (x>y) return;
        if (l==x && r==y) {d[h]+=k;tt[h]+=k;push(h);return;}
        int w=(l+r)/2;
        update(h*2,l,w,x,min(y,w),k);
        update(h*2+1,w+1,r,max(x,w+1),y,k);
        d[h]=min(d[h*2],d[h*2+1]);
    }

    ll get(int h,int l,int r,int x,int y)
    {
        push(h);
        d[h]=min(d[h*2],d[h*2+1]);
        if (x>y) return 1e18;
        if (l==x && y==r) return d[h];
        int w=(l+r)/2;
        return min(get(h*2,l,w,x,min(y,w)),get(h*2+1,w+1,r,max(x,w+1),y));
    }
};

bintree g1;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output1.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        //g2.update(1,0,n,0,a[i]-1,b[i]);
        g1.update(1,0,n,a[i],n,b[i]);
    }
    /*cout << "0 : \n";
        cout << " g1 : ";
        for (int i = 0; i <= n; i++) cout << g1.get(1,0,n,i,i) << " ";
        cout <<"\n";
        cout << " g2 : ";
        for (int i = 0; i <= n; i++) cout << g2.get(1,0,n,i,i) << " ";
        cout <<"\n";*/
    ll ans=1e18;
    for (int i = 1; i < n; i++)
    {
        //g2.update(1,0,n,0,a[i]-1,-b[i]);
        g1.update(1,0,n,a[i],n,-b[i]);
        g1.update(1,0,n,0,a[i]-1,b[i]);
        //g2.update(1,0,n,a[i],n,b[i])
        ans=min(g1.d[1],ans);
    }
    cout << ans;
    return 0;
}
/*
*/