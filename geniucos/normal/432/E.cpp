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
int p,car,x,y,n,m,i,j,k,ap[2009],a[109][109];
int maibine(int i,int j)
{
    int p;
    ap[a[i-1][j]]++;
    ap[a[i][j+1]]++;
    ap[a[i][j-1]]++;
    ap[a[i+1][j]]++;
    for(p='A';p<='Z';p++)
        if(ap[p]==0) break;
    ap[a[i-1][j]]--;
    ap[a[i][j+1]]--;
    ap[a[i][j-1]]--;
    ap[a[i+1][j]]--;
    return p;
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
scanf("%d",&m);
for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    if(a[i][j]==0)
    {
        if(i==12&&j==19)
            car=0;
        car=maibine(i,j);
        for(k=1;i+k-1<=n&&j+k-1<=m;k++)
        {
            for(x=i;x<i+k-1;x++)
                if(a[x][j+k-1]!=0||a[x][j+k]==car) break;
            if(x<i+k-1) break;
            for(y=j;y<j+k-1;y++)
                if(a[i+k-1][y]!=0||a[i+k][y]==car) break;
            if(y<j+k-1) break;
            if(a[i+k-1][j+k-1]!=0||a[i-1][j+k-1]==car) break;
            ////le-am verificat sa nu fie 0 si sa n-aiba vecini == car
            if(maibine(i,j+k-1)<car&&a[i][j+k-1]==0) break;
            for(x=i;x<=i+k-1;x++)
                a[x][j+k-1]=car;
            for(y=j;y<=j+k-1;y++)
                a[i+k-1][y]=car;
        }
        /*for(x=1;x<=n;x++)
        {
            for(y=1;y<=m;y++)
                printf("%c",a[x][y]);
            printf("\n");
        }
        printf("\n\n");*/
    }
for(i=1;i<=n;i++)
{
    for(j=1;j<=m;j++)
        printf("%c",a[i][j]);
    printf("\n");
}
return 0;
}