#include<cstdio>
const int MAXN = 1e3 + 5;
const int MAXM = 1e3 + 5;

char s[MAXN],t[MAXM];
int a[MAXN];

int main(void)
{
	int n,m,q;
	scanf("%d%d%d%s%s",&n,&m,&q,s+1,t+1);
	for(int i=1; i+m-1<=n; ++i)
	{
		a[i]=1;
		for(int j=1; j<=m; ++j)
			if(s[i+j-1]!=t[j])
			{
				a[i]=0;
				break;
			}
	}
	for(int i=1; i<=n; ++i) a[i]+=a[i-1];
	
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		r-=m-1;
		if(r<l) printf("0\n");
		else printf("%d\n",a[r]-a[l-1]);
	}
	return 0;
}