#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[105],ans;
bool ok[105];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(!ok[i])
		{
			ans++;
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]%a[i]==0) ok[j]=true;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}