#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,p,k;
long long n,Q[100005],Min=(long long)1e18,Max;
int main()
{
	scanf("%d",&n);
	for (i=1;i*i<=n;++i)
	  if (n%i==0) Q[++Q[0]]=i,Q[++Q[0]]=n/i;
	  sort(Q+1,Q+Q[0]+1);
	for (i=1;i<=Q[0];++i)
	  for (j=1;j<=Q[0];++j)
	  {
	     if (1ll*Q[i]*Q[j]>n||n%(Q[i]*Q[j])!=0) continue;
	     Max=max(Max,(Q[i]+1)*(Q[j]+2)*(n/Q[i]/Q[j]+2)-Q[i]*Q[j]*(n/Q[i]/Q[j]));
	     Min=min(Min,(Q[i]+1)*(Q[j]+2)*(n/Q[i]/Q[j]+2)-Q[i]*Q[j]*(n/Q[i]/Q[j]));
	  }
	printf("%I64d %I64d\n",Min,Max);
}