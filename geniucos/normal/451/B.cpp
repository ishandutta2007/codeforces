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
int st,dr,i,j,n,a[100009],b[100009];
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
for(i=1;i<n;i++)
    b[i]=(a[i]<a[i+1]);
for(i=1;i<n;i++)
    if(b[i]==0) break;
if(i==n)
{
    printf("yes\n1 1\n");
    return 0;
}
st=i;
for(j=i;j<n;j++)
    if(b[j]==1) break;
dr=j;
for(j=j;j<n;j++)
    if(b[j]==0) break;
if(j==n)
{
    reverse(a+st,a+dr+1);
    for(i=1;i<n;i++)
        if(a[i]>a[i+1]) break;
    if(i==n) printf("yes\n%d %d\n",st,dr);
    else printf("no\n");
}
else printf("no\n");
return 0;
}