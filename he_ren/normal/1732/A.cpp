#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

inline int gcd(int a,int b){ return b? gcd(b,a%b): a;}

void solve(void)
{
	int n;
	scanf("%d",&n);
	int k = 0;
	for(int i=1; i<=n; ++i)
	{
		int x;
		scanf("%d",&x);
		k = gcd(k, x);
	}
	
	if(k == 1)
	{
		printf("0\n");
	}
	else if(n == 1)
	{
		printf("1\n");
	}
	else
	{
		int ans = 3;
		if(gcd(k, n) == 1) ans = min(ans, 1);
		if(gcd(k, n-1) == 1) ans = min(ans, 2);
		printf("%d\n",ans);
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}