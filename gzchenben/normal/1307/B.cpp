#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,x,t,a[100005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&x);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1);
		if(x<a[n])
		{
			bool pd=false;
			for(int i=1;i<=n;i++) 
				if(a[i]==x) pd=true;
			if(pd) printf("1\n");
			else printf("2\n");
		}
		else if(x%a[n]==0) printf("%d\n",x/a[n]);
		else printf("%d\n",(x/a[n])+1);
	}
}