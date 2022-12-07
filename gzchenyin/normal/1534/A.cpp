#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,t;
char a[55][55];
int flag;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        bool ok=true;
        flag=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf(" %c",&a[i][j]);
                if(a[i][j]=='R' && (i+j)%2==1)
                {
                    if(flag==0) flag=1;
                    if(flag==2) ok=false;
                }
                if(a[i][j]=='R' && (i+j)%2==0)
                {
                    if(flag==0) flag=2;
                    if(flag==1) ok=false;
                }
                if(a[i][j]=='W' && (i+j)%2==0)
                {
                    if(flag==0) flag=1;
                    if(flag==2) ok=false;
                }
                if(a[i][j]=='W' && (i+j)%2==1)
                {
                    if(flag==0) flag=2;
                    if(flag==1) ok=false;
                }
            }
        }
        if(!ok)
        {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        if(flag==0 || flag==1)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    if((i+j)%2==1) printf("R");
                    else printf("W");
                }
                printf("\n");
            }
        } 
        if(flag==2)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    if((i+j)%2==0) printf("R");
                    else printf("W");
                }
                printf("\n");
            }
        } 
    }
}