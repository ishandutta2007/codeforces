
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define maxn 600005

using namespace std;
struct seg{
    int l,r,s,f,len;
};
seg a[maxn*4];
int n,query,l[maxn],r[maxn],k[maxn],u[maxn],cnt,p,v[maxn];
unordered_map <int,int> m;

void build(int p,int l,int r)
{
    a[p].l=l; a[p].r=r; a[p].f=-1;
    if (l==r) {a[p].s=a[p].len=v[l]-v[l-1];return;}
    int mid=(l+r)>>1;
    build(p<<1,l,mid);
    build((p<<1)|1,mid+1,r);
    a[p].s=a[p<<1].s+a[(p<<1)|1].s;
    a[p].len=a[p].s;
}

void pass(int p)
{
    if (a[p].f==-1) return;
    a[p].s=a[p].f?a[p].len:0;
    if (a[p].l<a[p].r) {
        a[p<<1].f=a[p].f;
        a[(p<<1)|1].f=a[p].f;
    }
    a[p].f=-1;
}

void update(int p,int l,int r,bool o)
{
    if (a[p].l>r||a[p].r<l) {pass(p); return;}
    if (a[p].l>=l&&a[p].r<=r) {
        a[p].f=o; pass(p);
        return;
    }
    pass(p);
    update(p<<1,l,r,o);
    update((p<<1)|1,l,r,o);
    a[p].s=a[p<<1].s+a[(p<<1)|1].s;
}

int main()
{
    scanf("%d%d",&n,&query);
    u[cnt++]=0; u[cnt++]=n;
    for (int i=0;i<query;i++)
    {
        scanf("%d%d%d",&l[i],&r[i],&k[i]); l[i]--; k[i]--;
        u[cnt++]=l[i]; u[cnt++]=r[i];
    }
    sort(u,u+cnt); m[0]=0;
    for (int i=1;i<cnt;i++) if (u==0||u[i]>u[i-1]) m[u[i]]=++p,v[p]=u[i];
    build(1,1,p);
    for (int i=0;i<query;i++)
    {
        update(1,m[l[i]]+1,m[r[i]],k[i]);
        printf("%d\n",a[1].s);
    }
    return 0;
}