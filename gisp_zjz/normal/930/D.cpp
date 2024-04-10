#include<bits/stdc++.h>
#define maxn 203000
#define x first
#define y second

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
ll ans,n,l,r,p,q;
pi a[maxn],b[maxn],c[maxn],d[maxn];

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        int u,v;scanf("%d%d",&u,&v);
        if ((u+v)%2) a[p++]={u+v,u-v}; else b[q++]={u+v,u-v};
    }
    sort(a,a+p);sort(b,b+q);
    if (p>3) {
        l=a[0].y; r=a[0].y;
        for (int i=0;i<p-1;i++)
        {
            l=min(a[i].y,l);
            r=max(a[i].y,r);
            c[i].x=l; c[i].y=r;
        }
        l=a[p-1].y; r=a[p-1].y;
        for (int i=p-1;i;i--)
        {
            l=min(a[i].y,l);
            r=max(a[i].y,r);
            d[i-1].x=l; d[i-1].y=r;
        }
        for (int i=0;i<p-1;i++) ans+=(a[i+1].x-a[i].x)*max(0ll,min(c[i].y,d[i].y)-max(c[i].x,d[i].x));
    }
    if (q>3) {
        l=b[0].y; r=b[0].y;
        for (int i=0;i<q-1;i++)
        {
            l=min(b[i].y,l);
            r=max(b[i].y,r);
            c[i].x=l; c[i].y=r;
        }
        l=b[q-1].y; r=b[q-1].y;
        for (int i=q-1;i;i--)
        {
            l=min(b[i].y,l);
            r=max(b[i].y,r);
            d[i-1].x=l; d[i-1].y=r;
        }
        for (int i=0;i<q-1;i++) ans+=(b[i+1].x-b[i].x)*max(0ll,min(c[i].y,d[i].y)-max(c[i].x,d[i].x));
    }
    cout << ans/4 << endl;
}