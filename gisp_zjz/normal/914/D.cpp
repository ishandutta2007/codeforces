#include<bits/stdc++.h>
#define maxn 502030

using namespace std;

struct seg{
    int mn,l,r;
};

seg a[maxn*4];
int b[maxn],c[maxn],n,query,m;

int gcd(int x,int y)
{
    if (x%y==0) return y; else return gcd(y,x%y);
}

void build(int x,int l,int r)
{
    a[x].l=l;
    a[x].r=r;
    if (l==r) {a[x].mn=b[l];return ;}
    int mid=(l+r)>>1;
    build(x*2,l,mid);
    build(x*2+1,mid+1,r);
    a[x].mn=gcd(a[x*2].mn,a[x*2+1].mn);
}

void update(int x,int l,int r,int val)
{
    if (a[x].l>r||a[x].r<l) return;
    if (a[x].l==a[x].r) a[x].mn=val;
    else {
        update(x*2,l,r,val);
        update(x*2+1,l,r,val);
        a[x].mn=gcd(a[x*2].mn,a[x*2+1].mn);
    }
}

int qry(int x,int l,int r,int val)
{
    if (a[x].l>r||a[x].r<l) return 0;
    if (a[x].l>=l&&a[x].r<=r&&a[x].mn%val==0) return 0;
    if (a[x].l==a[x].r) return a[x].mn%val!=0;
    int cnt=qry(x*2,l,r,val);
    if (cnt<2) cnt+=qry(x*2+1,l,r,val);
    return cnt;
}

int main()
{
    memset(c,0,sizeof(c));
    for (int i=1;i<maxn;i++)
        for (int j=1;i*j<maxn;j++)
            c[i*j]++;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&b[i]);
    build(1,1,n);
    scanf("%d",&query);
    while (query--)
    {
        int o,u,v; scanf("%d%d%d",&o,&u,&v);
        if (o==2) update(1,u,u,v);
        else {
            scanf("%d",&m);
            if (qry(1,u,v,m)<2) printf("YES\n"); else printf("NO\n");
        }
    }
    return 0;
}