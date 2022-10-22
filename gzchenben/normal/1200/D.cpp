#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,ans,f[2005][2005];
char a[2005][2005];
void Add(int x1,int x2,int y1,int y2)
{
    x1=max(x1,1); y1=max(y1,1);
    x2=min(x2,n-k+1); y2=min(y2,n-k+1);
    for(int i=x1;i<=x2;i++)
    {
        f[i][y1]++;
        f[i][y2+1]--;
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf(" %c",&a[i][j]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        int L=n+1,R=0;
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]=='B') 
            {
                L=min(L,j);
                R=max(R,j);
            }
        }
        if(R==0) Add(1,n-k+1,1,n-k+1);
        else if(R-L+1<=k) Add(i-k+1,i,R-k+1,L);
    }
    for(int j=1;j<=n;j++)
    {
        int L=n+1,R=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i][j]=='B') 
            {
                L=min(L,i);
                R=max(R,i);
            }
        }
        if(R==0) Add(1,n-k+1,1,n-k+1);
        else if(R-L+1<=k) Add(R-k+1,L,j-k+1,j);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            f[i][j]+=f[i][j-1];
            ans=max(ans,f[i][j]);
        }
    }
    printf("%d\n",ans);
}