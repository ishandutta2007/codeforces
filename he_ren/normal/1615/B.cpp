#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

int a[19][MAXN];

void solve(void)
{
	int l,r;
	scanf("%d%d",&l,&r);
	
	int ans = r-l+1;
	for(int i=0; i<=18; ++i)
	{
		int cnt = a[i][r] - a[i][l-1];
		ans = min(ans, r-l+1 - cnt);
	}
	printf("%d\n",ans);
}

int main(void)
{
	for(int i=0; i<19; ++i)
		for(int j=1; j<MAXN; ++j)
			a[i][j] = a[i][j-1] + ((j>>i)&1);
	
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}