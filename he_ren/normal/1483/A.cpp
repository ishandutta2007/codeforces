#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int MAXM = 1e5 + 5;

int cnt[MAXN];
vector<int> a[MAXM];

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i)
	{
		int k;
		scanf("%d",&k);
		a[i].resize(k);
		for(int j=0; j<k; ++j) scanf("%d",&a[i][j]);
	}
	
	int mx = (m+1) >> 1;
	
	memset(cnt,0,(n+1)<<2);
	for(int i=1; i<=m; ++i) if(a[i].size() == 1)
		if(++cnt[a[i][0]] > mx){ printf("NO\n"); return;}
	printf("YES\n");
	for(int i=1; i<=m; ++i)
	{
		if(a[i].size() == 1){ printf("%d ",a[i][0]); continue;}
		int res = cnt[a[i][0]] == mx? a[i][1]: a[i][0];
		++cnt[res];
		printf("%d ",res);
	}
	printf("\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}