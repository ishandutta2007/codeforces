#include<bits/stdc++.h>
using namespace std;
int n,a[111111],b[111111],num[111111],pos[111111],cnt;
bool f;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		if (!num[a[i]])
		{
			cnt++;
			pos[a[i]]=cnt;
		}
		num[a[i]]=(num[a[i]]+1)%(n-a[i]);
		b[i]=pos[a[i]];
	}
	for (int i=0;i<n;i++) 
	{
		if (num[i])
		{
			f=1;
			break;
		}
	}
	if (f) printf("Impossible\n");
	else 
	{
		printf("Possible\n");
		for (int i=1;i<=n;i++) printf("%d ",b[i]);
		printf("\n");
	}
	return 0;
}