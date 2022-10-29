#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long a[1000005],b[1000005];
int l,r,t,n,i,m;
int main()
{
	 scanf("%d",&n);
	 for (i=1;i<=n;++i) scanf("%d",&a[i]),b[i]=a[i];
	 sort(b+1,b+n+1);
	 for (i=1;i<=n;++i) a[i]+=a[i-1],b[i]+=b[i-1];
	 scanf("%d",&m);
	 for (;m--;)
	 {
	 	 scanf("%d%d%d",&t,&l,&r);
	 	 if (t==1) printf("%I64d\n",a[r]-a[l-1]);
	 	 else printf("%I64d\n",b[r]-b[l-1]);
	 }
}