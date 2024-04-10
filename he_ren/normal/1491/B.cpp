#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e2 + 5;

int a[MAXN];

void solve(void)
{
	int n,u,v;
	scanf("%d%d%d",&n,&u,&v);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int ans = u + v;
	for(int i=1; i<n; ++i)
	{
		if(abs(a[i] - a[i+1]) > 1) ans = 0;
		if(abs(a[i] - a[i+1]) == 1) ans = min(ans, min(u,v));
		else ans = min(ans, v + min(u,v));
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