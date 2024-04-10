#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,Min[2],Max[2];
char c[100005];
int main()
{
	 scanf("%s",c); Max[0]=Max[1]=-1; Min[0]=Min[1]=200000;
	 int len=strlen(c);
	 for (i=0;i<len-1;++i)
	   if (c[i]=='A'&&c[i+1]=='B')  Min[0]=min(Min[0],i),Max[0]=max(Max[0],i);
	   else if (c[i]=='B'&&c[i+1]=='A') Min[1]=min(Min[1],i),Max[1]=max(Max[1],i);
	 if (Max[0]==-1||Max[1]==-1||abs(Min[0]-Max[1])<=1&&abs(Min[1]-Max[0])<=1) printf("NO\n");
	 else printf("YES\n");
}