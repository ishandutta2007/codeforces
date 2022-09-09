#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

int a[MAXN];

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	
	int ans = 0;
	static int t[MAXN];
	for(int i=1; i<=n; ++i) t[i] = d;
	for(int i=1; i<=n; ++i)
	{
		int pos = lower_bound(t+1,t+n+1,a[i]) - t;
		if(t[pos] == d) ++ans;
		t[pos] -= a[i];
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