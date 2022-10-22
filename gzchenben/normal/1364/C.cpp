#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int n,a[100005],b[100005],st[100005],top;
int main()
{
	memset(b,-1,sizeof(b));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		st[++top]=i;
		while(a[i-1]!=a[i])
		{
//			printf("--%d\n",st[top]);
			b[st[top]]=a[i-1];
			a[i-1]++;
			top--;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==-1) printf("100001 ");
		else printf("%d ",b[i]);
	}
	printf("\n");
}