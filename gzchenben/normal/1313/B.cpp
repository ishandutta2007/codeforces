#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,x,y,t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&x,&y);
		printf("%d %d\n",max(n-max((n-x)+(n-y)-1,0),1),min(x+y-1,n));
	}
}