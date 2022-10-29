#include<cstdio>
#include<cstring>
using namespace std;
char c[1000001];
int a[1000001],b[1000001];
int i,j,m,n,p,k,l,r;
long long ans;
int main()
 {  char x=getchar();
  while(x!='\n'&&x!=-1)c[++n]=x,x=getchar();
  for (i=1;i<=n-4;i++)
   if (c[i]=='m'&&c[i+1]=='e'&&c[i+2]=='t'&&c[i+3]=='a'&&c[i+4]=='l')
      a[++p]=i;
   else if (c[i]=='h'&&c[i+1]=='e'&&c[i+2]=='a'&&c[i+3]=='v'&&c[i+4]=='y')
     b[++k]=i;
  l=1;
  r=1;
  while (l<=p&&r<=k)
  { while (a[l]<b[r]&&l<=p) l++;
     ans+=p-l+1;
     r++;
}
printf("%I64d",ans);
return 0;
}