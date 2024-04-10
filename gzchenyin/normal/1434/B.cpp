#include<cstdio>
#include<algorithm>
using namespace std;
int n,pos[100005],nxt[200005],pre[200005],List[200005],cnt,ans[100005];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++)
    {
        char opt;
        int x;
        scanf(" %c",&opt);
        if(opt=='+') List[i]=-(++cnt);
        else
        {
            scanf("%d",&x);
            List[i]=x;
            pos[x]=i;
        }
        nxt[i]=i+1;
        pre[i]=i-1;
    }
    for(int i=1;i<=n;i++)
    {
        if(List[pre[pos[i]]]>=0)
        {
            printf("NO\n");
            return 0;
        }
        ans[-List[pre[pos[i]]]]=i;
        pre[nxt[pos[i]]]=pre[pre[pos[i]]];
        nxt[pre[pre[pos[i]]]]=nxt[pos[i]];
    }
    printf("YES\n");
    for(int i=1;i<=n;i++)
    {
        printf("%d ",ans[i]);
    }
    printf("\n");
}