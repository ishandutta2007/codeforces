#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,test,a[1111],b[1111];
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<=n;i++) scanf("%d",&b[i]);
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		for (int i=1;i<=n;i++) printf("%d ",a[i]);
		printf("\n");
		for (int i=1;i<=n;i++) printf("%d ",b[i]);
		printf("\n");
	}
	return Accepted;
}