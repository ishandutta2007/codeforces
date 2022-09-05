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
int sol,i,n,T,c,V,a[200009],s[200009];
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
scanf("%d",&T);
scanf("%d",&c);
for(i=1;i<=n;i++)
{
    scanf("%d",&V);
    if(V<=T) a[i]=1;
    else a[i]=0;
    s[i]=s[i-1]+a[i];
}
for(i=1;i<=n-c+1;i++)
    if(s[i+c-1]-s[i-1]==c) sol++;
printf("%d\n",sol);
return 0;
}