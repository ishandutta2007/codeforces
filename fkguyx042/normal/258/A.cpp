#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,tot;
char c[100001],c1;
int main()
 {   c1=getchar();
  while (c1!='\n') { c[tot++]=c1; c1=getchar();}
   //tot--;
 j=0;
  for (i=0;i<tot;i++)
   {  if (c[i]=='0')
       { if (j==0) j=1; else putchar('0'); }
   else { if (j==0&&i==tot-1) continue; else putchar('1');}
}
return 0;
}