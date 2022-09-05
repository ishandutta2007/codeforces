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
int n,i,V,nr,sol;
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
for(i=1;i<=n;i++)
{
    scanf("%d",&V);
    if(V!=-1) nr+=V;
    else
    {
        if(nr==0) sol++;
        else nr--;
    }
}
printf("%d\n",sol);
return 0;
}