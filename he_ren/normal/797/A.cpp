#include<cstdio>
const int MAXN = 1e6 + 5;

int a[MAXN],cnt=0;

int main(void)
{
	int n,k;
	scanf("%d%d",&n,&k);
	
	for(int i=2; n>1; ++i)
	{
		while(n%i==0)
		{
			a[++cnt]=i;
			n/=i;
			if(cnt==k)
			{
				a[cnt]*=n;
				break;
			}
		}
		if(cnt==k) break;
	}
	
	if(cnt<k) printf("-1");
	else
		for(int i=1; i<=k; ++i) printf("%d ",a[i]);
	return 0;
}