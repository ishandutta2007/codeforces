#include<cstdio>
#include<algorithm>
using namespace std;
int n,ans,a[105],b[105],l[105];
bool light(int x,int y)
{
	if(y<b[x] || ((y-b[x])/a[x])%2==1) return l[x];
	return l[x]^1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		char temp;
		scanf(" %c",&temp);
		if(temp=='1') l[i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
	}
	for(int i=0;i<=1000;i++)
	{
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(light(j,i))
			{
				cnt++;
			}
		}
//		if(cnt==6) printf("%d\n",i);
		ans=max(ans,cnt);
//		printf("%d\n",cnt);
	}
	printf("%d\n",ans);
	return 0;
}