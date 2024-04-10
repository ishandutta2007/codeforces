#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 2000005
using namespace std;
int i,j,m,n,p,k;
int next[N],vis[N];
char c[N];
int main()
{
	 scanf("%s",c);
	 int ans=0,len=strlen(c);
	 for (i=len;i;--i) c[i]=c[i-1];
	 for (i=2,j=0;i<=len;++i)
	 {
	 	  while (j&&c[j+1]!=c[i]) j=next[j];
	 	  if (c[j+1]==c[i]) ++j;
	 	  next[i]=j;
	 }
	  j=next[len];
	 while (j) vis[j]=1,j=next[j];
	 for (i=2;i<len;++i)
	   if (vis[next[i]]) ans=max(ans,next[i]);
	if (ans)
	{
		  for (i=1;i<=ans;++i) printf("%c",c[i]);
	}
	else printf("Just a legend\n");
}