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
int i,n,a[1000009];
long long s[1000009];
long long calc(int i,int j)
{
    if(i==j) return a[i];
    if(i>j) return 0;
    return s[j]-s[i-1]+calc(i,i)+calc(i+1,j);
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
sort(a+1,a+n+1);
for(i=1;i<=n;i++)
    s[i]=s[i-1]+a[i];
printf("%I64d\n",calc(1,n));
return 0;
}