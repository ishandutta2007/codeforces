#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
char c[1000001],c1[1000001];
int main()
{ scanf("%s",&c);scanf("%s",&c1);
  int len=strlen(c),len1=strlen(c1);
  if (len!=len1) printf("NO\n");
  else {
  	  int one=0,One=0;
  	   for (i=0;i<len;i++) if (c[i]=='1') one=1;
  	   for (i=0;i<len;i++) if (c1[i]=='1') One=1;
  	   if ((one^One)>0) printf("NO\n");
  	   else printf("YES\n");
  }
}