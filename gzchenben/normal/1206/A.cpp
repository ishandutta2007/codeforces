#include<cstdio>
using namespace std;
int n,m,a[105],b[105];
bool book[205];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		book[a[i]]=true;
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&b[i]);
		book[b[i]]=true;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(!book[a[i]+b[j]])
			{
				printf("%d %d\n",a[i],b[j]);
				return 0;
			}
		}
	}
}