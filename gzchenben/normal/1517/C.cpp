#include<cstdio>
#include<algorithm>
using namespace std;
int n,f[505],a[505][505];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&f[i]);
    }
    for(int i=1;i<=n;i++)
    {
        int nowx=i,nowy=i;
        for(int j=1;j<=f[i];j++)
        {
            a[nowx][nowy]=f[i];
            if(nowy!=1 && a[nowx][nowy-1]==0)
            {
                nowy--;
            }
            else 
            {
                nowx++;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}