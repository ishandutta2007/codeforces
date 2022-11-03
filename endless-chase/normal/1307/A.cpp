#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,test,d,a[111],lst,ans;
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&n,&d);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		lst=d;ans=a[1];
		for (int i=2;i<=n;i++)
		{
			while(lst>=i-1 && a[i])
			{
				lst-=(i-1);
				a[i]--;
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return Accepted;
}