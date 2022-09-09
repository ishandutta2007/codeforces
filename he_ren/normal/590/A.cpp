#include<cstdio>
const int MAXN = 5e5 + 5;

int a[MAXN];

int main(void)
{
	//freopen("A.in","r",stdin);
	//freopen("A.out","w",stdout);
	
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int ans=0;
	for(int l=1,r=1; r<=n; l=r)
	{
		++r;
		while(r<=n && a[r]!=a[r-1]) ++r;
		
		int tmp = (r-l-1)>>1;
		if(ans < tmp) ans=tmp;
		
		if(a[l]==a[r-1])
			for(int i=l; i<r; ++i) a[i]=a[l];
		else
		{
			int mid = (r-l)>>1;
			for(int i=1; i<=mid; ++i)
				a[l+i-1]=a[l], a[r-i]=a[r-1];
		}
	}
	
	printf("%d\n",ans);
	for(int i=1; i<=n; ++i) printf("%d ",a[i]);
	return 0;
}