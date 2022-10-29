#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 100005

using namespace std;
char c[N],s[N];
int i,j,m,n,p,k,len,A,ans;
int main()
{
	 scanf("%s",c);
	 scanf("%s",s);
	 len=strlen(c);
	 for (i=0;i<len;++i)
	 {
	    if (c[i]=='4') ++A;
	    if (s[i]=='4') --A;
	 }
	  for (j=0;j<len&&A;++j)
	    if (A>0&&c[j]=='4'&&s[j]=='7')
	       A--,c[j]='7',++ans;
	    else if (A<0&&c[j]=='7'&&s[j]=='4')
	       ++A,c[j]='4',++ans;
	  ans*=2;
	  for (j=0;j<len;++j)
	    if (c[j]!=s[j]) ++ans;
	  printf("%d\n",ans/2);
}