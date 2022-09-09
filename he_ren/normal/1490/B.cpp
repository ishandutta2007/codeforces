#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int n;
	scanf("%d",&n);
	vector<int> cnt(5);
	for(int i=1; i<=n; ++i)
	{
		int x;
		scanf("%d",&x);
		++cnt[x%3];
	}
	
	int m = n / 3, ans = 0;
	for(int i=0; i<3; ++i)
		if(cnt[i] > m)
			ans += cnt[i] - m, cnt[(i+1)%3] += cnt[i] - m, cnt[i] = m;
	printf("%d\n",ans + cnt[0] - m);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}