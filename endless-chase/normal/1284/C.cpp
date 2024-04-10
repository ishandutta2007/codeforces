#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,jc[333333],md,ans;
int main()
{
	scanf("%d%d",&n,&md);
	jc[0]=1;
	for (int i=1;i<=n;i++) jc[i]=1ll*jc[i-1]*i%md;
	for (int i=1;i<=n;i++)
	{
		ans=(1ll*(n-i+1)*(n-i+1)%md*jc[i]%md*jc[n-i]+ans)%md;
	}
	printf("%d\n",(ans+md)%md);
	return Accepted;
}