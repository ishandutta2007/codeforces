#include<cstdio>
#include<cstring>
using namespace std;
int n,m,t,a[100005];
bool f[1005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		memset(f,false,sizeof(f));
		int x;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			f[x]=true;
		}
		bool flag=false;
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&x);
			if(f[x] && !flag) 
			{
				printf("YES\n1 %d\n",x);
				flag=true;
			}
		}
		if(flag==false) printf("NO\n");
	}
}