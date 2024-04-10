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
int i,n,maxi,a[100009],st[100009],dr[100009];
int mod(int a)
{
    if(a<0) return -a;
    return a;
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
for(i=1;i<=n;i++)
{
    if(a[i]>a[i-1]) st[i]=st[i-1]+1;
    else st[i]=1;
}
for(i=n;i>=1;i--)
{
    if(a[i]<a[i+1]) dr[i]=dr[i+1]+1;
    else dr[i]=1;
}
maxi=1;
for(i=1;i<n;i++)
    if(dr[i+1]+1>maxi) maxi=dr[i+1]+1;
for(i=2;i<=n;i++)
    if(st[i-1]+1>maxi) maxi=st[i-1]+1;
if(dr[1]>maxi) maxi=dr[1];
if(st[n]>maxi) maxi=st[n];
for(i=2;i<n;i++)
    if(a[i-1]<a[i+1]-1&&st[i-1]+dr[i+1]+1>maxi) maxi=st[i-1]+dr[i+1]+1;
printf("%d\n",maxi);
return 0;
}