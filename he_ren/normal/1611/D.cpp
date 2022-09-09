#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

int b[MAXN], p[MAXN], pos[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&b[i]);
	for(int i=1; i<=n; ++i) scanf("%d",&p[i]);
	
	for(int i=1; i<=n; ++i) pos[p[i]] = i;
	
	static int res[MAXN];
	memset(res, 0, (n+1)<<2);
	for(int i=1; i<=n; ++i) if(b[i] != i)
	{
		if(pos[b[i]] > pos[i])
		{
			printf("-1\n");
			return;
		}
		res[i] = pos[i] - pos[b[i]];
	}
	
	for(int i=1; i<=n; ++i) printf("%d ",res[i]);
	printf("\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}