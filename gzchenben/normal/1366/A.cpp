#include<cstdio>
#include<algorithm>
using namespace std;
int t,a,b;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",min(min(a,b),(a+b)/3));
	}
}