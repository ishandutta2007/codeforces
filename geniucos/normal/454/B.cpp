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
int i,j,n,nr,a[100009],b[100009];
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
for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
for(i=1;i<n;i++)
    if(a[i]>a[i+1]) break;
if(i==n)
{
    printf("0\n");
    return 0;
}
i++;
for(j=i;j<=n;j++)
    b[++nr]=a[j];
for(j=1;j<i;j++)
    b[++nr]=a[j];
for(j=1;j<nr;j++)
    if(b[j]>b[j+1]) break;
if(j==nr) printf("%d\n",n-i+1);
else printf("-1\n");
return 0;
}