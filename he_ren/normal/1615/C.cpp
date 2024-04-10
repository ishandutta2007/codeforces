#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int inf = 0x3f3f3f3f;

void solve(void)
{
	int n;
	string a,b;
	cin >> n >> a >> b;
	
	int ans = inf;
	for(int k=0; k<=1; ++k)
	{
		int res = 0;
		int cnt[2] = {0,0};
		for(int i=0; i<n; ++i)
		{
			if(a[i] != b[i])
			{
				++res;
				++cnt[a[i] - '0'];
			}
		}
		
		if(res % 2 == k && cnt[1] <= cnt[0] + 1 && cnt[0] <= cnt[1])
		{
			ans = min(ans, res);
		}
		
		for(int i=0; i<n; ++i)
			b[i] = '0' + '1' - b[i];
	}
	printf("%d\n",ans == inf? -1: ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}