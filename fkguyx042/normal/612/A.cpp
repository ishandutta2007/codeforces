#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char c[10005];
int n,p,q,i,j,k,l;
int main()
{
	 scanf("%d%d%d",&n,&p,&q);
	 scanf("%s",c);
	 for (i=0;i<=n/p;++i)
	     for (j=0;j<=n/q;++j)
	       if (i*p+j*q==n)
	       {
	       	     printf("%d\n",i+j);
	       	     int cnt=0;
	       	     for (k=1;k<=i;++k)
	       	     { 
	       	         for (l=1;l<=p;++l) printf("%c",c[cnt++]);
	       	     puts("");
	       	     }
	       	     for (k=1;k<=j;++k)
	       	     {
	       	         for (l=1;l<=q;++l) printf("%c",c[cnt++]);
	       	     puts("");
	       	     }
	       	     exit(0);
	       }
	puts("-1");
}