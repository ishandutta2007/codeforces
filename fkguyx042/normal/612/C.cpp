#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair

#define N 1000005
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,top,ans;
char c[N],stack[N];
int a[N],b[N];
void Re()
{
	 printf("Impossible\n");
	 exit(0);
}
int main()
{
	  scanf("%s",c); a['{']=a['(']=a['<']=a['[']=1; a['}']='{'; a[']']='['; a[')']='('; a['>']='<';
	  n=strlen(c);
	  for (i=0;i<n;++i) 
	  {
	  	  if (a[c[i]]==1) stack[++top]=c[i];
	  	  else 
	  	  {
	  	  	   if (!top) Re();
	  	  	   if (a[c[i]]!=stack[top]) ++ans;
	  	  	   --top;
	  	  }
	  }
	  if (top) Re();
	  printf("%d\n",ans);
}