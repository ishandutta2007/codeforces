#include<cstdio>
#include<algorithm>
int i,j,m,n,ans;
int main()
{scanf("%d%d",&n,&m);
  ans=n;
  for (;n>=m;)
  {  ans+=n/m;
      n=n/m+n%m;
}
printf("%d\n",ans);
}