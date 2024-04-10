#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<cmath>
#include<queue>
#include<set>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;
int maxi,nr,Q,n,m,tip,i,j,x,y,up[1009][1009],d[1009][1009],l[1009][1009],r[1009][1009],a[1009][1009],ST[1009],DR[1009],stiva[1009],b[1009];
void remakecol(int j)
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(a[i][j]==0) up[i][j]=0;
        else up[i][j]=up[i-1][j]+1;
    }
    for(i=n;i>=1;i--)
    {
        if(a[i][j]==0) d[i][j]=0;
        else d[i][j]=d[i+1][j]+1;
    }
}
void remakerow(int i)
{
    int j;
    for(j=1;j<=m;j++)
    {
        if(a[i][j]==0) l[i][j]=0;
        else l[i][j]=l[i][j-1]+1;
    }
    for(j=m;j>=1;j--)
    {
        if(a[i][j]==0) r[i][j]=0;
        else r[i][j]=r[i][j+1]+1;
    }
}
void maxim(int n,int pozl)
{
    ////am sirul b
    nr=0;
    for(i=1;i<=n;i++)
    {
        while(nr&&b[stiva[nr]]>=b[i]) nr--;
        if(nr==0) ST[i]=1;
        else ST[i]=stiva[nr]+1;
        stiva[++nr]=i;
    }
    nr=0;
    for(i=n;i>=1;i--)
    {
        while(nr&&b[stiva[nr]]>=b[i]) nr--;
        if(nr==0) DR[i]=n;
        else DR[i]=stiva[nr]-1;
        stiva[++nr]=i;
    }
    for(i=1;i<=n;i++)
    {
        if(pozl<ST[i]||pozl>DR[i]) continue;
        if((DR[i]-ST[i]+1)*b[i]>maxi) maxi=(DR[i]-ST[i]+1)*b[i];
    }
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
scanf("%d",&m);
scanf("%d",&Q);
for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
        scanf("%d",&a[i][j]);
for(i=1;i<=n;i++)
    remakerow(i);
for(j=1;j<=m;j++)
    remakecol(j);
while(Q)
{
    Q--;
    scanf("%d",&tip);
    if(tip==1)
    {
        scanf("%d",&i);
        scanf("%d",&j);
        a[i][j]^=1;
        remakecol(j);
        remakerow(i);
        continue;
    }
    else
    {
        scanf("%d",&x);
        scanf("%d",&y);
        maxi=0;
        if(a[x][y]==0)
        {
            printf("0\n");
            continue;
        }
        for(i=1;i<=n;i++)
            b[i]=l[i][y];
        maxim(n,x);
        for(i=1;i<=n;i++)
            b[i]=r[i][y];
        maxim(n,x);
        for(j=1;j<=m;j++)
            b[j]=up[x][j];
        maxim(m,y);
        for(j=1;j<=m;j++)
            b[j]=d[x][j];
        maxim(m,y);
        printf("%d\n",maxi);
    }
}
return 0;
}