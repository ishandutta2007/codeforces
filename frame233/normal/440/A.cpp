#include<cstdio>
bool used[100005];
int main()
{
	int n,x;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&x);
		used[x]=1;
	}
	for(int i=1;i<=n;++i)
	{
		if(!used[i])
		{
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}
//Dpair ak IOI
//Dpair bless me