#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,m,k,b[111111],c[111111],tp,ans;
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
	}
	for (int i=1;i<n;i++)
	{
		c[i]=b[i+1]-b[i]-1;
	}
	sort(c+1,c+n);
	tp=n-k;
	ans=n;
	for (int i=1;i<=tp;i++) ans+=c[i];
	printf("%d\n",ans);
	return Accepted;
}