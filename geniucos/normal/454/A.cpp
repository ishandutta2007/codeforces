#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<cmath>
#include<queue>
#include<set>
#include<algorithm>
#include<ctime>
#include<string>
using namespace std;
int i,j,n,st,dr,a[109][109];
int mod(int x)
{
    if(x<0) return -x;
    return x;
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
st=dr=n/2+1;
for(i=1;i<=n/2;i++)
{
    for(j=st;j<=dr;j++)
        a[i][j]=1;
    st--;
    dr++;
}
for(i=n/2+1;i<=n;i++)
{
    for(j=st;j<=dr;j++)
        a[i][j]=1;
    st++;
    dr--;
}
for(i=1;i<=n;i++,printf("\n"))
    for(j=1;j<=n;j++)
    {
        if(a[i][j]) printf("D");
        else printf("*");
    }
return 0;
}