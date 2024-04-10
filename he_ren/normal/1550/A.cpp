#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

void solve(void)
{
	int n;
	scanf("%d",&n);
	
	int ans = 0;
	for(int i=1; i<=n; i+=2)
		++ans, n -= i;
	if(n) ++ans;
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}