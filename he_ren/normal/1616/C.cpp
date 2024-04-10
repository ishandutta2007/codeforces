#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 70 + 5;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i]);
	
	int ans = n - 1;
	for(int i=1; i<=n; ++i)
		for(int j=i+1; j<=n; ++j)
		{
			int cur = 0;
			for(int k=1; k<=n; ++k) if(k != i && k != j)
			{
				if((a[i] - a[k]) * (j-k) != (a[j] - a[k]) * (i-k))
					++cur;
			}
			ans = min(ans, cur);
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