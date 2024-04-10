#include<cstdio>
#include<algorithm>
using namespace std;
int n,ans,a[105],removed[105];
int nxt(int x)
{
	x++;
	while(removed[x] && x<=n)
	{
		x++;
	}
	return x;
}
int pre(int x)
{
	x--;
	while(removed[x] && x>=1)
	{
		x--;
	}
	return x;
}
int main()
{
	scanf("%d",&n);
	a[0]=a[n+1]=-1;
	for(int i=1;i<=n;i++) 
	{
		char tmp;
		scanf(" %c",&tmp);
		a[i]=tmp-'a'+1;
	}
	for(int i=26;i>=1;i--)
	{
		bool flag=false;
		while(!flag)
		{
			flag=true;
			for(int j=1;j<=n;j++)
			{
				if(a[j]!=i || removed[j]) continue;
				if(a[pre(j)]==i-1 || a[nxt(j)]==i-1)
				{
					flag=false;
					removed[j]=true;
					ans++;
				}
			}
		}
	}
	printf("%d\n",ans);
}