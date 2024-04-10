#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a,b,c,t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		int ans=0;
		scanf("%d%d%d",&a,&b,&c);
		if(a)
		{
			a--;
			ans++;
		}
		if(b)
		{
			b--;
			ans++;
		}
		if(c)
		{
			c--;
			ans++;
		}
		if(a==0)
		{
			if(b && c) ans++;
			printf("%d\n",ans);
			continue;
		}
		if(b==0)
		{
			if(a && c) ans++;
			printf("%d\n",ans);
			continue;
		}
		if(c==0)
		{
			if(a && b) ans++;
			printf("%d\n",ans);
			continue;
		}
		if(a==1)
		{
			if(b+c>2) printf("%d\n",ans+2);
			else printf("%d\n",ans+1);
			continue;
		}
		if(b==1)
		{
			if(a+c>2) printf("%d\n",ans+2);
			else printf("%d\n",ans+1);
			continue;
		}
		if(c==1)
		{
			if(a+b>2) printf("%d\n",ans+2);
			else printf("%d\n",ans+1);
			continue;
		}
		if(a==2 || b==2 || c==2) printf("%d\n",ans+3);
		else printf("%d\n",ans+4);
	}
}