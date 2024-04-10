#include<cstdio>
const int MAXN = 2e5 + 5;
const int MAXM = 1e2 + 5;
const int MAXQ = 2e5 + 5;

struct Query
{
	int t,l,r;
}qry[MAXQ];
int a[MAXN];

int main(void)
{
	int n,q,m;
	scanf("%d%d%d",&n,&q,&m);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=q; ++i) scanf("%d%d%d",&qry[i].t,&qry[i].l,&qry[i].r);
	
	while(m--)
	{
		int b;
		scanf("%d",&b);
		for(int i=q; i>=1; --i)
		{
			int t=qry[i].t, l=qry[i].l, r=qry[i].r;
			if(b<l || b>r) continue;
			if(t==1)
			{
				--b;
				if(b<l) b=r;
			}
			else b = l+r-b;
		}
		printf("%d ",a[b]);
	}
	return 0;
}