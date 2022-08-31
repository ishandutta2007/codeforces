#include<bits/stdc++.h>
#define maxn 2030400

using namespace std;
typedef long long ll;

ll l,r,mid,k,a[20],p[20],n,f,s,t,q[20];
ll c[maxn],d[maxn],c1,c2;

ll cw(ll x)
{
    ll wx,wy,cnt,tmp;
    wx=c1-1; wy=c2-1; cnt=0;
    while (wx>=0&&c[wx]>x) wx--;
    while (wy>=0&&d[wy]>x) wy--;
    for (int i=0;i<=wx;i++)
    {
        tmp=x/c[i];
        while (wy>=0&&d[wy]>tmp) wy--;
        cnt+=(wy+1);
    }
    return cnt;
}

void dfs1(ll x,ll y,ll z)
{
    if (y==0) return;
    if (z==s) {c[c1++]=x;return;}
    ll w=1;
    dfs1(x,y,z+1);
    while (w<=y/p[z]){
        w*=p[z];
        dfs1(x*w,y/w,z+1);
    }
}

void dfs2(ll x,ll y,ll z)
{
    if (y==0) return;
    if (z==t) {d[c2++]=x;return;}
    ll w=1;
    dfs2(x,y,z+1);
    while (w<=y/q[z]){
        w*=q[z];
        dfs2(x*w,y/w,z+1);
    }
}

int main()
{
    scanf("%d",&n); c1=0;c2=0;
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n); s=0;t=0;
    for (int i=0;i<n;i++)
    {
        if (i%4==0||i%4==3) p[s++]=a[i]; else q[t++]=a[i];
    }
    l=1;r=(ll)1000000000; r=r*r;
    dfs1(1,r,0);
    dfs2(1,r,0);
    sort(c,c+c1);
    sort(d,d+c2);
    scanf("%I64d",&k);
    if (k==1){printf("1\n");return 0;}
    while (r-l>1)
    {
        mid=(l+r)>>1;
        if (cw(mid)<k) l=mid; else r=mid;
    }
    printf("%lld\n",r);
    return 0;
}