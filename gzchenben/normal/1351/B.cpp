#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int a1,b1,a2,b2;
		scanf("%d%d%d%d",&a1,&b1,&a2,&b2);
		if(a1<b1) swap(a1,b1);
		if(a2<b2) swap(a2,b2);
		if(a1==a2 && b1+b2==a1) printf("Yes\n");
		else printf("No\n");
	}
}