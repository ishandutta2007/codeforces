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
int i,j,k,n,ap[100009][2][2];
char sir[100009];
long long par,impar;
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
gets(sir+1);
n=strlen(sir+1);
for(i=1;i<=n;i++)
{
    par+=(n-i+1)/2;
    impar+=n-i+1-(n-i+1)/2;
}
for(i=n;i>=1;i--)
{
    for(j=0;j<=1;j++)
        for(k=0;k<=1;k++)
            ap[i][j][k]=ap[i+1][j][k];
    ap[i][(sir[i]=='b')][i&1]++;
}
for(i=1;i<=n;i++)
{
    if(i&1) par-=ap[i][1-(sir[i]-'a')][0],impar-=ap[i][1-(sir[i]-'a')][1];
    else par-=ap[i][1-(sir[i]-'a')][1],impar-=ap[i][1-(sir[i]-'a')][0];
}
printf("%I64d %I64d\n",par,impar);
return 0;
}