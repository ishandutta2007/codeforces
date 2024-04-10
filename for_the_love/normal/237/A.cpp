#include <cstdio>
#include <cstring>

int n,i,x,y,ans;
int v[100][100];
int main()
{
        scanf("%d",&n);
        for (i=1;i<=n;i++)
        {
                scanf("%d%d",&x,&y);
                v[x][y]++; if (v[x][y]>ans) ans=v[x][y];
        }
        printf("%d\n",ans);
        return 0;
}