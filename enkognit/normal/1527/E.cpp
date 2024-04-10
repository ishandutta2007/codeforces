#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("popcnt")
#include <random>
#include <time.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()
#define fi first
#define se second
#define pll pair<ll,ll>
#define pii pair<int,int>
#define ld long double

using namespace std;

mt19937_64 rnd(time(0));

ll n, T, m, k, a[100001], lf[100001], rg[100001], sf[100001], pr[100001], lst[100001];

struct segment_tree
{
    ll d[150001], tt[150001];

    void build(int h,int l,int r)
    {
        if (l==r)
        {
            if (T==1)d[h]=pr[l]+sf[l+1]; else d[h]=0;
            return;
        }
        int w=(l+r)/2;
        build(h*2,l,w);
        build(h*2+1,w+1,r);
        d[h]=min(d[h*2], d[h*2+1]);
    }

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
        if (x>y) return;
        if (l==x && y==r)
        {
            d[h]+=k;
            tt[h]+=k;
            return;
        }
        push(h);
        int w=(l+r)/2;

        update(h*2,l,w,x,min(y,w),k);
        update(h*2+1,w+1,r,max(x,w+1),y,k);

        d[h]=min(d[h*2], d[h*2+1]);
    }

    ll get(int h,int l,int r,int x,int y)
    {
        if (x>y) return 1e18;
        if (l==x && y==r) return d[h];
        int w=(l+r)/2;
        push(h);
        return min(get(h*2,l,w,x,min(y,w)), get(h*2+1,w+1,r,max(x,w+1),y));
    }
} g[101];

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        lf[i]=lst[a[i]];
        lst[a[i]]=i;
    }

    for (int i = 1; i <= n; i++) lst[a[i]]=n+1;

    for (int i = n; i > 0; i--)
    {
        rg[i]=lst[a[i]];
        lst[a[i]]=i;
    }

    for (int i = n; i > 0; i--)
    {
        sf[i]=sf[i+1];
        if (rg[i]!=n+1) sf[i]+=rg[i]-i;
    }

    for (int i = 1; i <= n; i++)
    {
        pr[i]=pr[i-1];
        if (lf[i]!=0) pr[i]+=i-lf[i];
    }

    for (T = 1; T <= k; T++)
        g[T].build(1,T,n);

    if (k==1)
    {
        cout << pr[n] << "\n";
        return;
    }

    k--;

    //cout << "----\n";
    //cout << pr[2] << " " << sf[3] << "\n";
    //for (int i = 1; i <= n; i++) cout << g[1].get(1,0,n,i,i) << " ";
    //cout << "\n";

    for (int i = 1; i <= n; i++)
    {
        //cout << i << " - "  << lf[i] << " " << rg[i] << "\n";
        for (int j = 2; j <= min(k, (ll)i); j++)
        {
            //cout << j << "\n";
            if (rg[i]!=n+1)
            {
                g[j-1].update(1,j-1,n,j-1,i-1,-(rg[i]-i));
            }
            if (lf[i]!=0)
            {
                g[j-1].update(1,j-1,n,j-1,lf[i]-1,i-lf[i]);
            }
            //cout << i << " " << j << " " << g[j-1].get(1,1,n,1,i-1) << "\n";
            g[j].update(1,j,n,i,i,g[j-1].get(1,j-1,n,j-1,i-1));
            //cout << "    " << g[j].get(1,0,n,i,i) << "\n";
        }
    }
    cout << g[k].get(1,k,n,k,n) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
1000000000000000 4523 3
456 23
4562 78
456239 456
*/