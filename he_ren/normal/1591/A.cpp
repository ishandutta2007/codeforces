#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e2 + 5;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int ans = 1;
	for(int i=1; i<=n; ++i)
	{
		ans += a[i];
		if(i > 1 && a[i] == a[i-1])
		{
			if(a[i] == 0)
			{
				ans = -1;
				break;
			}
			else ans += 4;
		}
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