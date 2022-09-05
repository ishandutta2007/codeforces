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
int sol,maxi,i,j,n,m,A[10009];
char sir[10009];
int mod(int a)
{
    if(a<0) return -a;
    return a;
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
gets(sir+1);
n=strlen(sir+1);
scanf("%d\n",&m);
for(i='a';i<='z';i++)
{
    scanf("%d",&A[i]);
    if(A[i]>maxi) maxi=A[i];
}
for(i=1;i<=n;i++)
    sol+=A[sir[i]]*i;
for(i=n+1;i<=n+m;i++)
    sol+=i*maxi;
printf("%d\n",sol);
return 0;
}