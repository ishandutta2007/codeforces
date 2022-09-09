#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int n;
	scanf("%d",&n);
	bool ok = 1;
	while(n--)
	{
		int x;
		scanf("%d",&x);
		if(x < 0) ok = 0;
	}
	if(ok)
	{
		printf("YES\n");
		printf("%d\n",201);
		for(int i=0; i<=200; ++i)
			printf("%d ",i);
		putchar('\n');
	}
	else printf("NO\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}