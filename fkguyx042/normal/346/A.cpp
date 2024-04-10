#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
int Gcd;
int gcd(int a,int b){ if (!a||!b) return a+b; return gcd(b,a%b);}
int main()
{ scanf("%d",&n);
  for (i=1;i<=n;i++)
 { scanf("%d",&p);
   Gcd=gcd(Gcd,p);
   k=max(k,p);
  }
  if ((k/Gcd-n)%2==1) printf("Alice\n");
  else printf("Bob\n");
}