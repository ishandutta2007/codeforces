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

ll n, m, i, j, w, y, ans, a[200001];
pll d[9][1000001];
pll o1, o2;

void build(int p,int h,int l,int r)
{
    if (l==r)
    {
        d[p][h]=mp(2e9,2e9);
        return;
    }
    ll w=(l+r)/2;
    build(p,h*2,l,w);
    build(p,h*2+1,w+1,r);
    d[p][h]=mp(2e9,2e9);
}

void update(int p,int h,int l,int r,int x,ll y)
{
    if (l==r)
    {
        d[p][h].fi=y;
        return;
    }
    int w=(l+r)/2;
    if (x<=w) update(p,h*2,l,w,x,y); else update(p,h*2+1,w+1,r,x,y);
    o1=d[p][h*2];o2=d[p][h*2+1];
    if (o1.fi+o1.se<=o1.fi+o2.fi && o1.fi+o1.se<=o2.se+o2.fi) d[p][h]=o1;else
    if (o2.fi+o2.se<=o1.fi+o2.fi && o1.fi+o1.se>=o2.se+o2.fi) d[p][h]=o2;else
    if (o1.fi+o2.fi<=o1.fi+o1.se && o1.fi+o2.fi<=o2.se+o2.fi) d[p][h]=mp(min(o1.fi,o2.fi),max(o1.fi,o2.fi));
}

pll get(int p,int h,int l,int r,int x,int y)
{
    if (x>y) return mp(2e9,2e9);
    if (l==x && y==r)
    {
        return d[p][h];
    }
    int w=(l+r)/2;
    pll o1=get(p,h*2,l,w,x,min(y,w)), o2=get(p,h*2+1,w+1,r,max(x,w+1),y);
    if (o1.fi+o1.se<=o1.fi+o2.fi && o1.fi+o1.se<=o2.se+o2.fi) return o1;else
    if (o2.fi+o2.se<=o1.fi+o2.fi && o1.fi+o1.se>=o2.se+o2.fi) return o2;else
    if (o1.fi+o2.fi<=o1.fi+o1.se && o1.fi+o2.fi<=o2.se+o2.fi) return mp(min(o1.fi,o2.fi),max(o1.fi,o2.fi));
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < 9; i++) build(i,1,1,n);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ll z=a[i], p=0;
        while (z)
        {
            if (z%10)
            {
                update(p,1,1,n,i,a[i]);
            }
            z/=10;
            p++;
        }
    }
    ll mn, q;
    pll u, o;
    for (int j = 0; j < m; j++)
    {
        ll t, x, y;
        cin >> t >> x >> y;
        if (t==1)
        {
            q=y;
            for (int j = 0; j < 9; j++)
            {
                if (q%10)
                {
                    update(j,1,1,n,x,y);
                }else update(j,1,1,n,x,2e9);
                q/=10;
            }
        }else
        {
            mn=1e18;
            u=mp(1e9,1e9);
            for (int i = 0; i < 9; i++)
            {
                //cout << i << "\n";
                pll o=get(i,1,1,n,x,y);
                if (mn>o.fi+o.se) mn=o.fi+o.se, u=o;
            }
            if (u.fi>=1e9 || u.se>=1e9) cout << "-1\n"; else cout << mn << "\n";
        }
    }
    return 0;
}