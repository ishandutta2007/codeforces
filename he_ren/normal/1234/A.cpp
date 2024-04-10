#include<cstdio>
const int MAXN = 100 + 5;

int a[MAXN];

inline void solve(void)
{
	int n;
	scanf("%d",&n);
	
	int s=0;
	for(int i=1; i<=n; ++i)
	{
		scanf("%d",&a[i]);
		s+=a[i];
	}
	
	printf("%d\n",s/n+(s%n>0));
}

int main(void)
{
	int Q;
	scanf("%d",&Q);
	while(Q--) solve();
	return 0;
}