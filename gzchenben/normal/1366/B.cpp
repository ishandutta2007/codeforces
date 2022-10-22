#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,m,x,l[105],r[105];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&x,&m);
		int lx=x,rx=x;
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&l[i],&r[i]);
			if(l[i]>rx || r[i]<lx) continue;
			lx=min(lx,l[i]);
			rx=max(rx,r[i]);
		}
		printf("%d\n",rx-lx+1);
	}
}