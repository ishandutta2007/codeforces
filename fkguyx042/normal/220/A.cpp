#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,w;
int a[100001],b[100001];
inline bool cmp(int a,int b) {return a>b;}
inline void Check()
{   printf("YES\n");
}
int main()
{ scanf("%d",&n);
  for (i=1;i<=n;i++) scanf("%d",&a[i]);
  for (i=2;i<=n;i++) 
   if(a[i]<a[i-1]) w=1;
   if (!w) Check();
else {
	 memcpy(b,a,sizeof(b));
	 sort(b+1,b+n+1);
	 for (i=1;i<=n;i++)
	 if (a[i]!=b[i]) k++;
	 if (k!=2) printf("NO\n");
	 else printf("YES\n");
}
}