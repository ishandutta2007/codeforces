#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i]);
	
	static pii p[MAXN];
	for(int i=1; i<=n; ++i)
		p[i] = {max(0, a[i-1] - a[i]), i};
	
	sort(p+1, p+n+1);
	for(int i=1; i<=n; ++i)
		printf("%d ",p[i].second);
	printf("\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}