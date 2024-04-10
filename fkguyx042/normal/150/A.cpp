#include<cstdio>
#include<algorithm>
using namespace std;
int i,j;
long long Q[1005],n;
int main()
{
	 scanf("%I64d",&n);
	 for (i=2;1ll*i*i<=n;++i)
	   while (n%i==0) Q[++Q[0]]=i,n/=i;
	 if (n>1) Q[++Q[0]]=i;
	 if (Q[0]<=1) printf("1\n0\n");
	 else if (Q[0]==2) printf("2\n");
	 else printf("1\n%I64d\n",1ll*Q[1]*Q[2]);
}