#include<cstdio>
#include<algorithm>
using namespace std;
int n,s;
int main()
{
	scanf("%d%d",&n,&s);
	if(n*2>s)
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for(int i=1;i<n;i++) printf("2 ");
	printf("%d\n",s-n*2+2);
	printf("1\n");
	
}