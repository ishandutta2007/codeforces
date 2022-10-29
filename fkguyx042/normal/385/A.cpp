#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,Max,c,a[100005];
int main()
{
	 scanf("%d%d",&n,&c);
	 for (i=1;i<=n;++i) 
	 {
	   scanf("%d",&a[i]);
	   if (i>1) Max=max(Max,a[i-1]-a[i]-c);
     }
     printf("%d",Max);
 }