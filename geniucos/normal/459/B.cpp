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
int maxi,mini,n1,n2,ai,n,i;
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
maxi=0;
mini=1000000001;
for(i=1;i<=n;i++)
{
    scanf("%d",&ai);
    if(ai>maxi) maxi=ai,n1=1;
    else
    if(ai==maxi) n1++;
    if(ai<mini) mini=ai,n2=1;
    else
    if(ai==mini) n2++;
}
if(maxi==mini) printf("0 %I64d\n",(long long)1LL*n*(n-1)/2);
else
printf("%d %I64d\n",maxi-mini,1LL*n1*n2);
return 0;
}