#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,t,a[100005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		if(m<2*n) printf("-1 -1\n");
		else printf("%d %d\n",n,2*n);
	}
}