#include <bits/stdc++.h>
#define ll long long
#define fr front()
#define fi first
#define mp make_pair
#define se second
#define pb push_back
#define pll pair<ll,ll>
#define pii pair<int,int>

using namespace std;

int n, m, i, j, ans, a[400001], b[400001];
int da[5000001], db[5000001];
string s;
//bool t[x][y];

void build(int h,int l,int r)
{
    if (l==r) {da[h]=a[l];db[h]=b[l];return;}
    int w=(l+r)/2;
    build(h*2,l,w);
    build(h*2+1,w+1,r);
    da[h]=max(da[h*2],da[h*2+1]);
    db[h]=min(db[h*2],db[h*2+1]);
}

pii get(int h,int l,int r,int x,int y)
{
    if (x>y) return mp(-1e9-1,1e9+1);
    if (l==x && y==r) return mp(da[h],db[h]);
    int w=(l+r)/2;
    pii p1=get(h*2,l,w,x,min(y,w)), p2=get(h*2+1,w+1,r,max(x,w+1),y);
    return mp(max(p1.fi, p2.fi), min(p1.se, p2.se));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();cout.tie();
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    build(1,1,n);

    ll ans=0;
    int l1=0, r1=0, l=0, r=0, w;
    pii o;
    for (int i = 1; i <= n; i++)
        if (a[i]<=b[i])
    {
        l = i, r = n, l1 = 0, r1 = 0;
        while (l<r)
        {
            w=(l+r)/2;
            o=get(1,1,n,i,w);
            if (o.fi<o.se) l=w+1; else r=w;
        }
        l1=l-1;
        do
        {
            l1++;
            o=get(1,1,n,i,l1);
        }while (o.fi<o.se && l1<n);

        o=get(1,1,n,i,l1);

        if (o.fi!=o.se) continue;

        l=l1, r=n;
        while (l<r)
        {
            w=(l+r)/2+(l+r)%2;
            o=get(1,1,n,i,w);
            if (o.fi==o.se) l=w; else r=w-1;
        }

        r1=r+1;
        do
        {
            r1--;
            o=get(1,1,n,i,r1);
        }while (o.fi>o.se && r1>=l1);

        o=get(1,1,n,i,r1);

        if (o.fi!=o.se) continue;
        ans+=max(r1-l1+1,0);
    }
    cout << ans;
    return 0;
}
/*
10000 10000 2
1 4232
3 1 10000 4231 10000
*/