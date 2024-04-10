#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 2005

using namespace std;
int i,j,m,n,p,k,len,sum,ans=10000;
char c[N],s[N],r[N*10];
int main()
{
	  scanf("%s",c);
	  scanf("%s",s);
	  for (i=1;i<=strlen(s);++i) r[len++]=0;
	  for (i=1;i<=strlen(c);++i) r[len++]=c[i-1];
	  for (i=1;i<=strlen(s);++i) r[len++]=0;
	  int Len=strlen(s);
	  for (i=0;i<len;++i)
	    if (i+Len-1<len)
	    {
	    	 sum=0;
	    	 for (j=0;j<Len;++j)
	    	   if (r[i+j]!=s[j]) ++sum;
	    	 ans=min(ans,sum);
	    }
	 printf("%d\n",ans);
}