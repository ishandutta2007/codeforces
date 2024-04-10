#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int i,j,m,n,p,k,a[5001],b[5001],ans,Ans,X,Gcd[5001];
int gcd(int x,int y) { return y==0?x:gcd(y,x%y);}
int Gotprime(int x)
{  int i,P=(int)sqrt(x),sum=0;
    for (i=2;i<=P;i++)
    if (x%i==0)
    {    X=lower_bound(b+1,b+m+1,i)-b;
        if (b[X]!=i) X=1; else X=-1;
        while (x%i==0) { x/=i; sum+=X;}
    }
    if (x>1) {    X=lower_bound(b+1,b+m+1,x)-b;  if (b[X]!=x) sum++; else sum--; }
  return sum;
}
int main()
{ scanf("%d%d",&n,&m);
  for (i=1;i<=n;i++) scanf("%d",&a[i]);
  for (i=1;i<=m;i++) scanf("%d",&b[i]);
  Gcd[1]=a[1];
  for (i=2;i<=n;i++) Gcd[i]=gcd(Gcd[i-1],a[i]);
  for (i=1;i<=n;i++)
   ans+=Gotprime(a[i]); 
    for (i=n;i;i--)
    {    int R=Gotprime(Gcd[i]);
         if (R<0) { ans-=R*i;
           for (j=i-1;j;j--) Gcd[j]/=Gcd[i]; }
}
printf("%d\n",ans);
}