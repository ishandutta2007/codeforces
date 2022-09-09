#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int n;
	scanf("%d",&n);
	int ans;
	scanf("%d",&ans);
	for(int i=2; i<=n; ++i)
	{
		int x;
		scanf("%d",&x);
		ans &= x;
	}
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}