#include<cstdio>
const int MAXN = 1e3 + 5;
const int MAXM = 1e3 + 5;

struct Input
{
	int l,r;
}in[MAXM];
int incnt=0;

bool vis[MAXN];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0; i<m; ++i)
	{
		int t,l,r;
		scanf("%d%d%d",&t,&l,&r);
		if(t)
			for(int i=l; i<r; ++i) vis[i]=1;
		else
			in[incnt].l=l, in[incnt].r=r, ++incnt;
	}
	
	for(int i=0; i<incnt; ++i)
	{
		int l=in[i].l, r=in[i].r;
		bool flag=0;
		for(int j=l; j<r; ++j)
			if(!vis[j])
			{
				flag=1;
				break;
			}
		if(!flag)
		{
			printf("NO");
			return 0;
		}
	}
	
	printf("YES\n");
	int a=MAXN;
	for(int i=1; i<=n; ++i)
	{
		printf("%d ",a);
		if(vis[i]) ++a;
		else --a;
	}
	return 0;
}