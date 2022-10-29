#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int Mo=1000000007;
int i,j,m,n,p,k,ans,tp;
char c[1001];
int power(int x,int y)
{ int sum=1;
    for (;y;y>>=1)
   {  if (y&1) sum=1ll*sum*x%Mo;
      x=1ll*x*x%Mo; }
    return sum; }
int main()
{ scanf("%s",&c);
for (i=strlen(c),tp=1;i;i--,tp++)
 if (i==strlen(c))
 {  if (c[i-1]=='1') ans=1; else ans=0; }
else {   
   if (c[i-1]=='0')
    ans=ans*2%Mo;
    else ans=(ans*2%Mo+power(2,2*tp-2))%Mo;
}
printf("%d\n",ans);
}