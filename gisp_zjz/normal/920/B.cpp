#include<bits/stdc++.h>
#define maxn 200050

using namespace std;

struct point{
    int x,y,z;
};

bool cmp(point u,point v)
{
    return u.x<v.x||(u.x==v.x&&u.z<v.z);
}

int query,n;
point a[maxn];
int ans[maxn],t,c[maxn];

int main()
{
    scanf("%d",&query);
    while (query--)
    {
        scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            scanf("%d%d",&a[i].x,&a[i].y);
            a[i].z=i;
        }
        sort(a,a+n,cmp);
        t=0;
        for (int i=0;i<n;i++)
        {
            t=max(t,a[i].x);
            if (t>a[i].y) c[i]=0;
            else c[i]=t++;
        }
        for (int i=0;i<n;i++) ans[a[i].z]=c[i];
        for (int i=0;i<n;i++) printf("%d ",ans[i]); printf("\n");
    }
    return 0;
}