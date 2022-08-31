#include<bits/stdc++.h>
#define L long long
using namespace std;
int n;
L x[200010],f[200010];
int main()
{
	//freopen("mod.in","r",stdin);
	//freopen("mod.out","w",stdout);
	int i,j;
	L k,l;
	scanf("%d",&n);
	for(i=n;i>0;i--)
	  scanf("%lld",&x[i]);
	for(i=n-1;i>0;i--)
	  x[i]=min(x[i],x[i+1]);
	x[0]=1;
	for(i=1;i<=n;i++)
	  for(k=x[i],l=0;k;k%=x[j])
	    {
		 j=lower_bound(x+1,x+n,k)-x-1;
		 f[i]=max(f[i],f[j]+(L)(n-j)*(k-k%x[j]-x[j])+l);
		 l+=(L)(n-j)*(k-k%x[j]);
		}
	printf("%lld\n",f[n]);
	return 0;
}