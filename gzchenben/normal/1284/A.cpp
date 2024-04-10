#include<cstdio>
using namespace std;
int n,m,q;
char a[25][20],b[25][20];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%s",a[i]);
	for(int i=1;i<=m;i++) scanf("%s",b[i]);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int x;
		scanf("%d",&x);
		printf("%s%s\n",a[(x-1)%n+1],b[(x-1)%m+1]);
	}
}