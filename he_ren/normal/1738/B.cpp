#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

ll s[MAXN];

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=n-d+1; i<=n; ++i)
		scanf("%lld",&s[i]);
	
	if(d == 1)
	{
		printf("Yes\n");
		return;
	}
	
	for(int i=n; i>=n-d+2; --i)
		s[i] -= s[i-1];
	
	for(int i=n-d+3; i<=n; ++i)
		if(s[i] < s[i-1])
		{
			printf("No\n");
			return;
		}
	
	if(s[n-d+1] <= s[n-d+2] * (n-d+1))
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}