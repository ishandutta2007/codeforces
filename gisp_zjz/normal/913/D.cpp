#include<bits/stdc++.h>
#define maxn 230402

using namespace std;
struct point{
    int x,y,z;
};

int n,l,r,t,mid,ans[maxn];
point a[maxn];

bool cmp(point u,point v)
{
    return u.x<v.x;
}

bool check(int s)
{
    int k=0; int w=0;
    for (int i=0;i<n&&k<s;i++)
        if (a[i].y>=s) w+=a[i].x,ans[k++]=a[i].z;
    return (k==s&&w<=t);
}

int main()
{
    scanf("%d",&n);scanf("%d",&t);
    for (int i=0;i<n;i++) scanf("%d%d",&a[i].y,&a[i].x);
    for (int i=0;i<n;i++) a[i].z=i+1;
    sort(a,a+n,cmp);
    l=-1; r=n+1;
    while (r-l>1)
    {
        mid=(l+r)/2;
        if (check(mid)) l=mid; else r=mid;
    }
    printf("%d\n",l);
    printf("%d\n",l);
    bool f=check(l);
    for (int i=0;i<l;i++) printf("%d ",ans[i]); printf("\n");
    return 0;
}