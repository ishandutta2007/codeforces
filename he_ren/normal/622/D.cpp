#include<cstdio>
const int MAXN = 5e5 + 5;

int a[MAXN*2];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n/2; ++i)
	{
		a[i]=a[n-i+1]=(i<<1)-1;
		a[n+i]=a[(n<<1)-i]=i<<1;
	}
	
	if(n&1)
	{
		a[(n+1)>>1]=a[n<<1]=n;
	}
	else
	{
		a[n+(n>>1)]=a[n<<1]=n;
	}
	
	for(int i=1; i<=(n<<1); ++i) printf("%d ",a[i]);
	return 0;
}