#include<bits/stdc++.h>
#define maxn 1000020

using namespace std;

int pre[maxn],sz[maxn],k,n,h[maxn],ans[maxn];

int ffind(int x)
{
    if (pre[x]==0||pre[x]==x) return pre[x];
    int tmp=ffind(pre[x]);
    pre[x]=tmp;
    return tmp;
}

void sub_union(int x,int y)
{
    if (h[x]==h[y]) h[x]++;
    if (h[x]>h[y]) pre[y]=x,sz[x]+=sz[y]; else pre[x]=y,sz[y]+=sz[x];
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) pre[i]=0,sz[i]=0,h[i]=0;
    ans[0]=1;
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&k);
        pre[k]=k;sz[k]=1;
        if (k>1&&ffind(k-1)!=0) sub_union(ffind(k),ffind(k-1));
        if (k<n&&ffind(k+1)!=0) sub_union(ffind(k),ffind(k+1));
        ans[i]=i+1-sz[ffind(n)];
    }
    for (int i=0;i<=n;i++) printf("%d ",ans[i]); printf("\n");
    return 0;
}