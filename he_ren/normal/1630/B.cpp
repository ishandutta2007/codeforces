#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

int a[MAXN];

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	vector<int> cnt(n+1);
	for(int i=1; i<=n; ++i) ++cnt[a[i]];
	
	array<int,3> ans = {n+1, -1, -1};
	int cur = 0;
	for(int i=1,j=1; i<=n; ++i)
	{
		while(j<=n && 2 * cur - n < d) cur += cnt[j++];
		if(2 * cur - n < d) break;
		ans = min(ans, array<int,3>{j-i, i, j-1});
		cur -= cnt[i];
	}
	
	static int s[MAXN];
	for(int i=1; i<=n; ++i)
		s[i] = s[i-1] + (ans[1] <= a[i] && a[i] <= ans[2]? 1: -1);
	
	vector<int> pos;
	for(int i=n, j=s[n]; i>=1 && (int)pos.size()<d; --i)
		if(s[i] <= j) pos.push_back(i), j = s[i]-1;
	pos.push_back(0);
	reverse(pos.begin(), pos.end());
	
	printf("%d %d\n",ans[1],ans[2]);
	for(int i=1; i<=d; ++i)
		printf("%d %d\n",pos[i-1]+1,pos[i]);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}