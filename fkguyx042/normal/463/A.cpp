#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,a,b,s,Max;
int main()
{ Max=-1;
  scanf("%d%d",&n,&s);
  for (i=1;i<=n;i++)  {
    scanf("%d%d",&a,&b);
      if (a*100+b<=s*100)
      Max=max(Max,(100-b)%100);
}
printf("%d\n",Max);
}