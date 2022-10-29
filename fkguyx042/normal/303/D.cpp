#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>

#define N 200005

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

using namespace std;
int i,j,m,n,p,k,Q[N];
int power(int x,int y)
{
	  int sum=1;
	  for (;y;y>>=1,x=1ll*x*x%n) if (y&1) sum=1ll*sum*x%n;
	  return sum;
}
bool check(int x)
{
	 int p=n-1,i;
	 for (i=1;i*i<=p;++i) if (p%i==0)
	 {
	 	  if (i<p&&power(x,i)==1) return 0;
	 	  if (p/i<p&&power(x,p/i)==1) return 0;
	 }
	 return 1;
}
int main()
{
	 scanf("%d%d",&n,&k);
	 n++;
	 for (i=2;i*i<=n;++i) if (n%i==0)
	 {
	 	  puts("-1");
	      return 0;
	 }
	 for (--k;k>1;--k) if (check(k))
	 {
	 	  printf("%d\n",k);
	 	  return 0;
	 }
	 printf("-1\n");
}