#include<cstdio>
using namespace std;
int n,t,a[1005][1005],F[1005][1005];
void Add(int x1,int y1,int x2,int y2)
{
    F[x1][y1]=F[x2][y2]=2;
    if(!F[x1-1][y1]) F[x1-1][y1]=1;
    if(!F[x1+1][y1]) F[x1+1][y1]=1;
    if(!F[x1][y1-1]) F[x1][y1-1]=1;
    if(!F[x1][y1+1]) F[x1][y1+1]=1;
    if(!F[x2-1][y2]) F[x2-1][y2]=1;
    if(!F[x2+1][y2]) F[x2+1][y2]=1;
    if(!F[x2][y2-1]) F[x2][y2-1]=1;
    if(!F[x2][y2+1]) F[x2][y2+1]=1;
}
void F1()
{
    for(int i=1;i<=n;i++)
    {
        if(i==1 || i==n) Add(1,i,2,i);
        else if(i%4==0) Add(1,i,1,i+1);
    }
}
void F2()
{
    for(int i=1;i<=n;i++)
    {
        if(i%4==1) Add(1,i,1,i+1);
    }
}
void work()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(F[i][j]) continue;
            if(F[i][j+1] || j==n) Add(i+1,j,i+2,j);
            else Add(i+1,j,i+1,j+1);
        }
    }
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=n;j++)
    //     {
    //         printf("%d",F[i][j]);
    //     }
    //     printf("\n");
    // }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&a[i][j]);
                F[i][j]=0;
            }
        }
        if(n%4==0)
        {
            F1();
            work();
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(F[i][j]==2) ans^=a[i][j];
                }
            }
        }
        if(n%4==2)
        {
            F2();
            work();
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(F[i][j]==2) ans^=a[i][j];
                }
            }
        }
        printf("%d\n",ans);
    }
}