#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int n,a[400001],b[400001],cnt,tot,ans,l,r,num[400001];
map<int,int> vis;
pair<int,int> c[400001];
int main()
{
    scanf("%d",&n);
    tot=n;
    for(register int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(register int i=1;i<=n;++i)
    {
        if(a[i]^a[i-1])
            ++cnt;
        b[i]=cnt;
        vis[b[i]]=a[i];
    }
    for(register int i=1;i<=cnt;++i)
        c[i].second=i;
    for(register int i=1;i<=n;++i)
        ++c[b[i]].first;
    sort(c+1,c+cnt+1);
    for(register int i=n;i>=1;--i)
    {
        for(register int j=cnt;j&&c[j].first>i;--j)
        {
            --c[j].first;
            --tot;
        }
        int p=tot/i;
        if(p<i)
            continue;
        if(ans<p*i)
        {
            ans=p*i;
            l=i;
            r=p;
        }
    }
    for(register int i=1;i<=cnt;++i)
    {
        c[i].first=0;
        c[i].second=i;
    }
    for(register int i=1;i<=n;++i)
        ++c[b[i]].first;
    printf("%d\n%d %d\n",ans,l,r);
    sort(c+1,c+cnt+1);
    for(register int i=cnt;i>=1;--i)
        if(c[i].first>=l)
            c[i].first=l;
        else
            break;
    int p=cnt;
    for(register int i=1;i<=r;++i)
        for(register int j=1;j<=l;++j)
        {
            if(!c[p].first)
                --p;
            num[(j-1)*r+(i+j)%r+1]=vis[c[p].second];
            --c[p].first;
        }
    for(register int i=1;i<=ans;++i)
    {
        printf("%d ",num[i]);
        if(i%r==0)
            puts("");
    }
    return 0;
}