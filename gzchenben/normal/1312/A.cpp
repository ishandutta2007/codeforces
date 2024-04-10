#include<cstdio>
#include<algorithm>
using namespace std;
int n,x,y;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		if(x%y==0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}