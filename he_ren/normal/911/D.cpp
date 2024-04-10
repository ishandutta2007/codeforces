#include<cstdio>
const int MAXN = 1500 + 5;

int a[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int ans=0;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<i; ++j)
			if(a[j]>a[i]) ans^=1;
	
	int m;
	scanf("%d",&m);
	while(m--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		int len = r-l+1;
		if(((len*(len-1))>>1) & 1) ans^=1;
		if(ans) printf("odd\n");
		else printf("even\n");
	}
	return 0;
}