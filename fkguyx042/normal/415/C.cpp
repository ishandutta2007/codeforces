#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,a,b,tot;
long long x;
int gcd(int x,int y) { return y==0?x:gcd(y,x%y); }
int main()
{scanf("%d%d",&n,&k);
  if (n==1)
  {  if(k==0) printf("1\n"); else printf("-1\n");
    return 0;
}
  if (n/2>k) { printf("-1\n"); return 0;}
  p=k-n/2;
  printf("%d %d",p+1,(p+1)*2); tot=1;
  for (i=3;i<=n;i++)
  {  if (i&1)
  {
     if (p+1==tot) tot++;
     if (p+1==tot+1) tot+=2;
     if ((p+1)*2==tot+1) tot+=2;
     if ((p+1)*2==tot) tot++; }
      printf(" %d",tot); tot++;
}
}