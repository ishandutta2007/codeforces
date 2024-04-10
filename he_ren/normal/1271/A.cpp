#include<cstdio>
#include<algorithm>
using namespace std;

int main(void)
{
	int a,b,c,d,e,f;
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	int ans=0;
	if(e>f)
	{
		int x = min(a,d);
		ans += e*x;
		d-=x;
		int y = min(min(b,c),d);
		ans += f*y;
	}
	else
	{
		int x = min(min(b,c),d);
		ans += f*x;
		d-=x;
		int y = min(a,d);
		ans += e*y;
	}
	printf("%d",ans);
	return 0;
}