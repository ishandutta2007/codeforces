#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int b,k,a[111111],ans;
int main()
{
	scanf("%d%d",&b,&k);
	b&=1;
	for (int i=1;i<=k;i++)
	{
		scanf("%d",&a[i]);
		a[i]&=1;
	}
	for (int i=1;i<=k;i++)
	{
		if (i==k) ans+=a[i];
		else ans+=b*a[i];
	}
	ans&=1;
	if (!ans) printf("even\n");
	else printf("odd\n");
	return Accepted;
}