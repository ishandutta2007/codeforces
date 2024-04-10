#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,t,b[105][105];
int checkmin()
{
    int minn=0;
    b[0][1]=1000000001;
    for(int i=1;i<=n;i++)
    {
        if(b[i][1]<b[minn][1]) minn=i;
    }
    return minn;
}
void turn(int x,int y)
{
    int tmp=b[x][1];
    for(int i=1;i<y;i++) b[x][i]=b[x][i+1];
    b[x][y]=tmp;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&b[i][j]);
            }
        }
        for(int i=1;i<=n;i++)
        {
            sort(b[i]+1,b[i]+m+1);
        }
        for(int i=m;i>=1;i--)
        {
            int x=checkmin();
            turn(x,i);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                printf("%d ",b[i][j]);
            }
            printf("\n");
        }
    }
}