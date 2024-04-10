#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[100005];
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		int x;
		scanf("%d",&x);
		printf("%d\n",(x+1)/2);
	}
}