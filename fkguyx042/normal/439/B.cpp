#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,n,p,k,v;
long long m;
int a[100001];
int main()
{ scanf("%d%d",&n,&v);
  for (i=1;i<=n;i++) 
    scanf("%d",&a[i]);
  sort(a+1,a+n+1);
  for (i=1;i<=n;i++)
   {  m+=(long long)a[i]*v;
      v--; if (v==0) v++;
}
printf("%I64d\n",m);
return 0;
}