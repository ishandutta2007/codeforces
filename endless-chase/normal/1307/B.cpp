#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,test,a[111111],mx,x;
bool f;
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&n,&x);
		mx=0;f=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			mx=max(mx,a[i]);
			if (a[i]==x) f=1;
		}
		if (f) printf("1\n");
		else printf("%d\n",max((x+mx-1)/mx,2));
	}
	return Accepted;
}