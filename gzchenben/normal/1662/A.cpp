#include<cstdio>
#include<algorithm>

using namespace std;

int a[20];

int main()
{
	int T=0;scanf("%d",&T);
	while(T--)
	{
		int n=0;scanf("%d",&n);
		for(int i=1;i<=10;i++)a[i]=0;
		for(int i=1,b=0,d=0;i<=n;i++)
		{
			scanf("%d%d",&b,&d);a[d]=max(a[d],b);
		}
		int sum=0;bool fl=1;
		for(int i=1;i<=10;i++){if(!a[i]){fl=0;break;}sum+=a[i];}
		if(fl)printf("%d\n",sum);else puts("MOREPROBLEMS");
	}
}