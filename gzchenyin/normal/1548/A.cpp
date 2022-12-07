#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,q,cnt[200005],ans;
int main()
{
    scanf("%d%d",&n,&m);
    ans=n;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        if(u>v) swap(u,v);
        if(cnt[u]==0) ans--;
        cnt[u]++;
    }
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        int opt,u,v;
        scanf("%d",&opt);
        if(opt==3) printf("%d\n",ans);
        if(opt==1)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            if(u>v) swap(u,v);
            if(cnt[u]==0) ans--;
            cnt[u]++;
        }
        if(opt==2)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            if(u>v) swap(u,v);
            if(cnt[u]==1) ans++;
            cnt[u]--;
        }
    }
}