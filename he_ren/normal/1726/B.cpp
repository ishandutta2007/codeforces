#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	
	if(n > m)
	{
		printf("No\n");
		return;
	}
	
	if(n % 2 == 1)
	{
		printf("Yes\n");
		for(int i=1; i<n; ++i)
			printf("1 ");
		printf("%d\n",m - (n - 1));
		return;
	}
	
	if(m % 2)
	{
		printf("No\n");
	}
	else
	{
		printf("Yes\n");
		for(int i=1; i<=n-2; ++i)
			printf("1 ");
		printf("%d %d\n", (m - (n - 2)) / 2, (m - (n - 2)) / 2);
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}