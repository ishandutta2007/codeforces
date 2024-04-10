#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int t,n,a[300001],p[300001],pre[300001],ans[300001];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(p,0,sizeof p);
        memset(pre,0,sizeof pre);
        for(register int i=1;i<=n;++i)
        {
            scanf("%d",&a[i]);
            pre[i]=p[a[i]];
            p[a[i]]=i;
        }
        memset(ans,0x3f,sizeof ans);
        for(register int i=1;i<=n;++i)
            if(p[a[i]]==i)
            {
                int maxn=n-p[a[i]]+1;
                for(register int j=p[a[i]];j;j=pre[j])
                    maxn=max(maxn,j-pre[j]);
                ans[maxn]=min(ans[maxn],a[i]);
            }
        printf("%d ",ans[1]==ans[0]? -1:ans[1]);
        for(register int i=2;i<=n;++i)
        {
            ans[i]=min(ans[i-1],ans[i]);
            printf("%d ",ans[i]==ans[0]? -1:ans[i]);
        }
        puts("");
    }
    return 0;
}