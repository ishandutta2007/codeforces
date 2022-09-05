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
int P,i,j,T,n,m,k;
char sir[2009][2009];
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
scanf("%d",&m);
scanf("%d\n",&k);
for(i=1;i<=n;i++)
    gets(sir[i]+1);
for(j=1;j<=m;j++)
{
    T=0;
    P=0;
    for(i=2;i<=n;i++)
    {
        T++;
        if(i>T) P+=(sir[i-T][j]=='D');
        if(i+T<=n) P+=(sir[i+T][j]=='U');
        if(j+T<=m) P+=(sir[i][j+T]=='L');
        if(j>T) P+=(sir[i][j-T]=='R');
    }
    printf("%d ",P);
}
printf("\n");
return 0;
}