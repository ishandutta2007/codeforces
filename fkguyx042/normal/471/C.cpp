#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long i,j,m,n,p,k,ans;
int main()
{  scanf("%I64d",&n);
   for (i=1;1ll*i*(3*i+1)/2ll<=n;i++)
    if ((n-1ll*i*(3*i+1)/2ll)%3==0) ans++;
printf("%I64d\n",ans);
}