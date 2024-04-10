#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
char a[25][25];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        for(int i=1;i<=x;i++) for(int j=1;j<=y;j++) a[i][j]=0;
        for(int i=1;i<=x;i+=2) a[i][1]=a[i][y]=1;
        for(int i=3;i<y-1;i+=2) a[1][i]=a[x][i]=1;
        for(int i=1;i<=x;i++) 
        {
            for(int j=1;j<=y;j++) 
            {
                printf("%d",a[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}