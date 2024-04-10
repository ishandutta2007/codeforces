#include<cstdio>
#include<algorithm>
#include<cstring>
int i,j,m,n,p,k;
int power(int x,int y)
{
	  int sum=1;
	  for (;y;y>>=1)
	  {
	  	 if (y&1) sum=1ll*sum*x%m;
	  	 x=1ll*x*x%m;
	  }
	  return sum;
}
int main()
{
	 scanf("%d%d",&n,&m);
	 printf("%d\n",(power(3,n)-1+m)%m);
}