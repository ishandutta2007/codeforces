#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,x,c[100001],ans=1;
char s;
int Mod(int x)
{ int sum=0;
  for (i=1;i<=c[0];i++)
   sum=(sum*10+c[i])%x;
   return sum;
}
int get4(int x)
{ if (!x) return 1;
  if (x==1) return 4;
}
int get3(int x)
{ if (!x) return 1;
  if (x==1) return 3;
  if (x==2) return 4;
  if (x==3) return 2;
}
int get2(int x)
{ if (!x) return 1;
  if (x==1) return 2;
  if (x==2) return 4;
  if (x==3) return 3;
}
int main()
{  for (s=getchar();s!='\n';s=getchar()) c[++c[0]]=s-'0';
   x=c[c[0]]%2;
   ans+=get4(x);
   x=Mod(4);
   ans+=get3(x);
   ans+=get2(x);
   printf("%d\n",ans%5);
}