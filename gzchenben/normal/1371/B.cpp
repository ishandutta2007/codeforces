#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[100005];
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(y>=x) printf("%lld\n",(long long)(x-1)*x/2+1);
		else printf("%lld\n",(long long)y*(y+1)/2);
	}
}