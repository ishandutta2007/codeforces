#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

inline int gcd(int a,int b){ return b? gcd(b,a%b): a;}

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int ans = 0;
	for(int i=0; i<=31; ++i)
	{
		int cnt = 0;
		for(int j=1; j<=n; ++j)
			if((a[j]>>i)&1) ++cnt;
		ans = gcd(ans, cnt);
	}
	if(ans)
	{
		for(int i=1; i<=ans; ++i)
			if(ans % i == 0)
			{
				printf("%d ",i);
			}
		printf("\n");
	}
	else
	{
		for(int i=1; i<=n; ++i)
			printf("%d ",i);
		printf("\n");
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}