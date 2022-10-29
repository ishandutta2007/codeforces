#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pb push_back
#define pii pair<int,int>

using namespace std;

const ll MOD=1e9+7;

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

ll md1=1e9+7, md2=998244353, md3=453256111, p1=31, p2=23, p3=19;

ll n, m, T, k, l, r, i, j, st1[100001], st2[100001], st3[100001], o, kol=0, ans[200001], tt[2000001], a[200001], b[200001], pp1[200001], pp2[200001],
pp3[200001], pr1[200001], pr2[200001], pr3[200001];

struct hesh
{
    ll h1, h2, h3;
};

hesh d[2000001], h0;

string s;


ll binpow(ll h,ll r,ll md)
{
    ll l=1;
    while (r)
    {
        if (r&1) l*=h, l%=md;
        h*=h;
        h%=md;
        r/=2;
    }
    return l%md;
}

void push(int h,int l,int r)
{
    if (tt[h]!=-1)
    {
        tt[h*2]=tt[h];
        tt[h*2+1]=tt[h];
        d[h].h1=(pp1[r-l]*tt[h])%md1;
        d[h].h2=(pp2[r-l]*tt[h])%md2;
        d[h].h3=(pp3[r-l]*tt[h])%md3;
        tt[h]=-1;
    }
}

void build(int h,int l,int r)
{
    tt[h]=-1;
    if (l==r) {d[h].h1=s[l]-'0';d[h].h2=d[h].h1;d[h].h3=d[h].h2;return;}
    ll w=(l+r)/2;
    build(h*2,l,w);
    build(h*2+1,w+1,r);
    d[h].h1=(d[h*2].h1+d[h*2+1].h1*st1[w-l+1]%md1)%md1;
    d[h].h2=(d[h*2].h2+d[h*2+1].h2*st2[w-l+1]%md2)%md2;
    d[h].h3=(d[h*2].h3+d[h*2+1].h3*st3[w-l+1]%md3)%md3;
}

void update(int h,int l,int r,int x,int y,int p)
{
    push(h,l,r);
    if (x>y) return;
    if (l==x && y==r)
    {
        tt[h]=p;
        push(h,l,r);
        return;
    }
    int w=(l+r)/2;
    update(h*2,l,w,x,min(y,w),p);
    update(h*2+1,w+1,r,max(x,w+ 1),y,p);
    d[h].h1=(d[h*2].h1+d[h*2+1].h1*st1[w-l+1]%md1)%md1;
    d[h].h2=(d[h*2].h2+d[h*2+1].h2*st2[w-l+1]%md2)%md2;
    d[h].h3=(d[h*2].h3+d[h*2+1].h3*st3[w-l+1]%md3)%md3;
}

hesh get(int h,int l,int r,int x,int y)
{
    push(h,l,r);
    if (x>y) return h0;
    if (l==x && y==r)
    {
        return d[h];
    }
    int w=(l+r)/2;
    hesh lr=get(h*2,l,w,x,min(y,w)), rr=get(h*2+1,w+1,r,max(x,w+1),y);
    lr.h1=(lr.h1+rr.h1*st1[max(w-x+1,0)]%md1)%md1;
    lr.h2=(lr.h2+rr.h2*st2[max(w-x+1,0)]%md2)%md2;
    lr.h3=(lr.h3+rr.h3*st3[max(w-x+1,0)]%md3)%md3;
    return lr;
}

vector <pair<pll, pair<pair<hesh,hesh>, ll> > > v;

bool comp(pair<pll, pair<pair<hesh,hesh>, ll> > x, pair<pll, pair<pair<hesh,hesh>, ll> > y)
{
    return x.fi.fi>y.fi.fi;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    pp1[0]=1;
    pp2[0]=1;
    pp3[0]=1;
    st1[0]=1;
    st2[0]=1;
    st3[0]=1;
    for (int i = 1; i <= n; i++)
    {
        st1[i]=(st1[i-1]*p1)%md1;
        st2[i]=(st2[i-1]*p2)%md2;
        st3[i]=(st3[i-1]*p3)%md3;
    }
    for (int i = 1; i <= n; i++)
    {
        pp1[i]=pp1[i-1]+st1[i];
        pp1[i]%=md1;
        pp2[i]=pp2[i-1]+st2[i];
        pp2[i]%=md2;
        pp3[i]=pp3[i-1]+st3[i];
        pp3[i]%=md3;

    }
    cin >> s;
    s=' '+s;
    T=0;

    build(1,1,n);
    for (int i = 0; i < m+k; i++)
    {
        ll t;
        cin >> t;
        if (t==1)
        {
            ll l, r, c;
            cin >> l >> r >> c;
            update(1,1,n,l,r,c);
        }else
        if (t==2)
        {
            ll l, r, d;
            T++;
            cin >> l >> r >> d;
            hesh o1=get(1,1,n,r-(r-l+1)%d+1,r), o2=get(1,1,n,l,l+(r-l+1)%d-1);
            if (o1.h1!=o2.h1 || o1.h2!=o2.h2 || o1.h3!=o2.h3)
            {
               ans[T]=-1;
            }
            r-=(r-l+1)%d;
            hesh o=get(1,1,n,l,l+d-1);
            hesh p=get(1,1,n,l,r);
            v.pb(mp(mp(r-l+1,d),mp(mp(o,p),T)));
        }
    }
    sort(v.begin(),v.end(),comp);

    //cout << "\n";+
    //reverse(v.begin(),v.end());
    for (int i = 1; i <= n; i++)
    {
        //cout << v.back().fi.fi << "-\n";
        //if (v.size()==0) break;
        while (v.size() && v.back().fi.fi==i)
        {
            if (ans[v.back().se.se]==-1) {v.pop_back();continue;}
            hesh u=v.back().se.fi.fi;
            u.h1=(u.h1*(pr1[v.back().fi.se]+1))%md1;
            u.h2=(u.h2*(pr2[v.back().fi.se]+1))%md2;
            u.h3=(u.h3*(pr3[v.back().fi.se]+1))%md3;
            //cout << u.h1 << " " << u.h2 << " " << u.h3 << "\n";
            //cout << v.back().se.fi.se.h1 << " " << v.back().se.fi.se.h2 << " " << v.back().se.fi.se.h3 << "\n";
            if (u.h1!=v.back().se.fi.se.h1 || u.h2!=v.back().se.fi.se.h2 || u.h3!=v.back().se.fi.se.h3)
                ans[v.back().se.se]=-1; else ans[v.back().se.se]=1;
            v.pop_back();
            //cout << v.size() << "---\n";
        }
        ll p=sqrt(i);
        if (v.size()==0) break;
        for (int j = 1; j <= p; j++)
            if (i%j==0)
            {
                pr1[j]+=st1[i];
                pr2[j]+=st2[i];
                pr3[j]+=st3[i];
                pr1[j]%=md1;
                pr2[j]%=md2;
                pr3[j]%=md3;
                if (i/j!=j)
                {
                    pr1[i/j]+=st1[i];
                    pr2[i/j]+=st2[i];
                    pr3[i/j]+=st3[i];
                    pr1[i/j]%=md1;
                    pr2[i/j]%=md2;
                    pr3[i/j]%=md3;
                }
            }
        //cout << pr1[i] << "\n";
    }
    for (int i = 1; i <= k; i++) if (ans[i]==1) cout << "YES\n"; else cout << "NO\n";
    return 0;
}
/*
5 6
X...XX
XX...X
......
..XX..
XXX..X
*/