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
        int x,y;
        scanf("%d%d",&x,&y);
        if(cnt[min(x,y)]==0) ans--;
        cnt[min(x,y)]++;
    }
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        int opt,x,y;
        scanf("%d",&opt);
        if(opt==3) printf("%d\n",ans);
        if(opt==1)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if(cnt[min(x,y)]==0) ans--;
            cnt[min(x,y)]++;
        }
        if(opt==2)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if(cnt[min(x,y)]==1) ans++;
            cnt[min(x,y)]--;
        }
    }
}