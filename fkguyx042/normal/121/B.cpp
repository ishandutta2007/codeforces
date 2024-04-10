#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
char c[100005];
int main()
{
	 scanf("%d%d",&n,&k);
	 scanf("%s",c);
	 for (i=n;i;--i) c[i]=c[i-1];
	 c[0]=0;
	 for (i=1;i<n&&k;++i)
	   if (c[i]=='4'&&c[i+1]=='7')
	{
		   if (i&1) 
		   {
		   	   c[i+1]='4'; --k;
		   }
		   else 
		   {
		   	   if (c[i-1]=='4')
		   	  {
		   	  	   if (k&1) c[i]=c[i+1]='7';
		   	  	   break;
		   	  }
		   	  else 
		   	  {
		   	  	  c[i]='7'; --k;
	          }
	       }
	}
	for (i=1;i<=n;++i) printf("%c",c[i]);
}