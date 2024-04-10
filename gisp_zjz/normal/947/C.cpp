#include<bits/stdc++.h>
#define maxn 304050

using namespace std;
struct node{
    int sz,l,r;
};
node a[maxn*64];
int b[maxn],c[maxn],ans[maxn],n,p,t,k;

int main()
{
    scanf("%d",&n); a[0].l=-1; a[0].r=-1;
    for (int i=0;i<n;i++) scanf("%d",&b[i]);
    for (int i=0;i<n;i++) scanf("%d",&c[i]);
    for (int i=0;i<n;i++)
    {
        t=0;
        for (int j=29;j>=0;j--)
        {
            a[t].sz++;
            if (c[i]&(1<<j)) {
                if (a[t].r==-1) a[t].r=++p,a[p].l=-1,a[p].r=-1,t=p;
                else t=a[t].r;
            }
            else {
                if (a[t].l==-1) a[t].l=++p,a[p].l=-1,a[p].r=-1,t=p;
                else t=a[t].l;
            }
        }
        a[t].sz++;
    }
    for (int i=0;i<n;i++)
    {
        t=0;
        for (int j=29;j>=0;j--)
        {
            a[t].sz--;
            if (b[i]&(1<<j)) {
                if (a[t].r==-1||a[a[t].r].sz==0) t=a[t].l,ans[i]|=(1<<j);
                else t=a[t].r;
            }
            else {
                if (a[t].l==-1||a[a[t].l].sz==0) t=a[t].r,ans[i]|=(1<<j);
                else t=a[t].l;
            }
        }
        a[t].sz--;
    }
    for (int i=0;i<n;i++) printf("%d ",ans[i]);
    printf("\n");
    return 0;
}