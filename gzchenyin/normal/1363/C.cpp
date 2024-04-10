#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,x;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&x);
		int cnt=0;
		for(int i=1;i<=n-1;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			if(u==x || v==x) cnt++;
		}
		if(cnt<=1 || n%2==0) printf("Ayush\n");
		else printf("Ashish\n");
	}
}